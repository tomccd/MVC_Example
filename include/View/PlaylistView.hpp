#ifndef PLAYLISTVIEW_HPP
#define PLAYLISTVIEW_HPP
#include "../Model/Playlist.hpp"
class PlaylistView{
    public:
        void displayPlaylist(Playlist * playlist){
            int count = 1;
            vector<MediaFile*> mediaList = playlist->getPlaylist();
            cout<<"List media file in this playlist\n";
            auto it = mediaList.begin();
            while(it!= mediaList.end()){
                cout<<count++<<". "<<(*it)->getFileName()<<endl;
                it++;
            }
        }
};
#endif