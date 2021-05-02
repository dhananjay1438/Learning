#include <chrono>
#include <iostream>

int main(void) {

  auto t1 = std::chrono::system_clock::now();

  int i = 0;
  while (true) {
    std::cout << i << " ";
    i++;
    if (std::chrono::system_clock::now() - t1 > std::chrono::seconds(5))
      break;
  }

  return 0;
}
