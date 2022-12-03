# ChocAn Software

# Description

This is the Chocoholics Anonymous Software created by group 8 for the Fall 2022 CS 314 - Elements of Software Engineering class.

# Installation
First, you will need to upload the provided .tar.gz file to the school server where the program was tested with file streams.

Some commands to help you transfer the file to the school server are as follows:
```
sftp [username]@linux.cs.pdx.edu
sftp> put Chocoholics-Anonymous-Software-group8.tar.gz .
```

Once you are logged into the school environment, you will need to create a directory and untar the compressed file there (to avoid polutting your current directory):
```
mkdir ChocAn-Software && tar xf Chocoholics-Anonymous-Software-group8.tar.gz -C ChocAn-Software
```

The build for this codebase is managed by CMake. To create the makefile and compile this project, simply go into the project directory and run the following commands (This must be done in the school or any linux environment with a cmake version 3.21 or newer):
```
> cmake .
> make
```

# Testing
The software comes with a sample set of data to use for testing. Chocaholics Anonymous Members, Providers, and Services are all loaded into the program automatically and are available under the `/assets` directory.

All reports are run as .txt files for testing purposes. These can be found in the `/docs` directory. 

# Authors

  Nathan Waggoner

  Kobe Norcross

  Ashton Sawyer

  Matthew Loera
