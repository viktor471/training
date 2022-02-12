
class Sentence:
    sentence: str
    
    def __init__(self, sentence: str):
        self.sentence = sentence
        self.sentence_list = sentence.split(" ")
        self.current = 0

    def __next__(self):
        if self.current < len(self.sentence_list):
            current = self.current
            self.current += 1
            return self.sentence_list[current]
        else:
            raise StopIteration

    
    def __iter__(self):
        return self


sentence = "hello my friend I glad to see you"

for word in Sentence(sentence):
    print(word)



def sentence_generator(sentence: str):
    sentence_list = sentence.split(" ")

    for word in sentence_list:
        yield word

gen = sentence_generator(sentence)

print("\ngenerator:\n")

for word in gen:
    print(word)

