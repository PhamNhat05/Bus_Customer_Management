#include<string>
using namespace std;

struct thongtin_KH{
    string location,name;
    int timkiem; int phanloai;
    string numberphone ;
    string MS;
    string day_choose,time;
    string loaighe,soghe;
    //int month;
 //   int tiendien = rand() % 100;
} KH[100], KHcon[100];

string locat_const[] = {"Quang Nam","Thua Thien Hue","Ho Chi Minh"} ;               
string tachchucaidau(string qq){
    string thugon;
    for(int i = 0 ; i < qq.length(); i++){
        if(qq[i] == ' '){
            thugon = thugon + qq[i+1];
        }
    }
    thugon = qq[0]+thugon;
    return thugon; 
} 
// lay so ky tu ten dai nhat nhap tu ban phim
int Spacestring(thongtin_KH KHspace[], int &biendem){
    int Space = (KHspace[0].name).length();
    for(int i = 0; i < biendem; i++){
        if((KHspace[i].name).length() > Space)
            Space = (KHspace[i].name).length();
        }
    return Space;
}
// tach ten de tim kiem
string tachten(string &KH){
	int cnt;
	for (int i = KH.length(); i > 0 ; i--){
		if (KH[i] == ' '){
            cnt = i; 
            break;   
        } 
	}
	return KH.substr((cnt + 1),KH.length());  // tra ve chuoi da duoc cat
}

void tachMS(thongtin_KH KHV[], int index){
    int cnt;
        for(int j = (KHV[index].MS).length(); j >= 0; j-- ){
            if((KHV[index].MS)[j] == 'h'){
                cnt = j;
                KHV[index].time = (KHV[index].MS).substr(0,cnt);
                KHV[index].loaighe = (KHV[index].MS)[(KHV[index].MS).length()- 3];
                KHV[index].soghe = (KHV[index].MS).substr((KHV[index].MS).length()- 2,(KHV[index].MS).length());
            }
        }
} 

void phanloaiKH ( thongtin_KH KH[], int &biendem){
    for(int i = 0; i <= biendem; i++){
       if(KH[i].location.compare(locat_const[0]) == 0){
            KH[i].phanloai = 0;
        }else{
            if(KH[i].location.compare( locat_const[1]) == 0){
                KH[i].phanloai = 1;
            }else {
                if(KH[i].location.compare(locat_const[2]) == 0){
                KH[i].phanloai = 2;  
                }else{ 
                    KH[i].phanloai = -1;
                }
            } 
        }
    }
}

// Xoa du lieu
void delname(int &biendem, thongtin_KH KH[],int index){
        // Khi index o vi tri cuoi
	if(index == (biendem - 1)){
		KH[index].name == "";
        KH[index].location == "";
        KH[index].numberphone == "";
        KH[index].MS = "";
        KH[index].time = "";
        KH[index].loaighe = "";
        KH[index].soghe = "";
        KH[index].day_choose = "";
	}else{   //khi index o dau hoac giua
		for(int i = index; i < biendem - 1 ; i++){
    	    		KH[i] = KH[i + 1];
    		}
	}
        biendem -= 1;
}
int return_p(int  &m ){
    char c;
    while(1){
        if(kbhit()){
            c = getch();
            switch(c){
                case 75:m = 1 ;return m;break; // phim <-

                case 27: m = 0;return m;break; // phim Esc
            }
        }
    }
}

