//
// Created by Pawel Kutyla on 19/01/2025.
//

#ifndef ALGORITHMS_DATASTRUCTURES_TURING_H
#define ALGORITHMS_DATASTRUCTURES_TURING_H
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
class Turing {
private:
  std::string currentState;
  std::vector<char> tape;
  int currentPosition;
  std::unordered_map<std::string, std::tuple<char, char, std::string>> instructions;
public:
//  void saveSymbol(const std::string& newSymbol);
  std::string getCurrentState() const;
  std::string getCurrentSymbol() const;
  int getCurrentPosition() const;
  std::vector<char> getTape() const;
  void setInstructions(std::unordered_map<std::string, std::tuple<char, char, std::string>> newInstructions);
  void run();
  Turing(std::vector<char> inputTape): currentState("init"),tape(inputTape), currentPosition(0){
    tape.push_back('_');
  }
  void setTape(const std::vector<char>& inputTape);

};

#endif // ALGORITHMS_DATASTRUCTURES_TURING_H
