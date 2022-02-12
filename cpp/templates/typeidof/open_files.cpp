#include "open_files.h"

std::mutex Files::mutex_;
Files* Files::files_ = nullptr;

Files :: file_was_not_opened
      :: file_was_not_opened( QString name_of_file, QString msg="" )
{
    this->name_of_file_ = name_of_file;
    this->msg_ = msg;
}

void Files :: file_was_not_opened
           :: what()
{
    qDebug() << "file "
             << name_of_file_
             << " was not opened "
             << msg_;
}

void Files::closeFiles()
{
    file_out_function.closeFile();
    file_in_function .closeFile();
}

Files *Files::getInstance()
{
    std::lock_guard< std::mutex > lock( mutex_ );
    if( files_ == nullptr )
        return files_ = new Files;
    else
        return files_;
}

std::fstream& Files::getFstream_OutFunction()
{
    File& file = getFile_OutFunction();
    return file.file;
}

std::fstream& Files::getFstream_InFunction()
{
    File& file = getFile_InFunction();
    return file.file;
}

File& Files::getFile_OutFunction()
{
    Files* files = getInstance();
    return files->file_out_function;
}

File& Files::getFile_InFunction()
{
    Files* files = getInstance();
    return files->file_in_function;
}


std::fstream File::openFile()
{
    std::fstream file( path_to_file.toStdString(),   std::ofstream::out
                                                   | std::ofstream::trunc );

    if( !file.is_open() )
        throw Files::file_was_not_opened( path_to_file );
    return file;
}

void File::closeFile()
{
    file.close();
}
