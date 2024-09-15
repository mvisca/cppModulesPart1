#include "GlobalHeader.hpp"

int main(void) {
    std::string stra(20, 'a');
    std::string strb(5, 'b');
    std::string stras = stra.substr(0, 10);
    std::string strbs = strb.substr(0, 10);

    std::cout << stras << std::endl;
    std::cout << strbs << std::endl;

    return (0);
}