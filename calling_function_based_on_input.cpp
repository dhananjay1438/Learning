#include <iostream>
#include <map>

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
inline void print_usage() { std::cout << "Usage ./a.out a [+|-|/|%] b"; }
inline int add(int a, int b) { return a + b; }
inline int sub(int a, int b) { return a - b; }
inline int divide(int a, int b) { return a / b; }
inline int mod(int a, int b) { return a % b; }

int main(int argc, char *argv[]) {
  try {
    if (argc != 4) {
      throw no_proper_usage();
    }
    typedef int (*Handler)(int, int);

    Handler functions[]{add, sub, divide, mod};

    std::map<char, int> operators;
    operators['+'] = 0;
    operators['-'] = 1;
    operators['/'] = 2;
    operators['%'] = 3;

    int n1 = std::stoi(argv[1]);
    int n2 = std::stoi(argv[3]);
    char op = argv[2][0];

    auto it = operators.find(op);

    if (n2 == 0 && it->second == '/') {
      throw divide_by_zero();
    }

    if (it == operators.end()) {
      throw no_such_operator();
    }
    std::cout << functions[it->second](n1, n2);

  } catch (no_such_operator &obj) {

    std::cout << obj.what() << std::endl;
    print_usage();

  } catch (no_proper_usage &obj) {

    std::cout << obj.what() << std::endl;
    print_usage();

  } catch (std::invalid_argument &obj) {

    std::cout << "Please enter integers only";
    print_usage();

  } catch (divide_by_zero &obj) {

    std::cout << obj.what();
    print_usage();

  } catch (...) {

    std::cout << "Something happend!";
    print_usage();
  }

  return 0;
}
