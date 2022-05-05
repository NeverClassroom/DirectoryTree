#define EXIT_SUCCESS 0
#define EXIT_FAILURE -1
#define HIERARCHY_NUM 2

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <dirent.h>
#include <sys/stat.h>

using std::cout; using std::cin;
using std::endl; using std::vector;
using std::string;


void DirectoryTree(string dir, string prefix, vector<string>& ignore, int hier_num = HIERARCHY_NUM) {
    string filepath;
    DIR *dp;
    struct dirent *dirp;
    struct stat filestat;

    dp = opendir(dir.c_str());
    if (dp == NULL) {
        cout << "Error " << errno << " while trying opening" << dir << endl;
        return;
    }

    while (dirp = readdir(dp)) {
        filepath = dir + "/" + dirp->d_name;
        string nameString(dirp->d_name);
        if(std::find(ignore.begin(), ignore.end(), nameString) != ignore.end() || std::find(ignore.begin(), ignore.end(), filepath) != ignore.end()) {
            continue;
        } else {
            string tmpprefix = prefix;
            tmpprefix.replace(tmpprefix.size()-3, 3, "├─");
            cout << tmpprefix << dirp->d_name << endl;
        }

        if (stat(filepath.c_str(), &filestat))
            continue;

        if (S_ISDIR(filestat.st_mode) && hier_num >= 1) {
            DirectoryTree(filepath, prefix + "   │", ignore, --hier_num);
        }
    }
    closedir(dp);
}

vector<string> IgnoreVector() {
    vector<string> ignore;
    ignore.push_back(".");
    ignore.push_back("..");
    ignore.push_back(".git");
    ignore.push_back(".gitignore");
    return ignore;
}

int main(int argc, char** argv) {
    if (!argv[1]){
        cout << "You must type a directory name as argument!" << endl;
        return EXIT_FAILURE;
    }

    string dir(argv[1]);
    vector<string> ignore = IgnoreVector();
    for (int i = 2; i < argc; ++i)
        ignore.push_back(string(argv[i]));

    cout << "." << endl;
    DirectoryTree(dir, "│", ignore);

    return EXIT_SUCCESS;
}
