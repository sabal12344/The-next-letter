#include <iostream>
#include<cstdlib>
#include<chrono>
using namespace std;
char accuracy(int score){
 
 if(score==13)
 return 'a';

 else if(score>10)
 return 'b';

 else if(score>7)
 return 'c';

 else
 return 'd';

}
void evaluation(double time, int score){
  char acc=accuracy(score);
  if(time<=6){
    switch(acc){
      case 'a':
      cout<<"You are a superhuman";
      break;

      case 'b':
      cout<<"You type super fast with good accuracy.";
      break;

      default:
      cout<<"You are just winging your fingers here and there.";
      break;
    }

    
  }
  else if(time<=15){
     switch(acc){
      case 'a':
      cout<<"That was fast, and you scored perfect";
      break;

      case 'b':
      cout<<"Not fully accurate but it was fast.";
      break;

      default:
      cout<<"Not accurate enough!";
      break;
    }
  }
  else if(time<=30){
    if(acc=='a'){
      cout<<"Good score";
    }
    else
    cout<<"Not accurate enough..";
  }

  else{
    cout<<"You need more practice.";
  }


}

int main(){
  auto start = chrono::high_resolution_clock::now();
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();

  srand(seed);

  
   char input;
   int score=0;
   char evens[]={'Q','E','T','U','O','A', 'D','G','J','L','X','V','N'};

   char odds[]={'W','R','Y','I','P','S', 'F','H','K','Z','C','B','M'};

   

  for(unsigned int i=0;i<sizeof(evens);i++){
    int random = rand()%13;
    cout<<evens[random]<<endl;
    cin>>input;
     if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            cout << "\n\nError! Please enter a single character at a time.\n\n";
            return 0;
        }
    input=toupper(input);
    
    if(input==odds[random]){
        score++;
    }
    auto end =chrono::high_resolution_clock::now();
  chrono::duration<double> timetaken = end - start;


    
  }
  cout<<"\n\nYour score is "<<score<<" /13";

  auto end =chrono::high_resolution_clock::now();
  chrono::duration<double> timetaken = end - start;

  double t = timetaken.count();
  cout<<"\nTime taken : "<<t<<" seconds.";
  cout<<"\n\n\t\tEvaluation : ";
  evaluation(t,score);
return 0;
}
