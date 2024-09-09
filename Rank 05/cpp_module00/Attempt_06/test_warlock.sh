#!/bin/bash

# Color codes for output formatting
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Function to compile and run tests
function test_compile_run {
  g++ -Wall -Werror -Wextra -std=c++98 Warlock.cpp -o warlock_test
  if [ $? -eq 0 ]; then
    echo -e "${GREEN}Compilation successful! Running the test...${NC}"
    ./warlock_test
  else
    echo -e "${RED}Compilation failed!${NC}"
  fi
}

# Test cases where compilation is expected to fail
echo "=== Test: Compilation should fail (no default constructor) ==="
g++ -Wall -Werror -Wextra -std=c++98 -x c++ -o warlock_fail.o - <<EOF
#include "Warlock.hpp"
int main() {
    Warlock bob; // Should fail, no default constructor
    return 0;
}
EOF
if [ $? -ne 0 ]; then
    echo -e "${GREEN}Test passed: Compilation failed as expected (no default constructor)${NC}"
else
    echo -e "${RED}Test failed: Compilation succeeded unexpectedly (no default constructor)${NC}"
fi

echo "=== Test: Compilation should fail (copy constructor) ==="
g++ -Wall -Werror -Wextra -std=c++98 -x c++ -o warlock_fail.o - <<EOF
#include "Warlock.hpp"
int main() {
    Warlock jim("Jim", "the nauseating");
    Warlock jack(jim); // Should fail, no copy constructor allowed
    return 0;
}
EOF
if [ $? -ne 0 ]; then
    echo -e "${GREEN}Test passed: Compilation failed as expected (no copy constructor)${NC}"
else
    echo -e "${RED}Test failed: Compilation succeeded unexpectedly (copy constructor)${NC}"
fi

echo "=== Test: Compilation should fail (assignment operator) ==="
g++ -Wall -Werror -Wextra -std=c++98 -x c++ -o warlock_fail.o - <<EOF
#include "Warlock.hpp"
int main() {
    Warlock bob("Bob", "the magnificent");
    Warlock jim("Jim", "the nauseating");
    bob = jim; // Should fail, no assignment operator allowed
    return 0;
}
EOF
if [ $? -ne 0 ]; then
    echo -e "${GREEN}Test passed: Compilation failed as expected (no assignment operator)${NC}"
else
    echo -e "${RED}Test failed: Compilation succeeded unexpectedly (assignment operator)${NC}"
fi

# Test case where compilation is expected to succeed
echo "=== Test: Compilation should succeed and output correct results ==="
g++ -Wall -Werror -Wextra -std=c++98 -x c++ -o warlock_success Warlock.cpp - <<EOF
#include "Warlock.hpp"
int main() {
    Warlock const richard("Richard", "Mistress of Magma");
    richard.introduce();
    std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

    Warlock* jack = new Warlock("Jack", "the Long");
    jack->introduce();
    jack->setTitle("the Mighty");
    jack->introduce();

    delete jack;

    return 0;
}
EOF
if [ $? -eq 0 ]; then
    echo -e "${GREEN}Test passed: Compilation succeeded as expected${NC}"
    ./warlock_success | cat -e
else
    echo -e "${RED}Test failed: Compilation failed unexpectedly${NC}"
fi

# Cleanup generated files
rm -f warlock_test warlock_success warlock_fail.o
