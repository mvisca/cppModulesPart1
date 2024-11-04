#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>

class Contact {

	private:
	
		// Members
		std::string	_firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;

	public:

		// Constructors
		Contact();
		Contact(
		std::string	firstName,
		std::string	lastName,
		std::string	nickname,
		std::string	phoneNumber,
		std::string	darkestSecret);

		// Destructors
		~Contact();

		// Getters
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
	
		// Setters
		void		setFirstName(const std::string& firstName);
		void		setLastName(const std::string& lastName);
		void		setNickname(const std::string& nickname);
		void		setPhoneNumber(const std::string& phoneNumber);
		void		setSecret(const std::string& darkestSecret);
};

#endif