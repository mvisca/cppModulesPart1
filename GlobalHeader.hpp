#ifndef GLOBAL_HEAD_HPP
# define GLOBAL_HEAD_HPP

# include <iostream>
# include <cctype>
# include <string>
# include "Contact.hpp"
# include "PhoneBook.hpp"

std::string toUppercase(std::string str);

void	    displayTitle(void);
std::string	displayMenuGetValue(bool isEsp);
void        inputContact(PhoneBook& phoneBook, const bool& isEsp);

#endif