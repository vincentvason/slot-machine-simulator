#include <iostream>
#include <map>
#include <vector>
#include <string>

// Symbol
// Symbol [S]even, [B]ell, [3]Bar, [2]Bar, [1]Bar, [C]herry, [F]ree
std::vector<char> r1{'S','S','S','B','B', 'B','B','3','3','3', '2','2','2','1','1', '1','1','C','C','C', 'C','F','F','F'};
std::vector<char> r2{'S','S','S','B','B', 'B','3','3','3','2', '2','2','1','1','1', '1','1','C','C','C', 'C','F','F','F'};
std::vector<char> r3{'S','S','B','B','B', '3','3','3','2','2', '2','2','1','1','1', '1','C','C','C','C', 'C','F','F','F'};

int main()
{
    int spins = 0;
    float credits_wins = 0;
    int free_spin_wins = 0;

    std::string symbol[10] = {"Free Game", "Seven", "Bell", "3-Bar", "2-Bar", "1-Bar", "3 Cheery", "Any Bar", "2 Cheery", "1 Cheery"};
    int win[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


    /* Calculate Non-Free Games RTP */
    for (char r1i : r1)
        for (char r2i : r2)
            for(char r3i : r3)
                {
                    if(r1i == 'F' && r2i == 'F' && r3i == 'F')
                    {
                        ++free_spin_wins;
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
                }

    for(int i = 0; i < 10; i++)
    {
        std::cout << symbol[i] << " Triggered: \t" << static_cast<float>(win[i])/spins << std::endl;
    }    

    std::cout << "Spins /wo Free Game: \t" << spins - free_spin_wins << std::endl;
    std::cout << "Credits Win: \t" << credits_wins << std::endl;
    std::cout << "RTP /wo Free Game: \t" << credits_wins/(spins - free_spin_wins) << std::endl;

    float rtp_no_free_spin = credits_wins/(spins - free_spin_wins);
    float free_spin_probability = free_spin_wins/spins;

    /* Calculate Free Games RTP */
    float retrigger_chance = 1;

    for( int i = 1; i <= 10; i++)
    {
        retrigger_chance *= 1 + free_spin_probability;
    }

    float rtp_free_spin = (rtp_no_free_spin * 8 * retrigger_chance);
    std::cout << "Free Game Play: \t" << free_spin_wins << std::endl;
    std::cout << "RTP on Free Game: \t" << rtp_free_spin << std::endl;

    /* Total RTP*/
    float rtp = ((rtp_no_free_spin * (spins - free_spin_wins)) + (rtp_free_spin * (free_spin_wins)))/spins;
    std::cout << "Summarised RTP: \t" << rtp << std::endl;

    return 0;
}