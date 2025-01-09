# include <iostream>
# include <string>

int    main() {

    const std::string R = "\033[31m";
    const std::string G = "\033[32m";
    const std::string B = "\033[34m";
    const std::string W = "\033[0m";

    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << R << "String address: " << W << &str << std::endl;
    std::cout << R << "Pointer address: " << W << stringPTR << std::endl;
    std::cout << R << "Reference address: " << W << &stringREF << std::endl;

    return 0;
}