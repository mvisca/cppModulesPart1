#include "Contact.hpp"

// Default Constructor
Contact::Contact() {

	_firstName =		"noFirstName";
	_lastName =			"noLastName";
	_nickname =			"noNickname";
	_phoneNumber =		"noPhoneNumber";
	_darkestSecret =	"noDarkestSecret";

}

// Custom Constructor
Contact::Contact(
	std::string firstName,
	std::string lastName,
	std::string nickname,
	std::string phoneNumber,
	std::string darkestSecret) : 
	_firstName(firstName),
	_lastName(lastName),
	_nickname(nickname),
	_phoneNumber(phoneNumber),
	_darkestSecret(darkestSecret) {

	std::cout << "Contact created" << std::endl;

}

// Default Destructoer
Contact::~Contact() { 

	std::cout << "\nContact destroyed" << std::endl;

}

// Getters
std::string Contact::getFirstName() const {

	return _firstName;

}

std::string Contact::getLastName() const {

	return _lastName;

}

std::string Contact::getNickname() const {

	return _nickname;

}

std::string Contact::getPhoneNumber() const {

	return _phoneNumber;

}

std::string Contact::getDarkestSecret() const {

	return _darkestSecret;

}

// Setters
void Contact::setFirstName(const std::string &firstName) {

	_firstName = firstName;

}

void Contact::setLastName(const std::string &lastName) {

	_lastName = lastName;

}

void Contact::setNickname(const std::string &nickname) {

	_nickname = nickname;

}

void Contact::setPhoneNumber(const std::string &phoneNumber) {

	_phoneNumber = phoneNumber;

}

void Contact::setSecret(const std::string &darkestSecret) {

	_darkestSecret = darkestSecret;

}