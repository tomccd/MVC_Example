#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP
#include"MediaFile.hpp"
#include<vector>
class Playlist{
    private:
        vector<MediaFile*> playlist;
        string playlistName;
    public:
        Playlist(){};
        Playlist(string playlistName, vector<MediaFile*> playlist){
            this->playlist = playlist;
            this->playlistName = playlistName;
        }
        void addMediaFile(MediaFile *file){
            this->playlist.push_back(file);
        }
        void removeMediaFile(string name){
            auto it =this->playlist.begin();
            while(it!=this->playlist.end()){
                if((*it)->getFileName()==name){
                    delete (*it);
                    it= this->playlist.erase(it);
                    cout<<"Remove "<<name<<" success\n";
                    return;
                }
                cout<<"Invalid name\n";
            }
        }
        void createPlaylist(string name, MediaFile *file){
            this->playlistName = name;
            this->addMediaFile(file);
        }
        // get media file in playlist
        vector<MediaFile*> getPlaylist(){
            return playlist;
        }
        // return next media file of file in playlist
        MediaFile* nextMediaFile(MediaFile *file){
            auto it = playlist.begin();
            while(it!= playlist.end()){
                if((*it) == file){
                    return *(++it);
                }
                it++;
            }
            return NULL;
        }
        // return previous media file of file in playlist
        MediaFile* previousMediaFile(MediaFile *file){
            auto it = playlist.begin();
            while(it!= playlist.end()){
                if((*it) == file){
                    return *(--it);
                }
                it++;
            }
            return NULL;
        }
};
#endif