#include <algorithm>
#include <boost/regex.hpp>
#include "HeaderP.h"
#include "SourceP.cpp"

int main(int argc, char **argv) 
{
  std::string path_to_ftp;
  if (argc < 2) 
  {
    path_to_ftp = std::string(argv[1]);
  } 
  else
  {
    path_to_ftp = "../";
  }
}