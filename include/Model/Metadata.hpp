#ifndef METADATA_HPP
#define METADATA_HPP
#include <map>
#include <iostream>
using namespace std;
class Metadata{
    private:
        map<string, string> metadata;
    public:
        void showMetadata(){
            auto it = metadata.begin();
            while(it!= metadata.end()){
                cout<<(*it).first<<": "<<(*it).second<<endl;
                it++;
            }
        }
        void addNewKey(string key, string value){
            this->metadata.insert(make_pair(key, value));
        }
        void changeValue(string key, string value){
            auto it = metadata.begin();
            while(it!= metadata.end()){
                if((*it).first==key){
                    (*it).second==value;
                    cout<<"Change value of "<<(*it).first<<" from "<<(*it).second<<" to "<<value<<endl;
                    break;
                }
                it++;
            }            
        }
};

#endif