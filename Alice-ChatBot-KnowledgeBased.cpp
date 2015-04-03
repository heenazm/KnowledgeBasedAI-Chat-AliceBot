/* it is a knowledge base c++ program that provides responses based on the available knowledge and input given by the user" */

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 3;
typedef vector<string> vstring;
vector<string> pattern(string input);
void copy(char *array[], vstring &v);

typedef struct {
    char *input;
    char *op[SIZE];
}struct1;

void copy(char  *array[], vstring &v) { 
    for(int i = 0;  i < SIZE; ++i) {
        v.push_back(array[i]);
    }
}

struct1 data[] = {
    {"WHAT IS YOUR NAME", 
    {"MY NAME IS ALICE :-)",
     "YOU CAN CALL ME ALICE :-).",
     "WHY DO YOU WANT TO KNOW MY NAME?"}
    },
    {"HI", 
    {"HEY THERE!",
     "HOW ARE YOU?",
     "HI!"}
    },
    {"DO YOU LIKE TALKING TO ME?",
    {"HMMN, KIND OF, AND YOU?",
    "YES, I DO LIKE IT, INFACT I FIND YOU CUTE",
    "YES, IF THIS IS WHAT YOU WANT TO HEAR :-P" }
    },
    {"HOW ARE YOU",
    {"I AM DOING FINE!",
    "I DON'T KNOW EXACTLY, MAYBE I FEEL FINE WITH YOU",
    "WHY DO YOU WANT TO KNOW HOW AM I DOING?"}
    },
    {"WHO ARE YOU",
    {"I AM NOT A BOT",
     "DON'T ACT LIKE YOU DON'T KNOW WHO ARE TALKING TO",
     "DO YOU EVEN CARE?"}
    },
    {"ARE YOU REAL",
    {"DOES THAT QUESTION REALLY MATERS TO YOU?",
     "WHAT DO YOU MEAN BY THAT?",
     "I'M AS REAL AS I CAN BE."}
    }
};

int kbsize= sizeof(data)/sizeof(data[0]);

int main() {
	cout<<"-------WELCOME! LET'S TALK TO ALICE (Note: 3 responses, to end say: BYE)--------------"<<endl;
    string sInput = "";
    string sResponse = "";

    while(1) {
        cout << "ALICE: ";
        getline(cin, sInput);
        vstring op =pattern(sInput);
        if(sInput == "BYE") {
            cout << "I WANT TO TALK TO YOU AGAIN SOON ! :-)" <<endl;  
            break;
        } 
        else if(op.size() == 0)  {
            cout << "AHH, I AM NOT PROGRAMMED TO UNDERSTAND YOUR SILENCE! X-(" << endl;
        }
        else {
            int nSelection = rand()  % 3;
            sResponse =op[nSelection];
            cout << sResponse <<endl; 
        } 
    } 
    return 0;
}

vector<string> pattern(string  input) { 
    vstring result;
    for(int i = 0; i < kbsize;  ++i) {  
        if(string(data[i].input) == input) { 
            copy(data[i].op, result); 
            return result;
        } 
    } 
    return result; 
} 
