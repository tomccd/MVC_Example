#include "../header/MVC_Manage_Folder.hpp"

/*Model*/
std::vector<std::string *> Manage_Folder_Model::getFiles(std::string _path){
    if(fs::is_directory(_path)){
        if(!fs::is_empty(_path)){
            vct_path.clear();
            for(auto &file : fs::directory_iterator(_path)){
                vct_path.push_back(new std::string(file.path()));
            }
            return vct_path;
        }
        throw std::invalid_argument("This path is empty");
    }
    throw std::invalid_argument("Directory is invalid");
    return {};
}

/*View*/
void Manage_Folder_View::displayFiles(std::vector<std::string *> vct_path) const{
    if(vct_path.size()!=0){
        for(auto path:vct_path){
            std::cout << *path << std::endl;
        }
    }
    else{
        std::cout << "Can't show\n";
    }
}

/*Controller*/
void Manage_Folder_Controller::setPath(std::string _path){
    path = _path;
}

void Manage_Folder_Controller::updateView() const{
    view->displayFiles(model->getFiles(path));
}
