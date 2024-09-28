#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook {

private:

	static const int	_maxContacts = 8;
	Contact 			_contacts[_maxContacts];
	int					_contactsCount;

public:

	// Default Constructor
	PhoneBook();

	// Destroyer
	~PhoneBook();

	// Getter
	int					getMaxContacts(void) const;
	int					getContactsCount(void) const;
	const Contact&		getIndexContacts(const int& optionIndex) const;

	// Setter
	void	addContact(
		std::string firstName,
		std::string lastName,
		std::string nickname,
		std::string phoneNumber,
		std::string darkestSecret);

	// Handlers
	void	incrementCount(void);
};

#endif