#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*-----------------------------------------------------------------------------------------*/

struct Options
{
  string op1;
  string op2;
  string op3;
  string op4;
};
// Each Question
struct Question
{
  string question;
  Options options;
  int answer;
};

/*-----------------------------------------------------------------------------------------*/

//* Global Variables
bool GAME_STILL_GOING = true;
int QUESTIONS_LEFT = 3;
int CURRENT_SCORE = 0;
int QUESTION_NO = 1;

//* Functions
void askQuestion();
void question(string, string, string, string, string, int);
int main()
{

  askQuestion();
  cout << "Game Ended\n"
       << "Your Final Score : " << CURRENT_SCORE << endl;

  return 0;
}

void askQuestion()
{
  while (QUESTIONS_LEFT != 0)
  {
    string question_1 = "Which of the following is the largest land Animal ?";
    string question_2 = "Which of the follwing is not a programming language ?";
    string question_3 = "By using which language you can hack Nasa ?";
    question(question_1, "Elephant", "Lion", "Blue Whale", "Giraffe", 3);
    question(question_2, "HTML", "C++", "Python", "JavaScript", 1);
    question(question_3, "CSS", "HTML", "C++", "Python", 2);
  }
}

void question(string question, string op1, string op2, string op3, string op4, int answer)
{

  int USER_CHOICE;

  Options opt;
  opt.op1 = op1;
  opt.op2 = op2;
  opt.op3 = op3;
  opt.op4 = op4;

  Question q;
  q.question = question;
  q.options = opt;
  q.answer = answer;

  cout << "                    "
       << "Your Current Score:" << CURRENT_SCORE << "\n"
       << "<------------------------------------------>"
       << endl;
  //   Questions
  cout << "Q" << QUESTION_NO << "." << q.question << endl
       << endl;

  //  Options

  cout << "Option 1: " << opt.op1 << endl;
  cout << "Option 2: " << opt.op2 << endl;
  cout << "Option 3: " << opt.op3 << endl;
  cout << "Option 4: " << opt.op4 << endl;
  cout << "\n"
       << endl;
  cout << "Enter the correct option: ";
  cin >> USER_CHOICE;

  if (USER_CHOICE == q.answer)
  {
    cout << "\nYou got it! :((\n"
         << endl;
    CURRENT_SCORE++;
  }
  else
  {
    cout << "\nOh! you missed it! :))\n " << endl;
  }
  QUESTIONS_LEFT--;
  QUESTION_NO++;
}
