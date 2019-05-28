// 1In2Sklop.cpp : Defines the entry point for the console application.
//

/* Karmen Unuk
OA_N0000819_sklop1&sklop2: Naloge s polji & Deli in vladaj */


#include "stdafx.h"
#include <iostream>
#include<vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class CPolje
{
public:
	CPolje(int aN);   // ne rabimo pisati void
	~CPolje(void);
	int vrniVelikost();
	void dolociVelikost(int aN);
	int vrniElement(int aIdx);
	void dolociElement(int aIdx, int aValue);
	bool jeEnak(int aIdx, int aValue);
	void napolniNakljucno(int aN);
	void napolniNakljucno(int aLow, int aHigh);
	void napolniLinearno();
	void napolniLinearno(int aLow, int aHigh);
	void napolniLinearnoBrezNicle(int aLow, int aHigh);
	bool jeUrejeno();
	void zamenjaj(int aI, int aJ);
	void izpis();
	void premesaj();
	int stRazlicnih();
	void zamenjajPredpono(int aN);
	void obrni(int aI, int aJ);
	void urediP();
	CPolje*presek(CPolje*polje);
	void odstraniPoljubenElement();
	int zbrisanElement1();
	int zbrisanElement2();
	void PokvariPolje();
	bool Pokvarjen(int aI);
	void ObrniPokvarjen();

	//DELI IN VLADAJ
	int bisekcija(int aX);
	int bisekcija(int aX, int aL, int aD);
	int bisekcijaDrugace(int aX);
	int bisekcijaDrugace1(int aX, int aL, int aD);
	void zlij(int aL, int aS, int aD);
	void urediZZlivanjem();
	void urediZZlivanjem(int aL, int aD);
	void hitroUredi(int aL, int aD);
	void hitroUredi1(int aL, int aD);
	int deli(int aL, int aD);
	int trisekcija(int aL, int aD, int aX);
	int vecinski(int dno, int vrh);
	int stPonovitev(int k, int dno, int vrh);
	void Mehurcki(int dno, int vrh);
	void HitroUrediInMehurcki(int dno, int vrh);
	int Mediana(int dno, int vrh);
	void HitroUrediMediana(int dno, int vrh);
	void Deli1(int dno, int vrh);
	void Premesaj(int aL, int aD);
	int deli1(int aL, int aD);
	
private:
	int *podatki;
	int velikost;
	bool jeElement(vector<int> aV, int aX);
	int *novo;
};

CPolje::CPolje(int aN)
{
	podatki = new int[aN];
	velikost=aN;
    srand(time(NULL));
}

CPolje::~CPolje(void)
{
	delete[] podatki;
}

int CPolje::vrniVelikost(){

	return velikost;
}

void CPolje::dolociVelikost(int aN){
	if(aN<=0)
		return;

	if(aN>vrniVelikost()){

		int *polje2=new int[aN];
		for(int i=0; i<vrniVelikost(); i++){
		
			polje2[i]=podatki[i];
		}
		delete[] podatki;
		velikost=aN;
		podatki=polje2;
	}else if(aN<velikost){
		int *polje2=new int[aN];
		for(int i=0; i<aN; i++){
		
			polje2[i]=podatki[i];
		}
		delete[] podatki;
		velikost=aN;
		podatki=polje2;
	}
}

int CPolje::vrniElement(int aIdx){
	if(aIdx<vrniVelikost() && aIdx>=0)
		return podatki[aIdx];
	else
		throw "ERR_NO_SUCH_ELEMENT";
}

void CPolje::dolociElement(int aIdx, int aValue){
	if(aIdx<vrniVelikost() && aIdx>=0){
		podatki[aIdx]=aValue;
	}else
		throw "ERR_NO_SUCH_ELEMENT";
}

bool CPolje::jeEnak(int aIdx, int aValue){
	if(aIdx<vrniVelikost() && aIdx>=0){
		if(podatki[aIdx]==aValue)
			return true;
		return false;
	}else
		throw "ERR_NO_SUCH_ELEMENT";
}

void CPolje::napolniNakljucno(int aN){
	for(int i=0; i<vrniVelikost(); i++){
		podatki [i]=rand()%(aN+1);
	}
}

void CPolje::napolniNakljucno(int aLow, int aHigh){
	if(aLow>aHigh){
		int a=aLow;
		aLow=aHigh;
		aHigh=a;
	}
	for(int i=0; i<vrniVelikost(); i++){
		podatki [i]=rand()%(aHigh-aLow+1)+aLow;
	}
}

void CPolje::napolniLinearno(){
	for(int i=0; i<vrniVelikost(); i++){
		podatki[i]=i+1;
	}
}

void CPolje::napolniLinearno(int aLow, int aHigh){
	for(int i=0; i<vrniVelikost(); i++){
		if(aLow+i<=aHigh)
			podatki[i]=aLow+i;
		else
			podatki[i]=aHigh;
	}
}

void CPolje::napolniLinearnoBrezNicle(int aLow, int aHigh){
	for(int i=0; i<vrniVelikost(); i++){
		
		if(aLow+i<=aHigh){
			if(aLow+i==0){
				podatki[i]=aLow+i+1;
				aLow++;
			}
			else
				podatki[i]=aLow+i;
		}
		else
			podatki[i]=aHigh;
	}
}

bool CPolje::jeUrejeno(){
	for(int i=0; i<vrniVelikost()-1; i++){
		if(podatki[i]>podatki[i+1])
			return false;

	}
	return true;
}

void CPolje::zamenjaj(int aI, int aJ){
	if((aI<vrniVelikost() && aI>=0) && (aJ<vrniVelikost() && aJ>=0)){
		int a=podatki[aI];
		podatki[aI]=podatki[aJ];
		podatki[aJ]=a;
	}else
		throw "Tak element ne obstaja!";
}



void CPolje::izpis(){
	for(int i=0; i<vrniVelikost(); i++){
		cout<<podatki[i]<<" ";
	}
}

void CPolje::premesaj(){
	for(int i=0; i<vrniVelikost()-1; i++){
		int j=rand()%(vrniVelikost()-i-1)+i+1;
		zamenjaj(i,j);
	}
}

int CPolje::stRazlicnih(){
	
	if(jeUrejeno()){
		int stevec=1;
		for(int i=0; i<vrniVelikost()-1; i++){
			if(podatki[i]!=podatki[i+1])
				stevec++;
		}
		return stevec;

	}else{
		vector<int> vektor;
		int stevec=0;
		vektor.push_back(podatki[0]);
		for (int i=1;i<vrniVelikost();i++){
			for (int j=0;j<vektor.size();j++){
			if (podatki[i]==vektor[j])
				stevec++;
				
			}
			if(stevec==0)
				vektor.push_back(podatki[i]);
		}
		return vektor.size();
	}

	/*Druga možnost (tak bi Taranenko naredo)

	for(int i=0; i<vrniVelikost(); i++){
		if(jeElement(vektor, podatki[i])==false)
			vektor.push_back(podatki[i]);
	}
	return vektor.size();
	*/
	
}

bool CPolje::jeElement(vector<int> aV, int aX){  //Lahko bi uporabili pri zgornji funkciji
	for(int i=0; i< aV.size(); i++)
		if(aV[i]==aX)
			return true;
	
	return false;
}


void CPolje::obrni(int aI, int aJ) {
	for(int i=0; i<(aJ-aI+1)/2; i++)
		zamenjaj(aI+i, aJ-i);
}


void CPolje::zamenjajPredpono(int aN) {
	obrni(0, velikost-1);
	obrni(0, velikost-aN-1);
	obrni(velikost-aN, velikost-1);
}

void CPolje::urediP() {
	int j = 0;
	while(j < velikost){
		int i = velikost-1;
		while(i > j){
			if(podatki[i] < podatki[i-1]){
				int aK = podatki[i];
				podatki[i]= podatki[i-1];
				podatki[i-1] = aK;
			}
			i--;
		}
		j++;
	}
}

CPolje* CPolje:: presek(CPolje * polje)	{
	int k = 0;
	int t = 0;
	if(velikost <= polje->vrniVelikost()){
		CPolje * PresekP = new CPolje(velikost); 
		for(int i = 0; i < polje->vrniVelikost()-1; i++){
			if(podatki[k] == polje->vrniElement(i)){
				PresekP->dolociElement(t, polje->vrniElement(i));
				k++;
				t++;
				if(t == velikost){
					break;
				}
			}else{
				if(podatki[k] < polje->vrniElement(i)){
					i--;
					k++;
				}
			}
		}
		if(t != 0){
			PresekP->dolociVelikost(t);
			return PresekP;
		}else{
			throw "Presek je prazen!";
		}
	}else{
		CPolje * PresekP = new CPolje(polje->vrniVelikost());
		for(int j = 0; j< velikost-1; j++){
			if(podatki[j] == polje->vrniElement(k)){
				PresekP->dolociElement(t, podatki[j]);
				k++;
				t++;
				if(t == velikost){
					break;
				}
			}else{
				if(podatki[j] < polje->vrniElement(k)){
					j--;
					k++;
				}
			}
		}
		if(t != 0){
			PresekP->dolociVelikost(t);
			return PresekP;
		}else{
			throw "Presek je prazen!";
		}
	}
}

void CPolje:: odstraniPoljubenElement()
{
	premesaj();
	cout << "Polje po premesanju vrstnega reda: ";
	izpis();
	cout << endl;
	int aK = rand()%(velikost-1);
	podatki[aK-1] = 0;
}

int CPolje:: zbrisanElement1()
{
	int* p = new int[velikost];
	int aE;
	for(int j = 0; j< velikost; j++){
		aE = podatki[j];
		if(aE != 0){
			p[aE-1] = aE;
		}
	}
	int aT = 0;
	for(int k = 0; k < velikost; k++){
		aT = k+1;
		if(p[k] != aT){
			break;
		}else{
			aT = 0;
			continue;
		}
	}
	return aT;
}

int CPolje:: zbrisanElement2()			//s pomoèjo vsote prvih n števil:  (n*(n+1))/2
{
	int aV = 0;
	for(int i = 0; i< velikost-1; i++){
		aV =+podatki[i];
	}
	int aR = (velikost*(velikost+1))/2 - aV;
	return aR;
}

void CPolje:: PokvariPolje()
{
	int aK = rand()%(velikost-1);
	int aZ;
	for(int i = 0; i< aK; i++){
		aZ = rand()%(velikost-1);
		podatki[aZ] = -1;
	}
	cout << "'Pokvarjeno' polje: ";
	izpis();
	cout << endl;
}
bool CPolje:: Pokvarjen(int aI)		 
{								
	if(podatki[aI] == -1)
		return true;
	else
		return false;
}

void CPolje:: ObrniPokvarjen()
{
	int j = velikost-1;
	for(int i = 0; i<(velikost-1)/2; i++){
		if((Pokvarjen(i) == false)&&(Pokvarjen(j) == false)){
			zamenjaj(i, j);
			j--;
		}else{
			if((Pokvarjen(i) == false)&&(Pokvarjen(j) == true)){
				i--;
				j--;
			}else{
				if((Pokvarjen(i) == true)&&(Pokvarjen(j) == true)){
					j--;
				}
			}
		}
	}
}


int CPolje::bisekcija(int aX) {
	return bisekcija(aX, 0, vrniVelikost()-1);
}


int CPolje::bisekcija(int aX, int aL, int aD) {        // PROSTORSKA ZAHTEVNOST
	if (aL<=aD) {                                      // F(n)=1*F(n/2)+1
		int s=(aL+aD)/2;
		if(podatki[s]==aX)
			return s;
		if(podatki[s]>aX)
			return bisekcija(aX, aL, s-1);
		else
			return bisekcija(aX, s+1, aD);
	}
	else
		return -1;
}

int CPolje::bisekcijaDrugace(int aX)  //išèemo aX
{
	return bisekcijaDrugace1(aX, 0, velikost-1);
}

int CPolje::bisekcijaDrugace1(int aX, int aL, int aD)  //namesto da javi -1 ker ga ne najde, vrnemo kje bi moral stati
{
	int s=(aL+aD)/2;
	if (aL<=aD)
	{
		if (podatki[s]==aX)
		{
			return s+1;  //ker od 0 naprej stejemo
		}
		if (podatki[s]>aX)
			return bisekcijaDrugace1(aX, aL, s-1);
		else
			return bisekcijaDrugace1(aX, s+1, aD);

	}
	else
	{
		return s+1;  //vrnemo stevilo, kjer bi aX moram stati - to je kar s, saj smo se do tja premaknili, vendar ne nasli
	}
}


void CPolje::zlij(int aL, int aS, int aD) {
	int l=aL;
	int d=aS+1;
	int i=aL;
	while(l<aS && d<=aD) {
		if(podatki[l]<podatki[d]) {
			novo[i]=podatki[l];
			l++;
		} else {
			novo[i]=podatki[d];
			d++;
		}
		i++;
	}
	if(l>=aS) {
		for(int j=d; j<aD; j++) {
			novo[i]=podatki[j];
			i++;
		}
	} else {
		for(int j=l; j<aS; j++) {
			novo[i]=podatki[j];
			i++;
		}
	}
	for(int i=aL; i<=aD; i++)
		podatki[i]=novo[i];
}


void CPolje::urediZZlivanjem() {
	novo=new int[vrniVelikost()];
	urediZZlivanjem(0, vrniVelikost()-1);
}


void CPolje::urediZZlivanjem(int aL, int aD) {
	if(aL<aD) {
		int s=(aL+aD)/2;
		urediZZlivanjem(aL, s-1);
		urediZZlivanjem(s, aD);
		zlij(aL, s, aD);
	}
}

void CPolje::Premesaj(int aL, int aD)
{
	for (int i=aL; i<=aD; i++)
	{
		int j=rand()%(aD-aL+1)+aL;
		zamenjaj(i,j);
	}
}

void CPolje::hitroUredi(int aL, int aD) {
	if(aL<aD) {
		Premesaj(aL, aD);
		int s=deli(aL, aD);
		hitroUredi(aL, s-1);
		hitroUredi(s+1, aD);
	}
}


int CPolje::deli(int aL, int aD) {
	int delilni=podatki[aL];
	int l=aL;
	int d=aD;
	while(true) {
		while(l<aD && podatki[l]<=delilni)
			l++;
		while(d>aL && podatki[d]>=delilni)
			d--;
		if(l<d)
			zamenjaj(l, d);
		else
			break;
	}
	if (podatki[d]<podatki[aL])
	    zamenjaj(aL, d);
	return d;
}

void CPolje::hitroUredi1(int aL, int aD)
{
	if (aL<aD)
	{
		int s=deli1(aL, aD);
		hitroUredi1(aL, s-1);
		hitroUredi1(s+1, aD);
	}
}

int CPolje::deli1(int aL, int aD)
{
	int l=aL;
	int d=aD;
	int delilni=podatki[(aL+aD)/2];

	while (true)
	{
		while ((l<aD) && (podatki[l]<=delilni))
			l++;
		while ((d>aL) && (podatki[d]>=delilni))
			d--;

		if (l<d)
			zamenjaj(l,d);
		else
			break;

	}
	if (podatki[d]<podatki[aL])
		zamenjaj(d, aL);

	return d;
}

int CPolje:: trisekcija(int aL, int aD, int aX)
{
	if(this->jeUrejeno()){	
			int res;
		if(aD - aL < 2){
			if(podatki[aL] == aX)
				res = aL;
			else{
				if(podatki[aD] == aX)
					res = aD;
				else
					res = -1;
			}
		}else{
				int n = aD - aL + 1;
				int d = n /3;
				int dv = 2*d;
					if((aX >= podatki[aL])&&(aX <= podatki[aL+d])){
						aD = aL + d;
						res = this->trisekcija(aL, aD, aX);
					}else{
						if((aX >= podatki[aL+d+1])&& (aX <= podatki[aL + dv])){
							aL = aL + d + 1;
							aD = aL + dv;
							res = this-> trisekcija(aL, aD , aX);
						}else{
							aL = aL + dv +1;
							res = this->trisekcija(aL, aD, aX);
						}
					}
		}
		return res;
	}else{
	return -1;
	}
}

int CPolje::vecinski(int dno, int vrh) {
	if(dno==vrh) {
		return podatki[dno];
	} else {
		int s=(dno+vrh)/2;
		int K1=vecinski(dno, s);
		int K2=vecinski(s+1, vrh);
		if(K1==-1 && K2==-1)
			return -1;
		else if(K2==-1) {
			int x=stPonovitev(K1, dno, vrh);
			if(x>(dno+vrh)/2)
				return K1;
			else
				return -1;
		}else if(K1==-1) {
			int y=stPonovitev(K2, dno, vrh);
			if(y>(dno+vrh)/2)
				return K2;
			else
				return -1;
		} else {
			int x=stPonovitev(K1, dno, vrh);
			int y=stPonovitev(K2, dno, vrh);
			if(x>(dno+vrh)/2)
				return K1;
			else if (y>(dno+vrh)/2)
				return K2;
			else
				return -1;
		}
	}
}

int CPolje::stPonovitev(int k, int dno, int vrh) {
	int j=0;
	for(int i=dno; i<=vrh; i++) {
		if(podatki[i]==k)
			j++;
	}
	return j;
}


void CPolje:: Mehurcki(int dno, int vrh)
{
	int j = dno;
	while(j < vrh){
		int i = vrh-1;
		while(i > j){
			if(podatki[i] < podatki[i-1]){
				int aK = podatki[i];
				podatki[i]= podatki[i-1];
				podatki[i-1] = aK;
			}
			i--;
		}
		j++;
	}
	izpis();
	cout << endl;
}
void CPolje:: HitroUrediInMehurcki(int dno, int vrh)
{
	if(vrh-dno <= 7){
		Mehurcki(dno, vrh);
	}else{
		hitroUredi(dno, vrh);
	}
}

int CPolje:: Mediana(int dno, int vrh)
{
	int d = (dno+vrh)/2;
	int sredina = d;
	int levi = dno;
	int desni = vrh;

	if(podatki[sredina] < podatki[levi])
		zamenjaj(levi, sredina);
	if(podatki[levi] > podatki[desni])
		zamenjaj(levi, desni);
	if(podatki[sredina] > podatki[desni])
		swap(sredina, desni);
	return desni-1;
}


void CPolje:: HitroUrediMediana(int dno, int vrh)
{
	if((dno<vrh)&&(dno >= 0)&&(vrh >= 0)){
		int d = deli(dno+1, vrh-1);
		HitroUrediMediana(dno, d-1);
		HitroUrediMediana(d+1, vrh);
	}
}

void CPolje:: Deli1(int dno, int vrh)
{
	int delilni = Mediana(dno, vrh);
	int levi = dno;
	int desni = vrh;
	while(true){
		while(podatki[levi] <= delilni){
			if(levi == vrh){
				break;
			}
			levi++;
		}
		while(podatki[desni] >= delilni){
			if(desni == dno){
				break;
			}
			desni--;
		}
		if(levi < desni){
			zamenjaj(levi,desni);
		}else{
			break;
		}
	}
	
		zamenjaj(levi, delilni);
		Deli1(dno, levi-1);
		Deli1(levi+1, vrh);
}




int _tmain(int argc, _TCHAR* argv[])
{
	CPolje p(10);
	p.napolniLinearno();
	p.izpis();
	cout<<endl;

	p.obrni(0,9);
	cout<<"Obrnjeno polje: ";
	p.izpis();
	cout<<endl;

	p.premesaj();
	cout<<"Premesano polje: ";
	p.izpis();
	cout<<endl;
	cout<<"Stevilo razlicnih elementov: "<<p.stRazlicnih();
	cout<<endl;

	p.napolniLinearno(1,8);
	cout<<"Linearno napolnjeno polje med 1 in 8: ";
	p.izpis();
	cout<<endl;

	int a=p.stRazlicnih();
	cout<<"Stevilo razlicnih elementov: "<<a;
	cout<<endl;
	   
	p.zamenjajPredpono(3);
	cout<<"Zamenjana predpona in pripona: ";
	p.izpis();
	cout<<endl;

	CPolje p2(8);
	p2.napolniLinearno();
	cout << "Polje pred odstranitvijo poljubnega elementa: ";
	p2.izpis();
	cout << endl;
	p2.odstraniPoljubenElement();
	cout << "Polje po odstranitvi poljubnega elementa: ";
	p2.izpis();
	cout << endl;
	cout << "Odstranjen element: ";
	int Odst = p2.zbrisanElement1();
	if(Odst == 0)
		cout <<" Napaka! Noben ni bil odstranjen! " << endl;
	else
		cout << Odst << endl;

	CPolje pokvarjen(8);
	pokvarjen.napolniLinearno();
	pokvarjen.PokvariPolje();
	pokvarjen.ObrniPokvarjen();
	pokvarjen.izpis();
	cout << endl;
	bool po = pokvarjen.Pokvarjen(1);
	if(po == true){
		cout << "Element na 2. mestu je pokvarjen!";
	}else{
		cout << "Element na 2. mestu ni pokvarjen!";
	}
	cout<<endl<<endl;
	cout<<"DELI IN VLADAJ"<<endl<<endl;

	CPolje bis(10);
	bis.napolniLinearno();
	bis.izpis();
	cout<<endl;
	int e;
	cout<<"Kateri element se naj poisce v polju?  ";
	cin>>e;
	cout<<"BISEKCIJA - element se nahaja na indeksu  ";
	int r=bis.bisekcija(e, 0, 9);
	cout<<r<<endl;

	cout<<"Poljubno polje:  ";
	CPolje p3(10);
	p3.napolniNakljucno(6);
	p3.izpis();
	cout<<endl;
	
	cout<<"TRISEKCIJA "<<endl;
	p3.urediP();
	cout<<"Urejeno polje:  ";
	p3.izpis();
	cout<<endl;
	int tris=p3.trisekcija(0, p3.vrniVelikost(), e);
	cout<<"Element se nahaja na indeksu:  "<<tris<<endl;

	CPolje* to=new CPolje(10);

	to->napolniNakljucno(2,20);
	to->izpis();
	cout << endl;
	cout << "HITRO UREJANJE: " << endl;
	to->hitroUredi(0,9);
	to->izpis();
	cout << endl;
	to->hitroUredi1(0,9);
	to->izpis();
	cout << endl;

	cin.ignore();
	cin.get();
	
	return 0;
}