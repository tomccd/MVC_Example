#ifndef MEDIAVIEW_HPP
#define MEDIAVIEW_HPP
#include "../Model/MediaFile.hpp"
class MediaView{
    public:
        // Use to display general information of a media file
        void displayMediaFile(MediaFile * file){
            cout << "Name: "<<file->getFileName()<<endl;
            cout << "Path: "<<file->getFilePath()<<endl;
            cout << "Duration: "<<file->getDuration()<<endl;
            cout << "Size: "<<file->getFileSize()<<endl;
            map<string, string> tmp = file->getMetadata();    
        }
};
#endif