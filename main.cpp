// -------- KNJIŽNICE --------
// Vključi potrebne knjižnice in svoje razrede (Texti, Monster, Weapon) za igro

// -------- GLOBALNE SPREMENLJIVKE --------
//Nastavi začetne vrednosti za xp, zdravje, denar, lokacijo, orožje itd.
//Shrani originalna besedila v igri

// -------- FUNKCIJE --------

// Funkcija save() - Shrani besedila originalnih lokacij v vektor `texti`

// Funkcija reset() - Ponastavi vse igre vrednosti (xp, health, money, weapon status, itd.)

// Funkcija zacetek() - Prikaže glavni zaslon igre in meni z opcijami: Start, About, Exit

// Funkcija about() - Izpiše opis igre in navodila za igranje

// Funkcija pridobi(int n) - Preverja uporabnikov vnos in vrne veljavno izbiro, če je med 1 in n

// Funkcija vrstica() - Ustvari vrstico z znakom "|" na začetku in koncu ter "-" na sredini

// Funkcija info() - Prikaže informacije o xp, health in money

// Funkcija gumbi(Texti t) - Prikaže možnosti, ki so na voljo igralcu v določeni situaciji

// Funkcija locevanje(string t) - Uredi daljša besedila tako, da se pravilno ločijo po vrsticah

// Funkcija textiz(string t) - Prikaže kratko besedilo z "|" na začetku in koncu

// Funkcija izpis(Texti t) - Prikaže celoten zaslon z navodili, gumbi in trenutnim besedilom

// Funkcija pistole() - Trgovina z orožji; igralec lahko kupi orožje ali zapusti trgovino

// Funkcija sicretshop() - Skrita trgovina, kjer lahko igralec za xp izboljša obrambo ali napad

// Funkcija trgovina() - Omogoča igralcu, da kupi zdravje, gre v trgovino z orožjem ali v skrito trgovino

// Funkcija minigames() - Mini igra, kjer igralec lahko zmaga denar ali izgubi zdravje

// Funkcija napad(int num) - Igralec napada pošast; omogoča bojevanje ali pobeg

// Funkcija forest() - Omogoča izbiro med dvema pošastma v gozdu in napad nanju

// Funkcija cave() - Omogoča izbiro med dvema pošastma v jami in napad nanju

// Funkcija fight() - Omogoča izbiro bojevališča (gozd ali jama)

// Funkcija dragon(int num) - Končna bitka proti zmaju, če ga ubiješ, zmagaš, sicer izgubiš

/* -------- GLAVNI PROGRAM --------
main():
    save() - Shrani originalne tekste
    zacetek() - Prikaže glavni meni
    pridobi(3) - Pridobi uporabnikov vnos za izbiro med Start, About ali Exit

    Če je izbran Start:
        Pokaži meni možnosti v igri, dokler ni igre konec
        izpis(lokacije[tr]) - Izpiše trenutno lokacijo
        pridobi(3) - Pridobi vnos uporabnika glede na izbrane možnosti

        1) trgovina() - Pojdi v trgovino
        2) fight() - Bojuj se
        3) dragon(4) - Bojuj se proti končnemu šefu zmaju
*/

/*----------  KNJIŽNICE ----------*/

// Vključitev potrebnih knjižnic za vnos/izpis, delo z nizovi, vektorji, generatorjem naključnih števil, itd.
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>  
using namespace std;

/*-------- IMPORTANI FILE --------*/

// Vključitev lastnih razredov in definicij za "Texti", "Monster" in "Weapon", ki se uporabljajo v igri.
#include "Texti.cpp"
#include "Text.h"
#include "Monster.h"
#include "Monster.cpp"
#include "Weapon.h"
#include "Weapon.cpp"

/*---- FORWARD DEKLARACIJA FUNK. -----*/
int pridobi(int n); // Uporabljena za about(), potrebna je bila vnaprejšnja deklaracija


/*---- GLOBALNE SPREMELJIVKE -----*/

int xp=100;
int health=100;
int money=50;
int vnum=150;    //maxsimalno število znakov v eni vrstici
int tr=0;       //trenutna lokacija
int tw=0;      //trenutno orožje
int pp=0;     //zmajnša demage
int kk=0;    //doda k napadu
vector<string> texti;//shranjevanje originalnih textov

void save(){ //funkcija ki shrani vse besedila
    for(int i=0;i!=11;i++){
        texti.push_back(lokacije[i].text);
    }
}

void reset(){ //resitira podatke na začetne vrednoste
    xp=0;
    health=100;
    money=50;
    tr=0;
    tw=0;

    for(int i=1;i!=7;i++){
        weapon[i].own=false; //nastavi da ima igralec samo začetni weapon
    }

    for(int i=0;i!=11;i++){
        lokacije[i].text=texti[i]; //iz vektorja texti shrani v texti.text besedila
    }
}

void zacetek(){ //main screen
        cout << "\033[34m";  // Nastavi rdečo barvo

    cout<<"DDDD    RRRR     AAAAA   GGGGG  OOOOO   N   N      FFFFF III GGGGG  H   H TTTTT"<<endl;
    cout<<"D   D   R   R   A     A G       O     O NN  N      F      I  G      H   H   T  "<<endl;
    cout<<"D   D   RRRR    AAAAAAA G  GGG  O     O N N N      FFF    I  G  GGG HHHHH   T  "<<endl;
    cout<<"D   D   R  R    A     A G    G  O     O N  NN      F      I  G    G H   H   T  "<<endl;
    cout<<"DDDD    R   R   A     A  GGGGG   OOOOO  N   N      F     III  GGGGG H   H   T  "<<endl<<endl<<endl;

    cout<<"==============================================================================="<<endl;
    cout<<"                                        MENU                                   "<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"                                   1) START GAME"<<endl;
    cout<<"                                   2) ABOUT GAME"<<endl;
    cout<<"                                   3) EXIT GAME"<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"                     YOU NEED TO TYPE A NUMBER AND PRESS ENTER"<<endl;
    
    
}

void about(){ //about game
    cout<<"Welcome to Dragon Fighter! This is a \"Choose your own adventure\" style game made in C++.\nThroughout the game you will be given prompts and options to progress the game.\nENJOY!"<<endl;
    cout << "Press 1, 2 or 3 to return.\n";
    pridobi(3);
    system("cls"); // clear v cmd-ju
    zacetek();
}

int pridobi(int n) { //pridobi in preveri uporabnikov vnost
    int l;
    bool zas = true;

    do {
        cin >> l;  // Preberi število neposredno z 'cin'
        
        // Preveri, če je vnos pravilen
        if (cin.fail() || l < 1 || l > n) {  
            cin.clear();             // Počisti napako, če je bil vhod neveljaven
            cin.ignore(1000, '\n');   // Ignoriraj napačen vhod
            cout << "You only need to give one number. Options 1, 2 or " << n << "!" << endl;
        } else {
            zas = false;  // Končaj zanko, če je vhod pravilen
        }
    } while (zas);
    
    return l;
}

string vrstica(){ //izdela začetno,umestno ali končno vrstico
    string n="";
    
        n+="|";
        for(int i=0;i!=vnum-2;i++){
            n+="-";
        }
        n+="|\n";
    
    return n;
}

string info(){ //sestavi info del (zgorni del) ki izpiše xp, health in denar
    string x="| Xp:"+to_string(xp);
    string h="| Health:"+to_string(health);
    string m="| Money:"+to_string(money);
    
    string n="";
    n+=x+h+m;
    
    while(n.length()!=vnum-1){
        n+=" ";
    }
    n+="|\n";
    
    return n;
    
}

string gumbi(Texti t){ //izpiše opcije katere imaš in pod katero številko so
    
    string p1=t.btext[0];
    string p2=t.btext[1];
    string p3=t.btext[2];

    string n="|";
    n+=" 1)"+p1;
    n+=" | 2)"+p2;
    n+=" | 3)"+p3;
    
    while(n.length()!=vnum-1){
        n+=" ";
    }
    n+="|\n";
    
    return n;
}

string locevanje(string t) { 
    //dalše besedilo loči tako da na začetku vrstice pred besedilo da "|" in na koncu besedila še doda "|" če besedilo
    //nima več znakov kot je v int vnum. Če ima sortira tako da predstavi odvečne besede v novo vrstico
    string n = "|";
    string x = t;
    string d = "";
    string bes = "";
    
    if(x.length()<vnum-2){ //preveri če je besedilo majnše od vnmu znakov in če je še prostor za | na začetku in koncu
        for(int i=x.length();x.length()!=vnum-2;i++){
            x+=" ";
        }
        
        n+=x+"|\n";
        
        return n;
        
    }
    
   if(x.length()>vnum-2) { //preverja če ima več znakov kot je v pomnilniku vnum. Če je sortira po vrsticah
        for (int i = 0; i != x.length(); i++) {
            if (x[i] != ' ') {
                bes += x[i];
            } else {
                if (d.length() + bes.length() + 1 <= vnum-2) {
                    if (!d.empty()) d += " ";
                    d += bes;
                } else {
                    for(int i=d.length();i!=vnum-2;i++){
                        d+=" ";
                    }
                    n += d + "|\n|";
                    d = bes;
                }
                bes = "";
            }
        }
        if (!bes.empty()) {
            d+=bes;
            for(int i=d.length();i!=vnum-2;i++){
                        d+=" ";
                    }
        }
        n += d + "|\n";
    }else{
        n+=x+"|\n";
    }

    return n;
}

void textiz(string t){
    //funkcija ki kratko besedilo uredi tako da na začetku in na koncu doda |
    string n="";
    string x="|"+t;
    for(int i=x.length();x.length()!=vnum-1;i++){
        x+=" ";
    }

    n+=x+"|\n";
    n+=vrstica();
    cout<< n<<endl;
    
}

void izpis(Texti t){ //funkcija ki sestavi in izpiše navodila in vse potrebne informacije za igranje
    
    string iz="\n";
    iz+=vrstica();
    iz+=info();
    iz+=vrstica();
    iz+=gumbi(t);
    iz+=vrstica();
    iz+=locevanje(t.text);
    iz+=vrstica();

    for(int i=0;i!=30;i++){
        cout<<endl<<endl;
    }

    cout<<iz;

}

void pistole(){ //trgovina za pištole kjer lahko kupiš pištole

    string l="";
    string v="";
    string n="";
    string d="";
    string p="";
    string o="";
    string b="";
    int st;
    do{
    for(int ii=0;ii!=30;ii++){
        l+="\n";
    }
    l+=vrstica();
    l+=info();
    l+=vrstica();
    l+=locevanje("You are in the gun shop. Select a gun you want to buy by typing the number betwen 1 and 7. If you want to leave type 8");
    l+=vrstica();

    for(int i=0;i!=7;i++){
        v="|";
        n=") Weapon: "+weapon[i].name;
        for(int j=n.length();j<26;j++){
            n+=" ";
        }

        d="Attack damage: "+to_string(weapon[i].damage);
        for(int j=d.length();j<20;j++){
            d+=" ";
        }

        p="| Price: "+to_string(weapon[i].price);
        for(int j=p.length();j<14;j++){
            p+=" ";
        }


        v+=to_string(i+1)+n+" | "+d+p + "| ";

        if(weapon[i].own){
            v+="You already own this weapon!";
        }else{
            v+="You don't have this weapon!";
        }

         while(v.length()!=vnum-1){
             v+=" ";
         }
         v+="|\n";
         l+=v;
         l+=vrstica();
    }

    

    l+=b;
    cout<<l;
    b="";
    st=pridobi(8);

    if(st!=8){
        if(weapon[st-1].own==true){
            b+=locevanje("You already own this weapon!");
            b+=vrstica();
        }else{
            if(weapon[st-1].price<=money){
            money-=weapon[st-1].price;
            tw=st-1;
            weapon[st-1].own=true;

            b+=locevanje("Congratulations! You have bought: "+ weapon[st-1].name);
            b+=vrstica();

        }else{
            b+=locevanje("You don't have enough money");
            b+=vrstica();
        }   
        }
        
    }

    for(int i=0;i!=30;i++){
        cout<<endl;
    }
    }while(st!=8);

}

void sicretshop(){ //skrivna trgovina kjer lahko porabiš xp
    bool zas=true;
    int st;
    string b="";
    do{

        izpis(lokacije[12]);
        cout<<b;
        st=pridobi(3);

        if(st==1){
            if(xp>=25){
                pp+=5;
                xp-=25;
                b+=locevanje("You are now going to take "+to_string(pp) +" less damage");
                b+=vrstica();
            }else{
                b+=locevanje("You dont have enough money!");
                b+=vrstica();
            }
        }else if(st==2){
            if(xp>=25){
                kk+=5;
                xp-=25;
                b+=locevanje("You are now going to make "+to_string(kk) +" more damage with every hit!");
                b+=vrstica();
            }else{
                b+=locevanje("You dont have enough money!");
                b+=vrstica();
            }
        }else{
            zas=false;
        }
    
    }while(zas);
}

void trgovina(){ //trgovina kjer lahko kupiš health ali pa greš v trgovino z pištolo. Trgovina še vsebuje skriti dostop do skrite trgovine
    bool zas=true;
    int st;
    string l;
    while(zas){
                izpis(lokacije[2]);
                cout<<l;
                st=pridobi(4);

                if(st==1){
                    if(money<10){
                        l+=locevanje("You don't have enough money!");
                        l+=vrstica();
                    }else{
                        money-=10;
                        health+=10;
                    }
                }

                if(st==2){
                    pistole();
                }

                if(st==3){
                    zas=false;
                }

                if(st==4){
                    sicretshop();
                }
            }
}

void minigames(){ //minigames kjer lahko igralec dobi 10 money ali pa izgubi 10 healtha
    
        srand (time(NULL));
    int r=rand()%100+1;
    
    string op[2]={"even","odd"};
    string wl[2]={"win","lose"};
    
    string izz="";
    izpis(lokacije[10]);
    int num=pridobi(3);
    int n;

    if(num==3){
        return;  
    }else{
        if(num==1){
            if(r%2!=0){
                izz=", which means you "+wl[0];
                n=1;
                money+=10;
            }else{
                izz=", which means you "+wl[1];
                n= 2;
                health-=10;
            }
        }
        if(num==2){
            if(r%2==0){
                izz=", which means you "+wl[0];
                n= 1;
                money+=10;
            }else{
                izz=", which means you "+wl[1];
                n= 2;
                health-=10;
            }
        }
    }
    
    string iz="The number generated was "+to_string(r)+" that is "+op[r%2]+izz;
    lokacije[11].text=iz+". "+lokacije[11].text;
    izpis(lokacije[11]);
    num=pridobi(3);   

}

void napad(int num){
    // funkcija kjer napadaš pošasti
    /*
        pod program dobi številko pošasti. z pomočjo številke dobimovse informacije od pošasti toraj: ime, koliko damaga naredi, koliko ima življenja in koliko
        xp in money dobimo ko jo bomo ubili

        podprogram se lahko konča na 3 različne načine:
        1) Ubijemo pošast (ko jo ubijemo in če podamo 3 pridemo na skriti menu)
        2) Pošast nas ubije
        3) Ne končamo boja in "zbežimo"
    */
    bool zas=true;
    int st;
    int h=monster[num].health;
    string l="| Monster: "+monster[num].name+" | Attack damage: "+to_string(monster[num].attect)+" | Health: ";
    lokacije[6].text+=monster[num].name+".";
    do{
        
        l="| Monster: "+monster[num].name+" | Attack damage: "+to_string(monster[num].attect)+" | Health: ";
        izpis(lokacije[6]);
        l+=to_string(h);
        for(int i=l.length();i!=vnum-1;i++){
            l+=" ";
        }
        l+="|\n"+vrstica();
        cout<<l;
        st=pridobi(3);

        if(st==1){
            h-=weapon[tw].damage;
            h-=kk;

            if(h<=0){
                money+=monster[num].money;
                xp+=monster[num].xp;
                zas=false;
            }else{
                health-=monster[num].attect;
                health+=pp;
                if(health<=0){
                    izpis(lokacije[8]);
                    exit(0);
                }

            }
        }

        if(st==3){
            return;
        }

    }while(zas);

    izpis(lokacije[7]);
    st=pridobi(3);

    if(st==3){
        minigames();
        return;
    }else{
        return;
    }

    cout<<"Lol";
}

void forest(){ //izbiramo mod 2 pošastima kateri bomo bojevali
    int st;
    do{
        izpis(lokacije[4]);
        st=pridobi(3);

        if(st==1){
            napad(0);
            lokacije[6].text="You are fighting a "; // Ponastavitev teksta lokacije
        }
        if(st==2){
            napad(1);
            lokacije[6].text="You are fighting a ";
        }
    }while(st!=3);
}

void cave(){ //izbiramo mod 2 pošastima kateri bomo bojevali
    int st;
    do{
        izpis(lokacije[5]);
        st=pridobi(3);

        if(st==1){
            napad(2);
            lokacije[6].text="You are fighting a ";
        }
        if(st==2){
            napad(3);
            lokacije[6].text="You are fighting a ";
        }
    }while(st!=3);
}

void fight(){ //izberemo kje se bomo bojevali

    int st;
    
    do{

        izpis(lokacije[3]);
        st=pridobi(3);

        if(st==1){
            forest();
        }
        if(st==2){
            cave();
        }

    }while(st!=3);    

}

void dragon(int num){ //zadnja bitka. Če ubijemo zmaja smo končali igro.Če pa ne pa moremo it od začetka
    bool zas=true;
    int st;
    int h=monster[num].health;
    string l="| Monster: "+monster[num].name+" | Attack damage: "+to_string(monster[num].attect)+" | Health: ";
    lokacije[6].text+=monster[num].name+".";
    do{
        
        l="| Monster: "+monster[num].name+" | Attack damage: "+to_string(monster[num].attect)+" | Health: ";
        izpis(lokacije[6]);
        l+=to_string(h);
        for(int i=l.length();i!=vnum-1;i++){
            l+=" ";
        }
        l+="|\n"+vrstica();
        cout<<l;
        st=pridobi(3);

        if(st==1){
            h-=weapon[tw].damage;
            h-=kk;

            if(h<=0){
                money+=monster[num].money;
                xp+=monster[num].xp;
                zas=false;
            }else{
                health-=monster[num].attect;
                health+=pp;
                if(health<=0){
                    izpis(lokacije[8]);
                    exit(0);
                }

            }
        }

        if(st==3){
            return;
        }

    }while(zas);

    izpis(lokacije[9]); // Zmagovalni izpis 
}

int main(){ //main program kjer se vse izvaja

    save();

    int st;
    int running=true;
    bool zas=true;
    bool potek=true;
    do{
        zacetek();
    
        do{
            st=pridobi(3);

            if(st==2){
                about();
            }
            if(st==3){
                return 0;
            }

        }while(st!=1);

        while(running){
            zas=true;
            izpis(lokacije[tr]);
            st=pridobi(3);

            if(st==1){
                trgovina();
            }

            if(st==2){
                fight();
            }

            if(st==3){
                dragon(4); // Final boss
            }

            tr=1;
        }
    }while(potek);
    
}