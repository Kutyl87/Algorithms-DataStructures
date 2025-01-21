#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include "Turing.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <instructions_file>" << std::endl;
    return 1;
  }
  std::ifstream inputFile(argv[1]);
  if (!inputFile.is_open()) {
    std::cerr << "Error opening file: " << argv[1] << std::endl;
    return 1;
  }
  std::vector<char> tape = {'1', '0', '1', '1'};
  Turing machine(tape);
  std::unordered_map<std::string, std::tuple<char, char, std::string>> instructions;
  std::string line;
  while (std::getline(inputFile, line)) {
    std::istringstream iss(line);
    std::string state, symbol, newState;
    char newSymbol, direction;
    if (!(iss >> state >> symbol >> newSymbol >> direction >> newState)) {
      std::cerr << "Error parsing instruction: " << line << std::endl;
      continue;
    }
    std::string key = state + "," + symbol;
    instructions[key] = std::make_tuple(newSymbol, direction, newState);
  }
  machine.setInstructions(instructions);
  machine.run();
  inputFile.close();
  return 0;
}