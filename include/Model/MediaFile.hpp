#ifndef MEDIAFILE_HPP
#define MEDIAFILE_HPP
#include "Metadata.hpp"
/*

    We only need get function to use in View frame

*/
class MediaFile{
    private:
        string filePath;
        string fileName;
        int duration;
        int fileSize;
        Metadata metadata;
    public:
        MediaFile(string filePath, string fileName, int duration, int fileSize, Metadata metadata){
            this->filePath = filePath;
            this->fileName = fileName;
            this->duration = duration;
            this-> fileSize = fileSize;
            this->metadata = metadata;
        }
        string getFileName(){
            return this->fileName;
        }
        string getFilePath(){
            return filePath;
        }
        int getFileSize(){
            return fileSize;
        }
        Metadata getMetadata(){
            return metadata;
        }
        int getDuration(){
            return this->duration;
        }
};
#endif