#include <iostream>
int main(int ac, char **av)
{
//     (void)ac;
//     (void) av;
//     std::ofstream fs("test.txt");
//    // fs << "Buffered write" << std :: endl;   // goes to buffer
//     fs << "Buffered write\n";   // goes to buffer
//     sleep(5);                   // file might still be empty here

//     //fs.flush();                 // force flush
//     sleep(5);                   // now you can open file and see the text

//     //fs.close();
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return (1);
    }
    for (int i = 1; i < ac; i++)
    {
        int j = 0;
        while (av[i][j])
        {
            std::cout << (char)std::toupper(av[i][j]);
            j++;
        }
    }
    std::cout<< '\n';

    return (0);
}