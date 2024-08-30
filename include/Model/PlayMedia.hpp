#ifndef PLAYMEDIA_HPP
#define PLAYMEDIA_HPP
#include "Playlist.hpp"
/*
    ------------------------------------------------------------------------------------

    At the fisrt time, we will use setCurrentFile to save file is chosen to run

    ------------------------------------------------------------------------------------

    To switch from current file to next file
        Step 1: nextMediaFile()--> set current = next file
        Step 2: getCurrentFile() --> now we have next file and get filePath of next file
        => with this path, we will run 

    ------------------------------------------------------------------------------------

    ------------------------------------------------------------------------------------
*/
class PlayMedia{
    private:
        Playlist playMedia;// all play list are created
        MediaFile* currentFile;
        int volume;
        string state; // pause or play
    public:
        void setState(string state){
            this->state = state;
        }
        void addPlaylist(Playlist playlist){
            this->playMedia = playlist;
        }
        void setCurrentFile(MediaFile* currentFile){
            this->currentFile = currentFile;
        }
        MediaFile* getCurrentFile(){
            return this-> currentFile;
        }
        void setVolume(int volume){
            this->volume = volume;
        }
        int getVolume(){
            return volume;
        }
        void nextMediaFile(){
            setCurrentFile(playMedia.nextMediaFile(this->currentFile));
        }
        void previousMediaFile(){
            setCurrentFile(playMedia.previousMediaFile(this->currentFile));
        }
};

#endif