//
// Created by Pawel Kutyla on 19/01/2025.
//

#ifndef ALGORITHMS_DATASTRUCTURES_TURING_H
#define ALGORITHMS_DATASTRUCTURES_TURING_H
#include <tuple>
#include <string>
#include <deque>
#include <unordered_map>
class Turing {
private:
  std::string currentState;
  std::deque<char> tape;
  int currentPosition;
  std::unordered_map<std::string, std::tuple<char, char, std::string>> instructions;
public:
  std::string getCurrentState() const;
  std::string getCurrentSymbol() const;
  int getCurrentPosition() const;
  std::deque<char> getTape() const;
  void setInstructions(std::unordered_map<std::string, std::tuple<char, char, std::string>> newInstructions);
  void run();
  Turing(std::deque<char> inputTape): currentState("init"),tape(inputTape), currentPosition(0){
    tape.push_back('_');
  }
  void setTape(const std::deque<char>& inputTape);

};

#endif // ALGORITHMS_DATASTRUCTURES_TURING_H
