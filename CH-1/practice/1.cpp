#include <iostream>
int main()
{
	const std::string exclam="!";
	const std::string message = "Hello" + ", world" + exclam;

	const std::string hello = "Hello";
	const std::string message2 = hello + ", world" + "!";
	return 0;
}
