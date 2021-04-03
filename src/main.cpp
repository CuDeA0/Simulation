#include "iostream"
#include "include/cgen.hpp"
#include "include/exceptions.hpp"
#include <exception>

int main(){
  std::cout << "Testing the cgen library\n";
  std::cout << version() << "\n";
  std::string line;
  try
    {
      FileLine obj("/home/david/gaia/Programming/C++/Generators/README.md");
      while(obj.get())
        {
          std::cout << obj.read()  << "\n";
        }
    }
  catch(std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
}
