//
// Created by Pawel Kutyla on 19/01/2025.
//

#include "Turing.h"
#include "iostream"
std::string Turing::getCurrentState() const {
  return currentState;
}

//std::string Turing::getCurrentSymbol() {
//  return currentSymbol;
//}

//void Turing::saveSymbol(std::string newSymbol) {
//  this->currentSymbol= newSymbol;
//}

//void Turing::setState(std::string newState) {
//  this->currentState = newState;
//}

int Turing::getCurrentPosition() const{
  return currentPosition;
}

std::vector<char> Turing::getTape() const {
  return tape;
}
void Turing::setInstructions(std::unordered_map<std::string, std::tuple<char, char, std::string>> newInstructions){
  this->instructions = newInstructions;
}
void Turing::setTape(const std::vector<char>& inputTape){
  this->tape = inputTape;
}

void Turing::run() {
  std::cout << "Initial State: " << currentState << std::endl;
  std::cout << "Tape: ";
  for (char symbol : tape) {
    std::cout << symbol;
  }
  std::cout << std::endl;
  std::cout << "Head Position: " << currentPosition << std::endl;
  while (currentState != "halt") {
    char currentSymbol = this->tape[currentPosition];
    std::string key = currentState + "," + currentSymbol;
    if (this->instructions.find(key) == this->instructions.end()) {
      std::cout << "Instruction " + key + " not found" << std::endl;
      break;
    }
    std::tuple<char, char, std::string> operationPart = this->instructions[key];
    char newSymbol = std::get<0>(operationPart);
    char newDirection = std::get<1>(operationPart);
    std::string newState = std::get<2>(operationPart);
    this->tape[currentPosition] = newSymbol;
    this->currentState = newState;
    std::cout << "After state: " << currentState << std::endl;
    std::cout << "Tape: ";
    for (char symbol : tape) {
      std::cout << symbol;
    }
    std::cout << std::endl;
    std::cout << "Head Position: " << currentPosition << std::endl;
    if (newDirection == 'L') {
      currentPosition--;
    } else if (newDirection == 'R') {
      currentPosition++;
    }
    if (currentPosition < 0) {
      currentPosition = 0;
    }
    if ((size_t)currentPosition >= tape.size()) {
      tape.push_back('_');
    }
  }
  std::cout << "Final State: " << currentState << std::endl;
  std::cout << "Tape: ";
  for (char symbol : tape) {
    std::cout << symbol;
  }
  std::cout << std::endl;
  std::cout << "Head Position: " << currentPosition << std::endl;
}
