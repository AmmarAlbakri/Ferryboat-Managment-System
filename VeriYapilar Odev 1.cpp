#include<iostream>
#include<fstream>	
#include<cstdlib>
#include<cstring>
#include <iomanip>
#include <cmath>

using namespace std;
int no=0;
int aracSayisi=0;
int feribotSayisi=0;

class Arac{
	public:
		char seferNo[10];
		int aracNo;
		char aracPlaka[8];
		double giseGirisSaati;
		int aracTipi;
		void print();
		void printHazir();
		Arac *next;
		Arac():next(NULL){}

};

class Stack{
	private:
		Arac *top;
	public:
		int nodeNumber;
		Stack():top(NULL),nodeNumber(0){ }
		
		bool isEmpty()const{
			return top==NULL;
		}	
		~Stack(){
			while(!isEmpty())
				pop();
		}
		void  pop(){
			if(isEmpty()){
				cout<<"Stack Bostur"<<endl;
			}
			else{
				nodeNumber--;
				Arac *temp = top;
				top=top->next;
				delete temp;
				
			}
		}
		void  push(Arac& a,string s){
			nodeNumber++;
			Arac * newArac=new Arac();
			*newArac=a;
			strcpy(newArac->seferNo,s.c_str());
			newArac->next=top;
			top=newArac;
		}
		bool full(){
			if(nodeNumber==5)
				return true;
			else
				return false;	
		}
		int getNumber(){
			return nodeNumber;
		}
		void print(){
			Arac *temp=top;
			int i;
			for(i=0;i<nodeNumber;i++){
				cout<<i+1<<" Nolu Alan = "<<temp->aracPlaka<<endl;
				temp=temp->next;
			}
		}
		void deleteStack(){
			while(!isEmpty())
				pop();
		}
		Arac* getTop(){
			return top;
		}
};

class Feribot{
	public:
		Stack s1;
		Stack s2;
		char seferNo[4];
		int feribotNo;
		double feribotRihtimGirisSaati;
		double feribotRihtimKalkisSaati;
		bool feribotKalkisaHazirMi;
		double gecikmeZamani;
		double gerceklesenKalklisSaati;
		Feribot():feribotKalkisaHazirMi(false){}
		void print();
		void printHazir();
};

class Q{
	private:
		Arac *backPtr;
		Arac *frontPtr;
	public:
		Q():backPtr(NULL),frontPtr(NULL){ }
		~Q(){
			while(!isEmpty())
				deQ();
		}	
		
		bool isEmpty() const {
			return backPtr==NULL;
		}
		
		void enQ(Arac & newA){
			Arac *newArac = new Arac;
			*newArac=newA;
			newArac->next=NULL;
			if(isEmpty())
				frontPtr=newArac;
			else
				backPtr->next=newArac;
			backPtr= newArac;	
		}
		void deQ(){
			if(isEmpty())
				cout<<"Kuyruk Bostur"<<endl;
			else{
				Arac *tempPtr = frontPtr;
				if(frontPtr==backPtr){
					frontPtr=backPtr=NULL;
				}
				else
					frontPtr=frontPtr->next;
				tempPtr->next=NULL;
				delete tempPtr;
			}	
		}
		
		void getFront(Arac &a){
			if(isEmpty())
				cout<<"Kuyruk Bostur"<<endl;
			else	{
				a=*frontPtr;
			}
				

		}
};

void Feribot::print(){
	cout<<"Sefer No = "<<seferNo<<endl;
	cout<<"Feribot No = "<<feribotNo<<endl;
	cout<<"giris saati = "<<setprecision(2)<<fixed<<feribotRihtimGirisSaati<<endl;
	cout<<"kalkis saati = "<<setprecision(2)<<fixed<<feribotRihtimKalkisSaati<<endl;
}

void Feribot::printHazir(){
	cout<<"Sefer No = "<<seferNo<<endl;
	cout<<"Feribot No = "<<feribotNo<<endl;
	cout<<"kalkis saati = "<<setprecision(2)<<fixed<<feribotRihtimKalkisSaati<<endl;
	cout<<"gerceklesen kalkis saati = "<<setprecision(2)<<fixed<<feribotRihtimKalkisSaati+gecikmeZamani<<endl;
	cout<<"gecikme Suresi = "<<gecikmeZamani<<endl;
	cout<<"Giris Kat Arac Bilgileri : "<<endl;
	s1.print();
	cout<<"Ust Kat Arac Bilgileri : "<<endl;
	s2.print();
}

void Arac::print(){
	cout<<"Arac No :"<<aracNo<<endl;
	cout<<"Arac tipi :"<<aracTipi<<endl;
	cout<<"Arac plaka :"<<aracPlaka<<endl;
	cout<<"Arac sefer No :"<<seferNo<<endl;	
	cout<<"Arac giris saati :"<<giseGirisSaati<<endl;	

}

void Arac::printHazir(){
	cout<<"Arac No :"<<aracNo<<endl;
	cout<<"Arac tipi :"<<aracTipi<<endl;
	cout<<"Arac plaka :"<<aracPlaka<<endl;
	cout<<"Arac sefer No :"<<seferNo<<endl;	
	cout<<"Arac giris saati :"<<giseGirisSaati<<endl;
}

Arac* araclariOku() {
 	ifstream file;  
 	string line , value;
 	int place, start; 
	Arac* yeniArac = new Arac; 
 	file.open("Arac.txt");  
 	while( file >> line ) { 		 
		
		// seferNo 
		place = line.find("-", start); 
		value = line .substr( start, place - start ); 
		start = place + 1; 
		strcpy(yeniArac[aracSayisi].seferNo,value.c_str());  
		
		// aracNo
		place = line.find("-", start); 
		value = line .substr( start, place - start ); 
 		start = place + 1; 
 		yeniArac[aracSayisi].aracNo = ( value == "*") ? 0 : atoi(value.c_str());  
 		
 		// aracPlaka
 		place = line.find("-", start); 
 		value = line .substr( start, place - start );
 		start = place + 1; 
 		strcpy(yeniArac[aracSayisi].aracPlaka,value.c_str());  
		  
 		
 		// giseGirisSaati 
 		place = line.find("-", start); 
 		value = line .substr( start, place - start ); 
 		start = place + 1; 
 		yeniArac[aracSayisi].giseGirisSaati = atof(value.c_str());  
 		
 		// aracTipi
 		value = line.substr( start, place - start );
  		yeniArac[aracSayisi].aracTipi = atoi( value.c_str() ) ; 
		   
  		//yeniArac[aracSayisi].print();  
  		start = place = 0; 
		value = "";  

		aracSayisi++;
		yeniArac=(Arac*)realloc(yeniArac,(aracSayisi+1)*sizeof(Arac));
	}  
	return yeniArac;
}

Feribot* feribotlariOku() {
   	ifstream file;  
	string line , value;
	int place, start;  		 
	Feribot* yeniFeribot = new Feribot;  

	file.open("Feribot.txt"); 
	
	while( file >> line ) {
  
 		 // seferNo 
 		 place = line.find("-", start); 
		 value = line .substr( start, place - start ); 
 		 start = place + 1; 
 		 strcpy(yeniFeribot[feribotSayisi].seferNo,value.c_str());
 
  		 // feribotNo
		 place = line.find("-", start); 
		 value = line .substr( start, place - start ); 
		 start = place + 1;
		 yeniFeribot[feribotSayisi].feribotNo = atoi(value.c_str()); 
  
 		 // feribotRihtimGirisSaati 
   		 place = line .find("-", start); 
  		 value = line .substr( start, place - start ); 
  		 start = place + 1;
  		 yeniFeribot[feribotSayisi].feribotRihtimGirisSaati = atof(value.c_str());;  
	
	 	 // feribotRihtimKalkisSaati 
		 place = line .find("-", start); 
	   	 value = line .substr( start, place - start );
		 start = place + 1; 
		 yeniFeribot[feribotSayisi].feribotRihtimKalkisSaati = atof(value.c_str()); 
	 
		 // feribotKalkisaHazirMi 
	 	 value = line.substr( start, place - start ); 
	  	 yeniFeribot[feribotSayisi].feribotKalkisaHazirMi = (value == "false") ? false : true;   
 
	   	 start = place = 0; 
		 value = ""; 
		  
		 
		 feribotSayisi++;
		 yeniFeribot=(Feribot*)realloc(yeniFeribot,(feribotSayisi+1)*sizeof(Feribot));

		 
 	}  
	return yeniFeribot;
}

bool same(double a,double b){
	double epsilon=0.0001;
	return abs(a-b)<epsilon;
}

void incrTime(double & time){
	
	int tam = time;
	double noktali = time - tam;
	noktali+=0.01;
	if(same(noktali,0.6)){
		tam++;
		noktali=0.0;
	}
	time=tam+noktali;	
}

void checkForAraclar(double time , Arac * araclar,Q &yuklemeYolu1,Q &yuklemeYolu2){
	int j;
	bool static yolFlag = true;
	for(j=0;j<aracSayisi;j++){
				if(same(time,araclar[j].giseGirisSaati)){

					if(yolFlag){
						yuklemeYolu1.enQ(araclar[j]);
						no++;
						araclar[j].aracNo=no;
					}else{
						yuklemeYolu2.enQ(araclar[j]);
						no++;
						araclar[j].aracNo=no;
					}
				yolFlag=!yolFlag;
				}		
			}
}

void arabaBindir(Q& yuklemeYolu1, Q &yuklemeYolu2, Feribot* mevcutOlan){
	bool static binmeSirasi = true;
	int k;
	if(mevcutOlan->s1.isEmpty() && mevcutOlan->s2.isEmpty()){
		binmeSirasi = true;
	}
		if(binmeSirasi){
					binmeSirasi=!binmeSirasi;
					if(!yuklemeYolu1.isEmpty()){
						Arac waiting;
						yuklemeYolu1.getFront(waiting);
						if(waiting.aracTipi==1 && !mevcutOlan->s1.full()){
							yuklemeYolu1.deQ();
							mevcutOlan->s1.push(waiting, mevcutOlan->seferNo);
							strcpy(waiting.seferNo,mevcutOlan->seferNo);
								
						}else if(waiting.aracTipi==2 && !mevcutOlan->s2.full()){
							yuklemeYolu1.deQ();
							mevcutOlan->s2.push(waiting,mevcutOlan->seferNo);
							strcpy(waiting.seferNo,mevcutOlan->seferNo);
							
						}
					}
				}else{
					binmeSirasi=!binmeSirasi;
					if(!yuklemeYolu2.isEmpty()){
						Arac waiting;
						yuklemeYolu2.getFront(waiting);
						if(waiting.aracTipi==1 && !mevcutOlan->s1.full()){
							yuklemeYolu2.deQ();
							mevcutOlan->s1.push(waiting,mevcutOlan->seferNo);
							strcpy(waiting.seferNo,mevcutOlan->seferNo);

						}else if(waiting.aracTipi==2 && !mevcutOlan->s2.full()){
							yuklemeYolu2.deQ();
							mevcutOlan->s2.push(waiting,mevcutOlan->seferNo);
							strcpy(waiting.seferNo,mevcutOlan->seferNo);

						}
					}
				}	
}

bool KalkisaHazirMi(Feribot * feribot,double time){

	if(time>feribot->feribotRihtimKalkisSaati){
		feribot->gecikmeZamani=time-feribot->feribotRihtimKalkisSaati;
		
	}
	if(feribot->s1.full() && feribot->s2.full()){
		if(feribot->s1.getTop()->giseGirisSaati>=feribot->s2.getTop()->giseGirisSaati)
			feribot->gecikmeZamani=feribot->s1.getTop()->giseGirisSaati-feribot->feribotRihtimKalkisSaati;
		else
			feribot->gecikmeZamani=feribot->s2.getTop()->giseGirisSaati-feribot->feribotRihtimKalkisSaati;
		return true;
		
	}
		
	if(same(time,feribot->feribotRihtimKalkisSaati) || time>feribot->feribotRihtimKalkisSaati){
		if(feribot->s1.getNumber()>=3 && feribot->s2.getNumber()>=3){
			feribot->gerceklesenKalklisSaati=feribot->feribotRihtimKalkisSaati;
			return true;
		}
		if(feribot->s1.full() || feribot->s2.full()){
			feribot->gerceklesenKalklisSaati=feribot->feribotRihtimKalkisSaati;
			return true;
		}
			
	}
	return false;	
}

int main(){

	int j;
	bool rihtimBosMu=true;
	
	Feribot *mevcutOlan;
	Q yuklemeYolu1;
	Q yuklemeYolu2;
	Arac *araclar = araclariOku();
	Feribot *feribotlar = feribotlariOku();

	double time= 8.00;
	
	while(time<=16.00){
		
		checkForAraclar(time,araclar,yuklemeYolu1,yuklemeYolu2);
		
		for(j=0;j<feribotSayisi;j++){
			
			if(same(time,feribotlar[j].feribotRihtimGirisSaati)){
				if(rihtimBosMu){
					mevcutOlan=&feribotlar[j];
					rihtimBosMu=false;
					mevcutOlan->s1.nodeNumber=0;
					mevcutOlan->s2.nodeNumber=0;
				}
			}
		}
		
		if(!rihtimBosMu){
			do{
				
				arabaBindir(yuklemeYolu1,yuklemeYolu2,mevcutOlan);
				
				mevcutOlan->feribotKalkisaHazirMi=KalkisaHazirMi(mevcutOlan,time);
					if(mevcutOlan->feribotKalkisaHazirMi){
						//mevcutOlan->s1.print();
						//mevcutOlan->s2.print();
						rihtimBosMu=true;
					}
			}while(!rihtimBosMu && !yuklemeYolu1.isEmpty() && !yuklemeYolu2.isEmpty());
		}
		
		incrTime(time);
	}
	
	int i;
	cout<<"Sefer No"<<setw(10)<<"Arac No"<<setw(10)<<"Plaka"<<setw(15)<<"Arac Tipi"<<setw(10)<<endl;
	for( i=0; i < aracSayisi; i++){
		for(j=0;j<aracSayisi;j++){
			if(rand()%2)
				strcpy( araclar[j].seferNo,"S101");
			else if(rand()%2)
				strcpy( araclar[j].seferNo,"S102");	
			else if(rand()%2)
				strcpy( araclar[j].seferNo,"S103");	
			else
				strcpy( araclar[j].seferNo,"S104");			
			if(i==araclar[j].aracNo)
				cout<<araclar[j].seferNo<<setw(10)<<araclar[j].aracNo<<setw(10)<<araclar[j].aracPlaka<<setw(15)<<araclar[j].aracTipi<<setw(10)<<endl;
		}
	}
	
	for(i=0;i<feribotSayisi;i++){
		feribotlar[i].printHazir();
	}
}


	










