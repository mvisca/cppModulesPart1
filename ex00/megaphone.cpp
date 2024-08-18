#include <iostream>

void	extra(std::string line);

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		std::string line;
		for (int i = 1; i < ac; i++)
		{
			std::string s = av[i];
			for (size_t j = 0; j < s.length(); j++)
			{
				s[j] = std::toupper(s[j]);
			}
			line = line + s;
		}
		std::cout << line << std::endl;
	}
	else
	{
		std::string line = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		extra(line);
	}
	return (0);
}

void	extra(std::string line)
{
	std::cout << line << std::endl;
}
