#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include "Turing.h"

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <tape> <instructions_file>" << std::endl;
    return 1;
  }

  std::string tapeInput = argv[1];
  std::ifstream inputFile(argv[2]);
  if (!inputFile.is_open()) {
    std::cerr << "Error opening file: " << argv[2] << std::endl;
    return 1;
  }

  std::deque<char> tape(tapeInput.begin(), tapeInput.end());
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