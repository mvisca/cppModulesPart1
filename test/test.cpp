#include <iostream>
#include <string>

//void	transformer(std::string uni) // por copia
//void	transformer(std::string* uni)
void transformer(std::string*& uni)
{
	if (uni== NULL)
		uni = new std::string("It was empty");
	else
		*uni = "This has hanged";
}

int	main(void)
{
	std::string *uni = NULL;

	transformer(uni);

	std::cout << *uni;
	delete uni;
	uni = NULL;

	return (0);	
}
