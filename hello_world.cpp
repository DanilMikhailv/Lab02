#include <iostream>
#include <string>

// Main function that greets the user
int
main()
{
  std::string name; // Variable to store user's name

  std::cin >> name; // Prompt user for input

  // Output greeting message
  std::cout << "Hello World from " << name << std::endl;

  return 0;
}
