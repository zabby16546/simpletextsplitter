
#include <fstream>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <sstream>

int MAX_CHARACTERS_INPUT = 30000; // max number of characters allowed in buffer
int SEPERATE = 200; // amount of characters to put in each file

std::string readTo(const char*, int, int);
std::string readTo(std::string&, int, int);


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
    int numfiles; // how many files will be split
    ifs.seekg (0, ifs.beg); // set the pointer of ifs back to the start

    if(filelen%200 != 0){ // calculates the number of files that will be split
      numfiles = (filelen/SEPERATE)+1;
    }else{
      numfiles = (filelen/SEPERATE);
    }

    if(filelen <= MAX_CHARACTERS_INPUT){
      char* buffer = new char[filelen]; // make a buffer using dynamic memory
      std::cout << "Reading file\n"; // update the user as-to what is happening
      ifs.read(buffer, filelen); // read the file into the buffer

      std::ofstream ofs; // open a out file stream
      std::cout << "Seperating into " << numfiles << " files\n";

      std::string filename;

      for(int i = 0; i < numfiles; ++i){
        int begin = (i*SEPERATE);

        filename = "out";
        filename+='A'+i; // naming mechanism for the output files

        std::cout << "Writing " << filename << "..." << std::endl;
        ofs.open(filename.c_str()); // open the file with the filename
        ofs << readTo(buffer, begin, SEPERATE); // reads each segment
        ofs.close(); // closes the file so the next one can be opened
      }

      delete[] buffer; // free the memory from the read file
    }else{ // the file is too big, output a message saying so
      std::cout << "Input exceeds limit\n";
      std::cout << "MAX: " << MAX_CHARACTERS_INPUT << std::endl;
      std::cout << "GIVEN: " << filelen << std::endl;
    }
  }else{ // if there was a problem opening file, output error message
    std::cout << "Error opening file\n"; // if there is any problem opening
  }
  ifs.close(); // close the file!

  std::cout << "Finished.\n";
}

std::string readTo(const char* in, int start, int size){
  std::string result;
  for(int i=start; i < start+size; ++i){
    if(in[i] != '\0'){
      result+=in[i];
    }else{
      break;
    }
  }
  return result;
}

std::string readTo(std::string& in, int start, int size){
  std::string result;
  for(int i=start; i < start+size; ++i){
    if(i < int(in.length())){
      result+=in[i];
    }
  }
  return result;
}
