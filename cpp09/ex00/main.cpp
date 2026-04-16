#include "BitcoinExchange.hpp"

std::vector<std::string> get_params(std::string data)
{
    std::vector<std::string> tokens;
    std::stringstream ss(data);
    std::string token;
    
    while (getline(ss, token, '|'))
    {
        size_t first = token.find_first_not_of(" \t\n");
        size_t last = token.find_last_not_of(" \t\r\n");
        if (first != std::string::npos)
            token = token.substr(first, last - first + 1);
        tokens.push_back(token);
    }
    return tokens;
}
void parse_file(std::string file)
{
    std::string data;
    std::ifstream in_f(file.c_str());
    std::multimap<std::string, std::string> all_data;
    if (!in_f)
        throw std::runtime_error("Error: could not open file");
    while (getline(in_f, data))
    {
        std::vector<std::string> tokens = get_params(data);
        if (tokens.size() < 2)
            tokens.push_back("");
        if (tokens.size() > 2)
            throw std::runtime_error("the file must be like [date | value]");
        all_data.insert(std::make_pair(tokens[0], tokens[1])); 
    }
    
    for (std::map<std::string, std::string>::iterator it = all_data.begin(); it != all_data.end(); it++)
    {
        std::cout << it->first << "  " << it->second << std::endl;
    }
    

}
int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }
    std::string filename = av[1];
    try
    {
        parse_file(filename);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}