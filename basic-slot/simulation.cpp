#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <random>

// Symbol
// Symbol [S]even, [B]ell, [3]Bar, [2]Bar, [1]Bar, [C]herry, [F]ree
std::vector<char> r1{'S','S','S','B','B', 'B','B','3','3','3', '2','2','2','1','1', '1','1','C','C','C', 'C','F','F','F'};
std::vector<char> r2{'S','S','S','B','B', 'B','3','3','3','2', '2','2','1','1','1', '1','1','C','C','C', 'C','F','F','F'};
std::vector<char> r3{'S','S','B','B','B', '3','3','3','2','2', '2','2','1','1','1', '1','C','C','C','C', 'C','F','F','F'};

int main()
{
    int simulation_count = 10000000;

    int spins = 0;
    float credits_wins = 0;
    int free_spin_played = 0;

    std::string symbol[10] = {"Free Game", "Seven", "Bell", "3-Bar", "2-Bar", "1-Bar", "3 Cheery", "Any Bar", "2 Cheery", "1 Cheery"};
    int win[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int r1i, r2i, r3i;

    for(int i = 0; i < simulation_count + free_spin_played; i++)
    {
        r1i = r1[rand() % 24];
        r2i = r2[rand() % 24];
        r3i = r3[rand() % 24];

        if(r1i == 'F' && r2i == 'F' && r3i == 'F')
        {
            free_spin_played += 8;
            ++win[0];
        }
        else if(r1i == 'S' && r2i == 'S' && r3i == 'S')
        {
            credits_wins += 600.0/3.0;
            ++win[1];
        }
        else if(r1i == 'B' && r2i == 'B' && r3i == 'B')
        {
            credits_wins += 300.0/3.0;
            ++win[2];
        }
        else if(r1i == '3' && r2i == '3' && r3i == '3')
        {
            credits_wins += 90.0/3.0;
            ++win[3];
        }
        else if(r1i == '2' && r2i == '2' && r3i == '2')
        {
            credits_wins += 60.0/3.0;
            ++win[4];
        }
        else if(r1i == '1' && r2i == '1' && r3i == '1')
        {
            credits_wins += 45.0/3.0;
            ++win[5];
        }
        else if(r1i == 'C' && r2i == 'C' && r3i == 'C')
        {
            credits_wins += 15.0/3.0;
            ++win[6];
        }
        else if(isdigit(r1i) && isdigit(r2i) && isdigit(r3i))
        {
            credits_wins += 3.0/3.0;
            ++win[7];
        }
        else if(r1i == 'C' && r2i == 'C')
        {
            credits_wins += 3.0/3.0;
            ++win[8];
        }
        else if(r1i == 'C')
        {
            credits_wins += 1.0/3.0;
            ++win[9];
        }
        ++spins;

        if(i % (simulation_count/20) == 0){
            std::cout << (i / (simulation_count/20)) * 5 << "%" << std::endl; 
        }
    }

    std::cout << "Spins: \t" << spins - free_spin_played << std::endl;    
    std::cout << "Free Games: \t" << free_spin_played << std::endl;
    std::cout << "Credits Win: \t" << credits_wins << std::endl;
    std::cout << "RTP: \t" << credits_wins/(spins - free_spin_played) << std::endl;
     
}
