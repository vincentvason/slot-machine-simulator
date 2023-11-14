#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <ctime>

// Symbol
// Symbol [S]even, [B]ell, [3]Bar, [2]Bar, [1]Bar, [C]herry, [F]ree
std::vector<char> r1{'S','S','S','S','S', 'B','B','B','B','3', '3','3','2','2','2', '1','1','1','C','C', 'C','C','C','F'};
std::vector<char> r2{'S','S','S','B','B', 'B','3','3','3','2', '2','2','2','1','1', '1','1','1','C','C', 'C','C','C','C'};
std::vector<char> r3{'S','B','B','3','3', '3','3','2','2','2', '2','1','1','1','1', '1','C','C','C','C', 'C','C','C','C'};

float simulation();

int main()
{
    float rtp;
    float average_rtp;

    for(int i = 0; i < 1000; i++)
    {
        rtp = simulation();
        std::cout << "RTP @ " << i << " :" << rtp << std::endl;
        
        average_rtp = ((average_rtp*i) + rtp)/(i+1);
    }

    std::cout << "Average RTP :" << average_rtp << std::endl;
    return 0;
}

float simulation()
{
    time_t timer;
    int simulation_count = 1000000;

    int spins = 0;
    float credits_wins = 0;
    int free_spin_played = 0;

    std::string symbol[10] = {"Free Game", "Seven", "Bell", "3-Bar", "2-Bar", "1-Bar", "3 Cheery", "2 Cheery", "Any Bar", "1 Cheery"};
    int win[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(r1), std::end(r1), rng);
    std::shuffle(std::begin(r2), std::end(r2), rng);
    std::shuffle(std::begin(r3), std::end(r3), rng);

    int r1i, r2i, r3i;
    srand(time(&timer));   
    for(int i = 0; i < simulation_count + free_spin_played; i++)
    {
        r1i = r1[rand() % 24];
        r2i = r2[rand() % 24];
        r3i = r3[rand() % 24];

        if(r1i == 'F')
        {
            free_spin_played += 5;
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
            credits_wins += 60.0/3.0;
            ++win[3];
        }
        else if(r1i == '2' && r2i == '2' && r3i == '2')
        {
            credits_wins += 45.0/3.0;
            ++win[4];
        }
        else if(r1i == '1' && r2i == '1' && r3i == '1')
        {
            credits_wins += 30.0/3.0;
            ++win[5];
        }
        else if(r1i == 'C' && r2i == 'C' && r3i == 'C')
        {
            credits_wins += 6.0/3.0;
            ++win[6];
        }
        else if(r1i == 'C' && r2i == 'C')
        {
            credits_wins += 3.0/3.0;
            ++win[7];
        }
        else if(isdigit(r1i) && isdigit(r2i) && isdigit(r3i))
        {
            credits_wins += 1.0/3.0;
            ++win[8];
        }
        else if(r1i == 'C')
        {
            credits_wins += 1.0/3.0;
            ++win[9];
        }

        ++spins;
    }

    return credits_wins/(spins - free_spin_played);
}
