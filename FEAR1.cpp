#include <thread>

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <direct.h>
#include <fstream>
#include <ctime>

// just a test

const char * cok;
const int speed = 250;
char dir[FILENAME_MAX];

void speak()
{
    system(cok);
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void upd(int ct = 15, int cb = 0){
    SetConsoleTextAttribute(hConsole, (WORD) ((cb << 4) | ct));
    system("cls");
}

void clr(int ct, int cb = 0){
    SetConsoleTextAttribute(hConsole, (WORD) ((cb << 4) | ct));
}

int main(){
    srand(time(0));
    _getcwd(dir, sizeof(dir));
    upd();
    std::cout <<"CTPAIIIHO, BbIPY6AN \n\"Enter\" to BbIPY6NTb";
    char c = _getch();
    upd();
    switch(c){
        case 13:
            std::cout <<"CPACN6O, 4TO BbIPY6N/\\";
            std::cin.ignore();
            break;
        default:
            std::cout <<"TE6E HE CTPAIIIHO??";
            Sleep(500);
            for (int c = 0; c < 3; c++)
            for (int i = 0; i < 3; i++){
                Sleep(100);
                upd();
                std::cout <<"3arpy3ka";
                for (int j = 0; j <= i; j++){
                    std::cout<<'.';
                }
            }
            std::ifstream I;
            std::string str, word;
            I.open("FEAR1_text.txt", std::ios::in);
            while (!I.eof()){
                upd();
                std::getline(I, str);
                word = "";
                int asp = 0;
                do{
                    int i = word.length() - asp;
                    int sp;
                    sp = rand()%25+10;
                    asp += sp;
                    for (int j = 0; j < sp; j++)
                        word += char(rand()%93+33);
                    std::string nword = "";
                    do{
                        nword += std::toupper(str[i]);
                        i++;
                    }while(str[i] != ' ' && i < str.length());

                    char cmd[100];
                    const char * cnword = nword.c_str();
                    sprintf(cmd, "%s\\espeak -ven+m1 -z -s%d -p0 \"%s\"", dir, speed+5, cnword);
                    cok = cmd;
                    std::thread t(speak);

                    for (int i = 0; i < nword.length(); i++){
                        std::cout<<word;
                        clr(rand()%14 + 1);
                        for (int j = 0; j <= i; j++)
                            std::cout<<nword[j];
                        Sleep(5000/speed);
                        if (i == nword.length()-1)
                            t.join();
                        if (i%2 == 0)
                            upd(0, 15);
                        else
                            upd();
                    }
                    word += nword;
                    sp = rand()%25+10;
                    asp += sp;
                    for (int i = 0; i < sp; i++)
                        word += char(rand()%93+33);
                    std::string ns = "\n\n\n";
                    word += ns;
                    asp += ns.length();
                }while (word.length() < str.length() + asp - 2);
                }
            I.close();
        }
    return 0;
}
