#include "Turing.h"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <tuple>
#include <unordered_map>

TEST_CASE("Turing Machine Basic Operations - Adding 1") {
  std::string tape = "1011";
  std::vector<char> tapeVector(tape.begin(), tape.end());
  Turing machine = Turing(tapeVector);

  std::unordered_map<std::string, std::tuple<char, char, std::string>> instructions = {
      {"init,1", {'1', 'R', "init"}},
      {"init,0", {'0', 'R', "init"}},
      {"init,_", {'_', 'L', "carry"}},
      {"carry,1", {'0', 'L', "carry"}},
      {"carry,0", {'1', '*', "halt"}},
      {"carry,_", {'1', '*', "halt"}}
  };
  machine.setInstructions(instructions);

  SECTION("Correct final state and tape after processing") {
    machine.run();
    REQUIRE(machine.getCurrentState() == "halt");
    std::vector<char> tape = machine.getTape();
    std::string tapeString(tape.begin(), tape.end());
    REQUIRE(tapeString == "1100_");
    REQUIRE(machine.getCurrentPosition() == 1);
  }

  SECTION("Handle invalid instructions") {
    machine.setInstructions({{"init,1", {'1', 'R', "init"}}});
    machine.run();
    REQUIRE(machine.getCurrentState() == "init");
  }
}

TEST_CASE("Turing Machine Basic Operations - Adding 2") {
  std::string tape = "1001";
  std::vector<char> tapeVector(tape.begin(), tape.end());
  Turing machine = Turing(tapeVector);

  std::unordered_map<std::string, std::tuple<char, char, std::string>> instructions = {
      {"init,1", {'1', 'R', "init"}},
      {"init,0", {'0', 'R', "init"}},
      {"init,_", {'_', 'L', "carry"}},
      {"carry,1", {'0', 'L', "carry"}},
      {"carry,0", {'1', '*', "halt"}},
      {"carry,_", {'1', '*', "halt"}}
  };
  machine.setInstructions(instructions);

  SECTION("Correct final state and tape after processing") {
    machine.run();
    REQUIRE(machine.getCurrentState() == "halt");
    std::vector<char> tape = machine.getTape();
    std::string tapeString(tape.begin(), tape.end());
    REQUIRE(tapeString == "1010_");
    REQUIRE(machine.getCurrentPosition() == 2);
  }
}