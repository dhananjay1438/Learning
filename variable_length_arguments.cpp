#include <iostream>
#include <sstream>
#include <utility>

void second_approach() {}

template <typename T, typename... Arguments>
void second_approach(T first, Arguments... args) {

  std::cout << std::forward<T>(first) << " ";
  second_approach(std::forward<Arguments>(args)...);
}

template <typename... Arguments>
void first_approach(Arguments &&... args) { // Runs only with c++17

  std::stringstream ss;
  (ss << ... << args) << "\n";

  std::string str = ss.str();
  std::cout << str; // Prints all the arguments without space or new line
                    // (Pretty useless)
}

int main(void) {

  int n = 10;
  first_approach(10, "Hello", 20, 30, 40);
  second_approach(10, "Hello", 20, 30, 40);

  return 0;
}
