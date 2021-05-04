#include <iostream>
#include <map>
#include <vector>

class divide_by_zero : public std::exception {
public:
  virtual const char *what() const throw() {
    return "You are trying to divide number with 0";
  }
};
class no_such_operator : public std::exception {
public:
  virtual const char *what() const throw() {
    return "There is no such operator";
  }
};

class no_proper_usage : public std::exception {
public:
  virtual const char *what() const throw() {
    return "This is not how this is intented to use";
  }
};
inline void print_usage() { std::cout << "Usage ./a.out a [+|-|x|/|%] b"; }
inline int add(int a, int b) { return a + b; }
inline int mul(int a, int b) { return a * b; }
inline int sub(int a, int b) { return a - b; }
inline int divide(int a, int b) { return a / b; }
inline int mod(int a, int b) { return a % b; }

int main(int argc, char *argv[]) {
  std::vector<std::string> args(argv + 1, argv + argc);
  try {
    if (argc != 4) {
      throw no_proper_usage();
    }

    for (auto x : args) {
      std::cout << x << " ";
    }
    std::cout << "= ";
    typedef int (*Handler)(int, int);

    std::map<char, Handler> operations;
    operations.insert(std::pair<char, Handler>('+', add));
    operations.insert(std::pair<char, Handler>('-', sub));
    operations.insert(std::pair<char, Handler>('x', mul));
    operations.insert(std::pair<char, Handler>('/', divide));
    operations.insert(std::pair<char, Handler>('%', mod));

    int n1 = std::stoi(argv[1]);
    int n2 = std::stoi(argv[3]);
    char op = argv[2][0];

    if (n2 == 0 && op == '/') {
      throw divide_by_zero();
    }

    if (operations.find(op) == operations.end()) {
      throw no_such_operator();
    }
    std::cout << operations[op](n1, n2);

  } catch (no_such_operator &obj) {

    std::cout << obj.what() << std::endl;
    print_usage();

  } catch (no_proper_usage &obj) {

    std::cout << obj.what() << std::endl;
    print_usage();

  } catch (std::invalid_argument &obj) {

    std::cout << "Please enter integers only" << std::endl;
    print_usage();

  } catch (divide_by_zero &obj) {

    std::cout << obj.what() << std::endl;
    print_usage();

  } catch (...) {

    std::cout << "Something happend!" << std::endl;
    print_usage();
  }

  return 0;
}
