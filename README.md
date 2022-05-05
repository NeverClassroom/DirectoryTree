# DirectoryTree
Print the folder hierarchy of the specified directory as a tree graph (currently 2 layers).
The function is similar to the `tree` tool in the linux system.

## How to use

1. After download this project, you could enter the project folder and use command `make` to get executable file.

```
$ cd DirectoryTree
$ make
$ ls
LICENSE  Makefile  README.md  main  main.cpp
```

2. Execute the `main` program and **give it a directory name as a argument** you want to print. And then you could see the tree hierarchy of this directory.

```
$ ./main .
.
├─.gitignore
├─LICENSE
├─README.md
├─main.cpp
├─Makefile
├─main
```

## More about the program

In the `main.cpp`, you could find the definition `#define HIERARCHY_NUM 2`.
You could change this definition to meet your request for the number of directory hierarchy.
