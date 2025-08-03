#include <iostream>
#include <cstdlib>

using namespace std;

// enum enPlayers {Player, Computer};
enum enWinner {Player = 1, Computer = 2, Draw = 3};
enum enPlayerChoice {Stone = 1, Paper = 2, Scissor = 3};

int RandomNumber(int From, int To)
{
    int Random = rand() % (To - From + 1) + From;    
    return Random;
}

string ReadString(const string &Message)
{
    cout << Message;
    string String = "";
    cin >> String;
    return String;
}

bool isNumberInRange(short Number, short From, short To)
{
    return (Number >= From && Number <= To);
}

short ReadShortPositiveNumberInRange(const string &Message, short From, short To)
{
    short Number = 0;
    do
    {
        cout << Message;
        cin >> Number;

    } while(!isNumberInRange(Number, From, To));
    return Number;
}

struct stRoundInfo
{
    short NumberOfRound = 0;
    enPlayerChoice PlayerChoice;
    enPlayerChoice ComputerChoice;
    enWinner WinnerInRound;
    string WinnerName = "";
    short TimesOfPlayerWin = 0;
    short TimeOfComputerWin = 0;
    short TimesOfDrawForBothPlayers = 0;
};

struct stGameInfo
{
    short NumberOfRoundsWerePlayed = 0;
    short TimesOfWinForPlayer = 0;
    short TimesOfWinForComputer = 0;
    short TimesOfDrawForBothPlayerAndComputer = 0;
    enWinner GameWinner;
    string WinnerName = "";

};

enPlayerChoice ReadPlayerChoice()
{
    short PlayerChoice = ReadShortPositiveNumberInRange("Enter your choice (1 => Stone, 2 => Paper, 3 => Scissor): ", 1, 3);
    return (enPlayerChoice) PlayerChoice;
}

enPlayerChoice GetComputerChoice()
{
    return (enPlayerChoice) RandomNumber(1, 3);
}

void ResetScreen()
{
    system("cls");
}

enWinner WhoWonInTheRound(enPlayerChoice PlayerChoice /*stone*/, enPlayerChoice ComputerChoice /*Scissor*/)
{
    if(PlayerChoice == ComputerChoice)
        return enWinner::Draw;

    switch(ComputerChoice)
    {
        case enPlayerChoice::Stone:
            if(PlayerChoice == enPlayerChoice::Scissor)
                return enWinner::Computer;
        
        case enPlayerChoice::Paper:
            if(PlayerChoice == enPlayerChoice::Stone)
                return enWinner::Computer;

        case enPlayerChoice::Scissor:
            if(PlayerChoice == enPlayerChoice::Paper)
                return enWinner::Computer;
    }
    return enWinner::Player;
}

string GetWinnerName(enWinner Winner)
{
    string WinnerName[4] = {"", "Player", "Computer", "Draw"};
    return WinnerName[(short) Winner];
}

string ConvertPlayerChoiceToString(enPlayerChoice PlayerChoice)
{
    if(PlayerChoice == enPlayerChoice::Stone)
        return "Stone";
    else if(PlayerChoice == enPlayerChoice::Paper)
        return "Paper";
    else 
        return "Scissor";
}

void GetPointToWinnerInRound(stRoundInfo &RoundInfo)
{
      if(RoundInfo.WinnerName == "Player")
            RoundInfo.TimesOfPlayerWin++;
        else if(RoundInfo.WinnerName == "Computer")
            RoundInfo.TimeOfComputerWin++;
        else 
            RoundInfo.TimesOfDrawForBothPlayers++;
}

void PrintResultOfRound(stRoundInfo &RoundInfo)
{   
    cout << "**********************************************************\n";
    cout << "Round [" << RoundInfo.NumberOfRound << "]" << endl;
    cout << "Player Choice: " << ConvertPlayerChoiceToString(RoundInfo.PlayerChoice) << endl;
    cout << "Computer Choice: " << ConvertPlayerChoiceToString(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner: " << RoundInfo.WinnerName << endl; 
    cout << "**********************************************************\n";
}

string Tab(short NumberOfTabs)
{
    string Tabs = "";
    for(short loop = 0; loop < NumberOfTabs; loop++)
        Tabs += "\t";
    return Tabs;
}

void ShowGameOverScreen()
{
    cout << Tab(2) << "---------------------------------------\n";
    cout << Tab(2) << "Game Over\n"; 
    cout << Tab(2) << "---------------------------------------\n";
}

enWinner WhoWonInTheGame(short TimesOfWinForPlayer, short TimesOfWinForComputer)
{
    if(TimesOfWinForPlayer > TimesOfWinForComputer)   
        return enWinner::Player;
    else if(TimesOfWinForComputer > TimesOfWinForPlayer)
        return enWinner::Computer;
    else 
        return enWinner::Draw;
}

stGameInfo FillFinalResult(short NumberOfRounds, short TimesOfWinForPlayer, short TimesOfWinForComputer, short TimeOfDrawFowBothPlayer)
{
    stGameInfo GameInfo;
    GameInfo.NumberOfRoundsWerePlayed = NumberOfRounds;
    GameInfo.TimesOfWinForPlayer = TimesOfWinForPlayer;
    GameInfo.TimesOfWinForComputer = TimesOfWinForComputer;
    GameInfo.TimesOfDrawForBothPlayerAndComputer = TimeOfDrawFowBothPlayer;
    GameInfo.GameWinner = WhoWonInTheGame(GameInfo.TimesOfWinForPlayer, GameInfo.TimesOfWinForComputer);
    GameInfo.WinnerName = GetWinnerName(GameInfo.GameWinner);
    return GameInfo;
}

stGameInfo PlayGame(short HowManyRounds)
{
    stRoundInfo round_info;
    for(short GameRounds = 1; GameRounds <= HowManyRounds; GameRounds++)
    {
        cout << "Round [ " << GameRounds << " ] " << endl;
        round_info.NumberOfRound = GameRounds;
        round_info.PlayerChoice = ReadPlayerChoice();
        round_info.ComputerChoice = GetComputerChoice();
        round_info.WinnerInRound =  WhoWonInTheRound(round_info.PlayerChoice, round_info.ComputerChoice);
        round_info.WinnerName = GetWinnerName(round_info.WinnerInRound);
        GetPointToWinnerInRound(round_info);
        PrintResultOfRound(round_info);
    }   
    return FillFinalResult(round_info.NumberOfRound, round_info.TimesOfPlayerWin, round_info.TimeOfComputerWin, round_info.TimesOfDrawForBothPlayers);
}

void PrintFinalGameResult(stGameInfo &GameInfo)
{
    cout << "Game Rounds: " << GameInfo.NumberOfRoundsWerePlayed << endl;
    cout << "Player won times: " << GameInfo.TimesOfWinForPlayer << endl;
    cout << "Computer won time: " << GameInfo.TimesOfWinForComputer << endl;
    cout << "Draw times: " << GameInfo.TimesOfDrawForBothPlayerAndComputer << endl;
    cout << "Final Winner: " << GameInfo.WinnerName << endl;
}

void StartGame()
{
    string Answer = "";
    do 
    {
        ResetScreen(); 
        stGameInfo GameResults = PlayGame(ReadShortPositiveNumberInRange("Enter how many rounds you want to play: (1 - 10): ", 1, 10));
        ShowGameOverScreen();
        PrintFinalGameResult(GameResults);
        cout << "Do you want to play again: ";
        cin >> Answer;
    } while(Answer == "y" || Answer == "Y" || Answer == "yes" || Answer == "Yes");
}

void Print()
{
    srand((unsigned) time(NULL));
    StartGame();
} 