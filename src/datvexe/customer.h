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
