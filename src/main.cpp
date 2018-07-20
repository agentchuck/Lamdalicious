#include <boost/program_options.hpp>

namespace po = boost::program_options;

#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

int main(int argc, char **argv)
{
  // Declare the supported options.
  po::options_description desc("Allowed options");
  desc.add_options()
      ("help", "produce help message")
  ;

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);    

  if (vm.count("help")) {
      cout << desc << "\n";
      return 1;
  }

  return 0;
}
