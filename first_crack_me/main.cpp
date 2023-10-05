#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#include <Windows.h>

#define roll(x) x ^ 0x69

int main(void) {
  unsigned char str[] = {roll(0x68), roll(0x65), roll(0x6c), roll(0x6c),
                         roll(0x6f), roll(0x20), roll(0x74), roll(0x68),
                         roll(0x65), roll(0x72), roll(0x65), roll(0x21)};

  std::string nothing;
  std::cout << "Inject your dll now, waiting... (Please input a string)"
            << std::endl;
  std::cin >> nothing;

  std::string input;
  std::cout << "Input the key:";
  std::cin >> input;

  auto found = true;
  for (int i = 0; i < input.size(); i++) {
    auto regular_value = roll(str[i]);
    if (regular_value != input[i]) {
      found = false;
      break;
    }
  }

  if (found) {
    std::cout << "Successo!" << std::endl;
  }

  return 0;
}