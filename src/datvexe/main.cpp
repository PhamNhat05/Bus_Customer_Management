#include<bits/stdc++.h>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include "xuli1.h"
using namespace std;

string day_display[] = {"01","02","03","04","05","06","07","08",
                        "09","10","11","12","13","14","15","16",
                        "17","18","19","20","21","22","23","24",
                        "25","26","27","28","29","30"};
                        
string number_Bed[] = {"01","02","03","04","05","06","07","08",
                    "09","10","11","12","13","14","15"};
void gotoxy(short x, short y){
 HANDLE hConsoleOutput;
 COORD Cursor_an_Pos = { x, y };
 hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void TextColor(int x)
{
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

void hide_Cursor()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut,&ConCurInf);
}

void show_Pointer()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = TRUE;
    SetConsoleCursorInfo(hOut,&ConCurInf);
} 
void Table_day(int ox, int oy){
    int denta = ox;
    for(int i = 0; i < 30; i++){
        if(i == 6 || i == 12 || i == 18 || i == 24 || i == 30){
            oy = oy + 2;
            ox = denta;
        }
        gotoxy(ox,oy-1);
        cout << "+------+";
        gotoxy(ox,oy);
        cout << "|  ";
        gotoxy(ox+3,oy);
        cout << day_display[i];
        cout <<"  |";
        gotoxy(ox,oy+1);
        cout << "+------+";
        ox = ox + 7;
    }
    hide_Cursor();
}
void table_Bed (int ox, int oy){
    int denta = ox;
        for(int i = 0; i < 15; i++){
        if(i == 3 || i == 6 || i == 9 || i == 12){
            oy = oy + 2;
            ox = denta;
        }
        gotoxy(ox,oy-1);
        cout << "+------+";
        gotoxy(ox,oy);
        cout << "|  ";
        gotoxy(ox+3,oy);
        cout <<number_Bed[i];
        cout <<"  |";
        gotoxy(ox,oy+1);
        cout << "+------+";
        ox = ox + 7;
    }
    hide_Cursor();
}
// ve bang ghe da chon
void table_Bed_choose (int ox, int oy,string &bedchoose){
    int denta = ox;
        for(int i = 0; i < 15; i++){
        if(i == 3 || i == 6 || i == 9 || i == 12){
            oy = oy + 2;
            ox = denta;
        }
        TextColor(15);
        gotoxy(ox,oy-1);
        cout << "+------+";
        if(bedchoose.compare(number_Bed[i]) == 0){
            TextColor(12);
            gotoxy(ox,oy);
            cout << "|  ";
            gotoxy(ox+3,oy);
            cout <<number_Bed[i];
            cout <<"  |";
        }
        TextColor(15);
        gotoxy(ox,oy+1);
        cout << "+------+";
        ox = ox + 7;
    }
    //hide_Cursor();
}
void display_2(string &time, string &loaighe, string &soghe){
    if(time == "8"){
        if(loaighe == "A"){
            table_Bed_choose(80,10,soghe);
        }else if(loaighe == "B"){
            table_Bed_choose(80,22,soghe);
        }
    }else if(time == "10"){
        if(loaighe == "A"){
            table_Bed_choose(120,10,soghe);
        }else if(loaighe == "B"){
            table_Bed_choose(120,22,soghe);
        }
    }
}
void line(int biendem){
    for(int i = 0; i < (biendem +1); i++){
        cout << "-";
    }
}
string choose_Day(int ox, int oy,thongtin_KH KH[],int biendem){
    int setX = ox, setY = oy;
    int vtox = ox, vtoy = oy;
    TextColor(15);
    Table_day(ox,oy);
    char c;
    int day = 1;
    int a = 6;
    int setspace = 1;
    TextColor(9);
    gotoxy(setX,setY);
    cout << "| ";
    gotoxy(setX+3,setY);
    cout << day_display[0];
    cout <<"  |";
    show_Pointer();
    gotoxy(setX + 5,setY);
    while(1){
        if(kbhit()){
            c = getch();
            switch(c){
                case 's': {
                    TextColor(14);
                    gotoxy(42,27);
                    cin >> KH[biendem].MS;
                    KH[biendem].day_choose = day_display[day-1];
                    return KH[biendem].day_choose ; 
                    break;
                }
                case 13:{ //enter   
                    TextColor(14);
                    gotoxy(88,8);
                    cout << "8 gio";
                    gotoxy(128,8);
                    cout << "10 gio";
                    gotoxy(36,12);
                    cout <<day_display[day-1];
                    TextColor(15);
                    table_Bed(80,10);
                    table_Bed(80,22);
                    table_Bed(120,10);
                    table_Bed(120,22); 
                    switch(KH[biendem].phanloai){
                        case 0:{
                            for(int i = 0; i < biendem; i++){
                                if((day_display[day-1]).compare(KH[i].day_choose) == 0
                                    && KH[i].phanloai == 0){
                                        tachMS(KH,i);
                                        display_2(KH[i].time,KH[i].loaighe, KH[i].soghe);
                                }
                            }
                            break;
                        }
                        case 1:{
                            for(int i = 0; i < biendem; i++){
                                if((day_display[day-1]).compare(KH[i].day_choose) == 0
                                    && KH[i].phanloai == 1){
                                        tachMS(KH,i);
                                        display_2(KH[i].time,KH[i].loaighe, KH[i].soghe);
                                }
                            }
                            break;
                        }
                        case 2:{
                            for(int i = 0; i < biendem; i++){
                                if((day_display[day-1]).compare(KH[i].day_choose) == 0
                                    && KH[i].phanloai == 2){
                                        tachMS(KH,i);
                                        display_2(KH[i].time,KH[i].loaighe, KH[i].soghe);
                                }
                            }
                            break;
                        }
                        default:{
                            TextColor(15);
                            table_Bed(80,10);
                            table_Bed(80,22);
                            table_Bed(120,10);
                            table_Bed(120,22);
                            break;
                        }
                    } 
                    setX -= 6;
                    setspace -= 1;
                    day -= 1; 
                }
                case 77:{       // phim sang phai
                    setX += 6;
                    day += 1;
                    if(setX == 36 + vtox){
                        setX = vtox;
                        day = day - 6;
                        a = 6;
                        setspace = 0;
                    }
                    setspace ++;
                    gotoxy(setX + a + setspace -1,setY);
                    break;
                }
                case 75:{       	// phim sang trai
                    if(setX == vtox ){
                        setX = vtox + 36;
                        day = day + 6;
                        setspace = 7 ;
                        a = 0;
                    }
                    day -= 1;
                    setspace --;
                    setX -= 6;
                    a = 6;
                    gotoxy(setX + a + setspace -1,setY);
                    break;
                }
                case 72:{       	// phim len
                    if(setY == vtoy ){
                        setY = vtoy + 10;
                        day = day + 30;
                    } 
                    day -= 6;
                    gotoxy(setX + a + setspace - 1,setY-2) ;
                    setY -= 2;
                    break;
                }
                case 80:{       	// phim xuong 
                    if(setY == vtoy + 8){
                        setY = vtoy - 2;
                        day = day - 30;
                    }
                    day += 6;
                    gotoxy(setX + a + setspace -1 ,setY+2) ;
                    setY += 2;
                    break;
                }
            }
            TextColor(15);
            hide_Cursor();
            Table_day(vtox,vtoy);
            TextColor(9);
            show_Pointer();
            gotoxy(setX + setspace - 1,setY);
            cout << "| ";
            gotoxy(setX + 2 + setspace,setY);
            cout << day_display[day-1]; 
            cout << "  |";
            gotoxy(setX + a + setspace - 1,setY);
        }
    }
}

void nhap1(thongtin_KH &KH){
    int setX = 20;
    int setY = 10;
    TextColor(3);
    TextColor(15);
    Table_day(setX,setY+4);
    show_Pointer();
    gotoxy(80,6);
    cout << "KHUNG GIO XUAT PHAT:";
    TextColor(14);
    gotoxy(107,14);
    cout << "Giuong A";
    gotoxy(107,26);
    cout << "Giuong B";
    TextColor(15);
    table_Bed(80,10);
    table_Bed(80,22);
    table_Bed(120,10);
    table_Bed(120,22);
    show_Pointer();
    TextColor(2);
    gotoxy(65,3);
    cout << "DAT VE XE DI DU DUA DI:";
    TextColor(15);
    gotoxy(setX,6);
    cout << "So dien thoai: ";
    gotoxy(setX,8);
    cout << "Ho va ten khach hang:";
    gotoxy(setX,10);
    cout << "Dia diem xuat phat: ";
    gotoxy(setX,12);
    cout << "Ngay xuat phat: ";
    gotoxy(setX,27);
    cout << "Nhap ma so chuyen di: ";
    gotoxy(setX,26);
    TextColor(14);
    cout << "(VD ma so chuyen di: 8h-A13)";
    TextColor(9);
    gotoxy(setX,24);
    cout << "(bam 's': de luu ngay / Enter: chon ngay)";
    gotoxy(setX+75,32);
    TextColor(14);
    cout << "(Mau";
    TextColor(12);
    cout << " DO:";
    TextColor(14);
    cout << " la ghe da co khach dat)";
    TextColor(14);
    gotoxy(setX + 15,6);
    cin >> KH.numberphone;
    gotoxy(setX + 22,8);
    cin.ignore();
    getline(cin,KH.name);
    gotoxy(setX + 20,10);
    getline(cin,KH.location);
}

void input_Data(thongtin_KH KH[], int &biendem){
    nhap1(KH[biendem]);
    phanloaiKH(KH,biendem);
    choose_Day(20,14,KH,biendem);
    gotoxy(30,30);
    TextColor(14);
    cout << "Them thanh cong";
    fstream oufile;
    oufile.open("C:\\Users\\ADMIN\\OneDrive\\Documents\\quanlikh\\quanli\\dulieu.txt", ios::app);
    oufile << endl <<KH[biendem].name << endl;
    oufile << KH[biendem].numberphone << endl;
    oufile << KH[biendem].location << endl;
    oufile << KH[biendem].MS << endl;
    oufile << KH[biendem].day_choose;
    oufile.close();
	++biendem;
    fstream oufilecnt;
    oufilecnt.open("C:\\Users\\ADMIN\\OneDrive\\Documents\\quanlikh\\quanli\\count.txt");
    oufilecnt << biendem;
    oufilecnt.close();

}
void Thongbao(){
    char c;
    TextColor(15);
    gotoxy(60,20);
    cout << "Mo to cua so len nhe !!!";
    gotoxy(60,22);
    cout << "Sau do hay nhan enter";
    while(1){
        if(kbhit()){
            c = getch();
            if(c == 13){
                system("cls");
                break;
            }
        }
    }
}
void Cover(){
    char c = 0;
    gotoxy(60,20);cout << "Nha xe han hanh phuc vu cac chuyen sau:";
    gotoxy(35,22);cout<<"    Da Nang - Quang Nam     |   Da Nang - Ho Chi Minh   |    Da Nang - Thua Thien Hue";
    gotoxy(35,24);cout<<" Gio xuat phat: 8h va 10h   | Gio xuat phat: 8h va 10h  |    Gio xuat phat: 8h va 10h";
    gotoxy(70,30);cout << "Nhan Enter de tiep tuc";
    while(1){
        for(int i = 0; i <= 15; i++){
            TextColor(i);
            gotoxy(20,3);cout <<" ___    _   _     _       ___            _    _   _____      ";
            gotoxy(20,4);cout<<"|   \\  | | | |   | |     / _ \\           \\ \\/ /  | ____|  ";  
            gotoxy(20,5);cout<<"| |\\ \\ | | | |___| |    / /_\\ \\           \\/ /   | |___   ";  
            gotoxy(20,6);cout<<"| | \\ \\| | |  ___  |   / _____ \\          / \/\\\   | ____| ";   
            gotoxy(20,7);cout<<"| |  \\   | | |   | |  / /     \\ \\        / /\\ \\  | |___   ";  
            gotoxy(20,8);cout<<"|_|   \\__| |_|   |_| /_/       \\_\\      /_/  \\_\\ |_____|  ";  
            gotoxy(40,10);cout <<" _____   _     _       ___       __        __        ___     _   _     _       ___     ___________              ";
            gotoxy(40,11);cout<<"|  _  \\ | |   | |     / _ \\     |  \\      /  |      |   \\   | | | |   | |     / _ \\   |____   ____|         ";
            gotoxy(40,12);cout<<"| |_) | | |___| |    / /_\\ \\    |   \\    /   |      | |\\ \\  | | | |___| |    / /_\\ \\       | |            ";
            gotoxy(40,13);cout<<"| ___/  |  ___  |   / _____ \\   | |\\ \\  / /| |      | | \\ \\ | | |  ___  |   /  ____ \\      | |             ";
            gotoxy(40,14);cout<<"| |     | |   | |  / /     \\ \\  | | \\ \\/ / | |      | |  \\ \\| | | |   | |  / /     \\ \\     | |           ";
            gotoxy(40,15);cout<<"|_|     |_|   |_| /_/       \\_\\ |_|  \\__/  |_|      |_|   \\___| |_|   |_| /_/       \\_\\    |_|             ";
            Sleep(100);
            if(kbhit()){
                c= getch();
            }    
        }
        if( c == 13) {system("cls") ;break;}
        Sleep(0);
    }
    Sleep(50);
}
int main(){
    int check = 0;
    int n = 0;
    int count;
    fstream infilecnt("https://1drv.ms/t/s!AoBWCN0gvtdVjTtR6sZQxknc69yr?e=8XjFT8");
    infilecnt >> count;
    fstream infile("https://1drv.ms/t/s!AoBWCN0gvtdVjB3GzR5VZ1AGzVti?e=us8AYI");
        for(int i = 0; i < count; i++){
            getline(infile, KH[i].name);
            getline(infile, KH[i].numberphone);
            getline(infile, KH[i].location);
            getline(infile, KH[i].MS);
            getline(infile, KH[i].day_choose);
    } 
    infile.close();
    Thongbao();
    Cover();
    input_Data(KH,count);
    return 0;
}
