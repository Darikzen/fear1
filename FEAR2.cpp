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
const int speed = 300;
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
            std::string str;
            I.open("FEAR1_text.txt", std::ios::in);
            while (!I.eof()){
                upd();
                std::getline(I, str);

                    std::string pre = "", pos = "", word = " ";
                    int sp;
                    sp = rand()%200+100;
                    for (int j = 0; j < sp; j++)
                        pre += ' ';
                    sp = rand()%400+100;
                    for (int j = 0; j < sp; j++){
                        pre += char(rand()%93+33);
                        pos += char(rand()%93+33);
                    }

                    char cmd[100];
                    const char * cstr = str.c_str();
                    sprintf(cmd, "%s\\espeak -ven+m1 -z -s%d -p0 \"%s\"", dir, speed, cstr);
                    cok = cmd;
                    std::thread t(speak);

                    for (int i = 0; i < str.length(); i++){
                        std::cout<<pre;
                        clr(rand()%14 + 1);
                        word += toupper(str[i]);
                        std::cout<<word;
                        if (i%2 == 0)
                                clr(15);
                            else
                                clr(0, 15);
                        std::cout<<pos;
                        Sleep(3000/speed);
                        if (i == str.length()-1){
                            t.join();
                        }
                        if (i%2 == 0)
                            upd(0, 15);
                        else
                            upd();
                    }
                }
            I.close();
        }
    return 0;
}
