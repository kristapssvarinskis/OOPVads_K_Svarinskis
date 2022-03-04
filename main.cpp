#include <iostream>
#include <random>

int Randomrng(int a,int b);
struct Player{
    int power, defence, attack;
    char team;
    Player(){
        power = Randomrng(0,100);
        defence = Randomrng(0,100);
        attack = Randomrng(0,100);
    }
};

bool Compare(Player* teamA, Player* teamB);

int main()
{
    //team A
    Player playerA[4] ;
    for ( int i=0; i < 4; i++)
        playerA[i].team = 'A';

    //team B
    Player playerB[4];
    for ( int i=0; i < 4; i++)
        playerB[i].team = 'B';

    bool winner = Compare(playerA, playerB);
    std::string teamAwon = "Team A is the winner";
    std::string teamBwon = "Team B is the winner";
    std::cout <<  (winner? teamAwon : teamBwon) << std::endl;
    return 0;
}

int Randomrng(int a, int b){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(a,b);

    return dist(rng);
}
//ja teamA ir stiprāka, tad atdos(return) true
bool Compare(Player* teamA, Player* teamB)
{
    int teamA_Power;
    for (int j = 0; j < 4; j++ )
    {
        teamA_Power += teamA[j].power;
        teamA_Power += teamA[j].attack;
        teamA_Power += teamA[j].defence;
    }

    int teamB_Power;
    for (int j = 0; j < 4; j++)
    {
        teamB_Power += teamB[j].power;
        teamB_Power += teamB[j].attack;
        teamB_Power += teamB[j].defence;
    }
    return teamA_Power > teamB_Power ;
}
