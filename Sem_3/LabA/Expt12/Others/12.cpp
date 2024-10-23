#include <iostream>
#include <cstdlib>  
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>  
#include <dirent.h> 
using namespace std;
// Function to categorize files based on extension
string getFileCategory(const string& extension) {
    map<string, string> categories;
    categories[".jpg"] = "Images";
    categories[".jpeg"] = "Images";
    categories[".png"] = "Images";
    categories[".gif"] = "Images";
    categories[".mp4"] = "Videos";
    categories[".mkv"] = "Videos";
    categories[".avi"] = "Videos";
    categories[".mp3"] = "Audio";
    categories[".wav"] = "Audio";
    categories[".flac"] = "Audio";
    categories[".pdf"] = "Documents";
    categories[".docx"] = "Documents";
    categories[".txt"] = "Documents";
    categories[".zip"] = "Archives";
    categories[".rar"] = "Archives";
    categories[".tar"] = "Archives";

    if (categories.find(extension) != categories.end()) {
        return categories[extension];
    } else {
        return "Others"; 
    }
}

string getFileExtension(const string& filename) {
    size_t dotPos = filename.find_last_of('.');
    if (dotPos == string::npos) {
        return "";  
    }
    return filename.substr(dotPos); 
}

void organizeFiles(const string& directory) {
    DIR* dir;
    struct dirent* entry;

    if ((dir = opendir(directory.c_str())) == NULL) {
        cerr << "Cannot open directory: " << directory << endl;
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        string filename = entry->d_name;

        if (filename == "." || filename == "..") continue;

        string filePath = directory + "/" + filename;
        string extension = getFileExtension(filename);
        string category = getFileCategory(extension);

        if (entry->d_type == DT_DIR) continue;

        string targetDir = directory + "/" + category;


        string mkdirCommand = "mkdir -p \"" + targetDir + "\"";
        system(mkdirCommand.c_str());

        string targetPath = targetDir + "/" + filename;
        if (rename(filePath.c_str(), targetPath.c_str()) != 0) {
            cerr << "Error moving file: " << filename << endl;
        } else {
            cout << "Moved " << filename << " to " << category << " folder." << endl;
        }
    }

    closedir(dir);
}

int main() {
    string directory;
    cout << "Enter the path of the directory to organize: ";
    cin >> directory;

    organizeFiles(directory);

    cout << "Files organized successfully!" << endl;

    return 0;
}