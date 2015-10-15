
#include <fstream>
#include <cstring>
#include <string>
#include <iostream>

int MAX_CHARACTERS_INPUT = 30000; // max number of characters allowed in buffer
int SEPERATE = 200; // amount of characters to put in each file

void readTo(const char*, int, int);

int main(int argc, char *argv[]){
  char file[256]; // hold the filename
  if(argc == 1){ // if there was no parameter for a file name, ask for one
    std::cout << "File: ";
    std::cin >> file;
  }else{ // convert the argv into a usable char array so the file can be used
    std::strcpy(&file[0], argv[1]);
  }

  std::ifstream ifs(file); // open the filestream

  if(ifs.is_open()){
    ifs.seekg (0, ifs.end); // set the pointer of ifs to the end of the file
    int filelen = ifs.tellg(); // store the position of eof() in filelen
    ifs.seekg (0, ifs.beg); // set the pointer of ifs back to the start

    if(filelen <= MAX_CHARACTERS_INPUT){
      char* buffer = new char[filelen]; // make a buffer using dynamic memory
      std::cout << "Reading file\n"; // update the user as-to what is happening
      ifs.read(buffer, filelen); // read the file into the buffer
    }else{ // the file is too big, output a message saying so
      std::cout << "Input exceeds limit\n";
      std::cout << "MAX: " << MAX_CHARACTERS_INPUT << std::endl;
      std::cout << "GIVEN: " << filelen << std::endl;
    }
  }else{
    std::cout << "Error opening file\n"; // if there is any problem opening
  }
  ifs.close(); // close the file!
}

void readTo(const char* in, int start, int size){
  for(int )
}
