#include"Headers.h"
// Function to list files in a directory
string lastFileInDirectory() {
    string directory_path = "HashLogs/";
    string file = "";
    DIR* dir = opendir(directory_path.c_str());
    if (dir == nullptr) {
        cout << "Failed to open directory." << endl;
        return file;
    }
    
    int i = 0;
    struct dirent* entry;
    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_REG) {  // Check if it's a regular file
            file = (entry->d_name);
        }
    }
    return file;
}

int main() {
    
    fstream fin("");
    

    return 0;
}
