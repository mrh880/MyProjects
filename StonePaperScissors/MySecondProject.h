#include <iostream>
#include <stdlib.h>

using namespace std;

enum enQuestionsLevel {EasyLevel = 1, MedLevel, HardLevel, MixLevel};
enum enOperationType {Addition = 1, Subtract, Multiply, Division, MixOperation};

struct stQuestionInfo
{
    short FirstNumber = 0; 
    short SecondNumber = 0;
    enQuestionsLevel QuestionsLevel = enQuestionsLevel::EasyLevel; // for each question
    enOperationType OperationType = enOperationType::Addition   ; // for each question
    short CorrectAnswer = 0;
    short PlayerAnswer = 0;
    bool AnswerResult = false;
};

struct stGameInfo
{
    stQuestionInfo QuestionsInofList[100];
    short NumberOfQuestions = 0;
    enQuestionsLevel QuestionsLevel = enQuestionsLevel::EasyLevel;
    enOperationType OperationType = enOperationType::Addition;
    short NumberOfRightAnswers = 0;
    short NumberOfWrongAnswers = 0;
    bool isPass = false;
};

short RandomNumber(short From, short To)
{
    short Random = rand() % (To - From + 1) + From;
    return Random;
}

bool isNumberInRange(short Number, short From, short To)
{
    return(Number >= From && Number <= To);
}

void PrintTextOnScreen(const string &Text)
{
    cout << Text;
}

void PrintSymbolOnScreen(const char &Character)
{
    cout << Character;
}

void PrintSequenceOfCharacters(const char &Character, short NumberOfRepeating)
{
    for(short TimesToRepeat = 1; TimesToRepeat <= NumberOfRepeating; TimesToRepeat++)
        PrintSymbolOnScreen(Character);
}

void PrintHappyFace(){
    PrintTextOnScreen(":)");
}

void PrintSadFace()
{
    PrintTextOnScreen(":(");
}

short ReadShortNumber(const string &Message)
{
    PrintTextOnScreen(Message);
    short Number = 0;
    cin >> Number;
    return Number;
}

string ReadTextFromScreen(const string &Text)
{
    PrintTextOnScreen(Text);
    string String = "";
    cin >> String;
    return String;
}

void PrintNumberOnScreen(const short &Number)
{
    cout << Number;
}

void PrintLines(short NumberOfLines = 1)
{
    for(short Lines = 1; Lines <= NumberOfLines; Lines++)
        cout << endl;
}

void PrintTabs(short NumberOfTabs)
{
    for(short Tabs = 0; Tabs < NumberOfTabs; Tabs++)
        PrintSymbolOnScreen('\t');
}

void ResetScreen()
{
    system("color 0F");
    system("cls");
}

void ChangeScreenColorToGreen()
{
    system("color 0A");
}

void ChangeScreenColorToRed()
{
    system("color 4F");
}

void ChangeScreenColorToPurple()
{
    system("color 0D");
}

short ReadNumberOfQuestions()
{
    short NumberOfQuestions = 0;
    do
    {
        NumberOfQuestions = ReadShortNumber("How many questions do you want to answer: ");
    }while(!isNumberInRange(NumberOfQuestions, 1, 100));
    return NumberOfQuestions;
}

enQuestionsLevel ReadQuestionsLevel()
{
    short QuestionsLevel = 0;
    do 
    {
        QuestionsLevel = ReadShortNumber("Enter Questions level Easy[1], Med[2], Hard[3], Mix[4]: ");
    }while(!isNumberInRange(QuestionsLevel, 1, 4));
    return (enQuestionsLevel) QuestionsLevel;
}

enOperationType ReadOperationType()
{
    short OperationType = 0;
    do 
    {
        OperationType = ReadShortNumber("Enter Operation Type Add[1], Sub[2], Mul[3], Div[4], Mix[5]: ");
    }while(!isNumberInRange(OperationType, 1, 5));
    return (enOperationType) OperationType;
}

enQuestionsLevel GetRandomQuestionLevel()
{
    return (enQuestionsLevel) RandomNumber(1, 3);
}

enOperationType GetRandomOperationType()
{
    return (enOperationType) RandomNumber(1, 4);
}

enQuestionsLevel CheckIfQuestionLevelIsMixLevel(enQuestionsLevel QuestionLevel)
{
    if(QuestionLevel == enQuestionsLevel::MixLevel)
        return (enQuestionsLevel) RandomNumber(1, 3);
    else return  QuestionLevel;
} 

enOperationType CheckIfOperationTypeIsMixOperationType(enOperationType OperationType)
{
    if(OperationType == enOperationType::MixOperation)
        return (enOperationType) RandomNumber(1, 4);
    else 
        return  OperationType;
}

short GetNumberForQuestionAccordingToTheQuestionLevel(enQuestionsLevel QuestionLevel)
{
    switch(QuestionLevel)
    {
        case enQuestionsLevel::EasyLevel:
            return RandomNumber(1, 10);
        case enQuestionsLevel::MedLevel:
            return RandomNumber(10, 40);
        case enQuestionsLevel::HardLevel:
            return RandomNumber(40, 80);
        default: // no need
            return RandomNumber(4, 8);
    }
}

short GetResultAccordingToTheOperationType(short TheFirstNumber, short TheSecondNumber, enOperationType OperationType)
{
    switch(OperationType)
    {
        case enOperationType::Addition:
            return TheFirstNumber + TheSecondNumber;
        case enOperationType::Subtract:
            return TheFirstNumber - TheSecondNumber;
        case enOperationType::Multiply:
            return TheFirstNumber * TheSecondNumber;
        case enOperationType::Division:
            return TheFirstNumber / TheSecondNumber;
        default:
            return 0;
    }
}

stQuestionInfo GenerateQuestionInfo(enQuestionsLevel QuestionLevel, enOperationType OperationType)
{
    stQuestionInfo QuestionInof;

    QuestionInof.QuestionsLevel = CheckIfQuestionLevelIsMixLevel(QuestionLevel);
    QuestionInof.OperationType = CheckIfOperationTypeIsMixOperationType(OperationType);
    QuestionInof.FirstNumber = GetNumberForQuestionAccordingToTheQuestionLevel(QuestionInof.QuestionsLevel);
    QuestionInof.SecondNumber = GetNumberForQuestionAccordingToTheQuestionLevel(QuestionInof.QuestionsLevel);
    QuestionInof.CorrectAnswer = GetResultAccordingToTheOperationType(QuestionInof.FirstNumber, QuestionInof.SecondNumber, QuestionInof.OperationType);
    return QuestionInof;
}

void GenerateQuestionsInfo(stGameInfo &GameInfo)
{
    for(short Questions = 0; Questions < GameInfo.NumberOfQuestions; Questions++)
    {
        GameInfo.QuestionsInofList[Questions] = GenerateQuestionInfo(GameInfo.QuestionsLevel, GameInfo.OperationType);
    }
}

void GetPlayerAnswerForTheQuestion(stGameInfo &GameInfo, short NumberOfQuestion)
{
    short PlayerAnswer = ReadShortNumber("");
    GameInfo.QuestionsInofList[NumberOfQuestion].PlayerAnswer = PlayerAnswer;
}

void isPlayerAnswerIsCorrect(stGameInfo &GameInfo, short NumberOfQuestion)
{
    if(GameInfo.QuestionsInofList[NumberOfQuestion].CorrectAnswer == GameInfo.QuestionsInofList[NumberOfQuestion].PlayerAnswer)
        GameInfo.QuestionsInofList[NumberOfQuestion].AnswerResult = true;
    else 
        GameInfo.QuestionsInofList[NumberOfQuestion].AnswerResult = false;
}

char GetOperationTypeIntoText(enOperationType OperationType)
{
    switch(OperationType)
    {
        case enOperationType::Addition:
            return '+';
        case enOperationType::Subtract:
            return '-';
        case enOperationType::Multiply:
            return '*';
        case enOperationType::Division:
            return '/';
        default:
            return '+';
    }
}

void changeTheScreenColorAccordingToTheAnswerResult(bool Result)
{
    if(Result)
        ChangeScreenColorToGreen();
    else 
        ChangeScreenColorToRed();
}

void WhatToDoIfTheAnswerIsRight(stGameInfo &GameInfo, short NumberOfQuestion)
{
    changeTheScreenColorAccordingToTheAnswerResult(GameInfo.QuestionsInofList[NumberOfQuestion].AnswerResult);
    PrintTextOnScreen("Your answer is correct "); PrintHappyFace(); PrintLines();
    GameInfo.NumberOfRightAnswers++;
    PrintLines();
}

void WhatToDoIfTheAnswerIsWrong(stGameInfo &GameInfo, short NumberOfQuestion)
{
    changeTheScreenColorAccordingToTheAnswerResult(GameInfo.QuestionsInofList[NumberOfQuestion].AnswerResult);
    PrintTextOnScreen("Your answer is wrong "); PrintSadFace(); PrintLines();
    PrintTextOnScreen("The right answer is ==> "); PrintNumberOnScreen(GameInfo.QuestionsInofList[NumberOfQuestion].CorrectAnswer);
    PrintLines(2);
    GameInfo.NumberOfWrongAnswers++;
}

void WhatToDoAfterCheckTehAnswerWeatherItIsRightOrWrong(bool isTheAnswerIsRightOrWrong, stGameInfo &GameInfo, short NumberOfQuestion)
{
    if(isTheAnswerIsRightOrWrong)
        WhatToDoIfTheAnswerIsRight(GameInfo, NumberOfQuestion);
    else 
        WhatToDoIfTheAnswerIsWrong(GameInfo, NumberOfQuestion);
}

void PrintQuestion(stGameInfo &GameInfo, short NumberOfQuestion)    
{
    // Question [1/5]
    PrintTextOnScreen("Question ["); PrintNumberOnScreen((NumberOfQuestion+ 1)); PrintSymbolOnScreen('/'); PrintNumberOnScreen(GameInfo.NumberOfQuestions); PrintSymbolOnScreen(']'); PrintLines();  
    PrintNumberOnScreen(GameInfo.QuestionsInofList[NumberOfQuestion].FirstNumber); PrintLines();
    PrintNumberOnScreen(GameInfo.QuestionsInofList[NumberOfQuestion].SecondNumber); 
    PrintSymbolOnScreen(' '); PrintSymbolOnScreen(GetOperationTypeIntoText(GameInfo.QuestionsInofList[NumberOfQuestion].OperationType)); PrintLines();
    PrintSequenceOfCharacters('-', 10);
    PrintLines();
}

void PrintTheQuestionsAndGetPlayerAnswer(stGameInfo &GameInfo)
{
    for (short Questions = 0; Questions < GameInfo.NumberOfQuestions; Questions++)
    {
        PrintQuestion(GameInfo, Questions);
        GetPlayerAnswerForTheQuestion(GameInfo, Questions);
        isPlayerAnswerIsCorrect(GameInfo, Questions);
        PrintLines();
        WhatToDoAfterCheckTehAnswerWeatherItIsRightOrWrong(GameInfo.QuestionsInofList[Questions].AnswerResult, GameInfo, Questions);
        // WhatToDoAfterCheckTehAnswerWeatherItIsRightOrWrong(isPlayerAnswerIsCorrect(GameInfo.QuestionsInofList[Questions].CorrectAnswer,
        // GameInfo.QuestionsInofList[Questions].PlayerAnswer), GameInfo, Questions);
    }
}

void PrintGameOverScreen()
{
    ChangeScreenColorToPurple();
    PrintTabs(8); PrintSequenceOfCharacters('*', 40); PrintLines();
    PrintTabs(10); PrintTextOnScreen("GAME OVER"); PrintLines();
    PrintTabs(8); PrintSequenceOfCharacters('*', 40);   PrintLines(2);
}

string GetQuestionLevelIntoText(enQuestionsLevel QuestionLevel)
{
    string QuestionsLevel[4] = {"Easy", "Med", "Hard", "Mix"};
    return QuestionsLevel[QuestionLevel -1 ];
}

string GetOperationTypeInotText(enOperationType OperationType)
{
    string OperationsType[5] = {"+", "-", "*", "/", "Mix"};
    return OperationsType[OperationType - 1];
}

void PrintGameResult(stGameInfo &GameInfo)
{
    PrintTabs(8); PrintSequenceOfCharacters('*', 41); PrintLines();
    PrintTabs(8); PrintSymbolOnScreen('*'); PrintTabs(2); PrintTextOnScreen("GAME RESULT"); PrintTabs(2); PrintSymbolOnScreen('*'); PrintLines(); 
    PrintTabs(8); PrintSequenceOfCharacters('*', 41); PrintLines();
    PrintTabs(9); PrintTextOnScreen("Number of questions =>> "); PrintNumberOnScreen(GameInfo.NumberOfQuestions); PrintLines();
    PrintTabs(9); PrintTextOnScreen("Questions level =>> "); PrintTextOnScreen(GetQuestionLevelIntoText(GameInfo.QuestionsLevel)); PrintLines();
    PrintTabs(9); PrintTextOnScreen("Operation type ==> "); PrintTextOnScreen(GetOperationTypeInotText(GameInfo.OperationType)); PrintLines();
    PrintTabs(9); PrintTextOnScreen("Number of right answers ==> "); PrintNumberOnScreen(GameInfo.NumberOfRightAnswers); PrintLines();
    PrintTabs(9); PrintTextOnScreen("Number of wrong answers ==> "); PrintNumberOnScreen(GameInfo.NumberOfWrongAnswers);
    PrintLines();
    PrintTabs(8); PrintSequenceOfCharacters('*', 40);
    PrintLines();
}

void PlayMathGame()
{
    stGameInfo GameInfo;
    GameInfo.NumberOfQuestions = ReadNumberOfQuestions();
    GameInfo.QuestionsLevel = ReadQuestionsLevel();
    GameInfo.OperationType = ReadOperationType();
    GenerateQuestionsInfo(GameInfo);
    PrintTheQuestionsAndGetPlayerAnswer(GameInfo);
    PrintGameOverScreen();
    PrintGameResult(GameInfo);
}

void StartTheGame()
{
    string Answer = "";
    do
    {
        ResetScreen();
        PlayMathGame();
        Answer = ReadTextFromScreen("Do you to play again (Y/N): ");
    }while(Answer == "Yes" || Answer == "yes" || Answer == "Y" || Answer == "y");
}

void StartGame()
{
    srand((unsigned) time(NULL));
    StartTheGame();
}
