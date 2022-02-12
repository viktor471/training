#include <iostream>
#include <functional>
#include <map>

using namespace std;

class Serializable
{
protected:
    typedef function<void(const string&)> Func;

    struct SerializerPair
    {
        Func Serializer;
        Func Deserializer;
    };

    char Add(string _key, Func _serializer, Func _deserializer)
    {
        auto& lv_Pair = m_Serializers[_key];
        lv_Pair.Serializer = _serializer;
        lv_Pair.Deserializer = _deserializer;
    }

public:
    virtual void Serialize()
    {
        for (auto& lv_Ser : m_Serializers)
            lv_Ser.second.Serializer(lv_Ser.first);
    }

    virtual void Deserialize()
    {
        for (auto& lv_Ser : m_Serializers)
            lv_Ser.second.Deserializer(lv_Ser.first);
    }

private:
    map<string, SerializerPair> m_Serializers;
};

class Test : public Serializable
{
public:
    int SomeInt = 666;
    float SomeFloat = 42.2;
    string SomeString = "Hello My Little Pony";
private:
    serialize(SomeInt);
    serialize(SomeFloat);
    serialize(SomeString);
};

struct Test_2
{
    string SomeString = "Hello My Little Pony";
    function<void()> SomeFunc = [this]()
    {
        cout << SomeString;
    };
};
class TestClass : public Serializable
{
public:
    int SomeInt = 666;

private:
    char SomeIntSer = Add
    (
        "SomeInt",
        [this](const string& _key)
        {
            ::Serialize(_key, SomeInt);
        },
        [this](const string& _key)
        {
            ::Deserialize(_key, SomeInt);
        }
    );
};
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
