#ifndef OPEN_FILES_H
#define OPEN_FILES_H
#include <QString>
#include <fstream>
#include <iostream>
#include <QDebug>
#include <mutex>

#define COMMON_PATH "/home/viktor/prg/typeidof/"
#define FILE_OUT_FUNCTION COMMON_PATH "out_function"
#define FILE_IN_FUNCTION  COMMON_PATH "in_function"

struct File {

   std::fstream file;
   QString path_to_file;
   std::fstream openFile();
   void         closeFile();

   File( QString path_to_file )
   {
       this->path_to_file = path_to_file;
       file = openFile();
   }
};

class Files
{
protected:

    static Files* files_;
    static std::mutex mutex_;

    File file_out_function;
    File file_in_function;

    Files( QString path1 = FILE_OUT_FUNCTION,
           QString path2 = FILE_IN_FUNCTION               )
        : file_out_function( path1 ), file_in_function( path2 ) {}

    void operator=( const Files ) = delete;
    Files( Files &other )         = delete;
    ~Files() { closeFiles(); }

    static File& getFile_OutFunction();
    static File& getFile_InFunction();

    void          closeFiles();
    static Files* getInstance();

public:

    static std::fstream& getFstream_OutFunction();
    static std::fstream& getFstream_InFunction();

    class file_was_not_opened
    {
        QString msg_;
        QString name_of_file_;
    public:
        file_was_not_opened( QString name_of_file, QString msg );

        void what();
    };
};

#endif // OPEN_FILES_H


