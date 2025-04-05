#include <iostream>
#include "ValidAnagram.h"

int main()
{
    ValidAnagram validAnagram;
    std::cout << validAnagram.isAnagram("racecar", "carrace") << std::endl;
    std::cout << validAnagram.isAnagram("jar", "jam") << std::endl;
    return 0;
}