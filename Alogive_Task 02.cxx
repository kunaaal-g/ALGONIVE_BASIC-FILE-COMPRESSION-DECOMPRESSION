#include <iostream>
#include <fstream>
#include <string>
std::string compressRLE(const std::string& input) 
{
    std::string result;
    for (size_t i = 0; i < input.length(); i++) 
    {
        int count = 1;
        while (i + 1 < input.length() && input[i] == input[i + 1]) 
        {
            count++;
            i++;
        }
        result += input[i] + std::to_string(count);
    }
    return result;
}
std::string decompressRLE(const std::string& input) 
{
    std::string result;
    for (size_t i = 0; i < input.length(); i += 2) 
    {
        char c = input[i];
        int count = input[i + 1] - '0';
        result.append(count, c);
    }
    return result;
}
int main() 
{
    std::string data = "aaabbccccd";
    std::string compressed = compressRLE(data);
    std::string decompressed = decompressRLE(compressed);
    std::cout << "Original: " << data << "\n";
    std::cout << "Compressed: " << compressed << "\n";
    std::cout << "Decompressed: " << decompressed << "\n";
}