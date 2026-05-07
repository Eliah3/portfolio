#include <iostream>
#include <windows.h>
#include <string>

class Spielbrett{
public:
    char spielbrett[3][3];


public:
    void spielbrettZuruecksetzen(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                spielbrett[i][j] = '0';
            }
        }
    }    
    void gibSpielbrettAus(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                std::cout << spielbrett[i][j];
            }
            std::cout << " " << std::endl;
        }
    }
    
    bool endbedingungen(){
        int anz = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if (spielbrett[i][j] == 'x' || spielbrett[i][j] == 'o'){
                    anz++;
                }
            }
        }
        
        if(anz == 9){
            return true;
        }

        bool checkeDreiInEinerReihe = false;
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if (spielbrett[i][j] == 'x' && spielbrett[i-1][j-1] == 'x' && spielbrett[i-2][j-2] == 'x' || spielbrett[i][j] == 'o'&& spielbrett[i-1][j-1] == 'o' && spielbrett[i-2][j-2] == 'o'){
                    checkeDreiInEinerReihe = true;
                }
            }
        }

       
        if(spielbrett[0][0] == 'x' && spielbrett[1][1] == 'x' && spielbrett[2][2] == 'x' || spielbrett[0][0] == 'o'&& spielbrett[1][1] == 'o' && spielbrett[2][2] == 'o'){
            checkeDreiInEinerReihe = true;
        }
        if(spielbrett[0][2] == 'x' && spielbrett[1][1] == 'x' && spielbrett[2][0] == 'x' || spielbrett[0][2] == 'o'&& spielbrett[1][1] == 'o' && spielbrett[2][0] == 'o'){
            checkeDreiInEinerReihe = true;
        }

        std::cout << "spiel vorbei" << std::endl;
        return checkeDreiInEinerReihe;
    }



};
class Spieler{
public:
    char spielertyp;

public:

    Spieler(char pSpielertyp){
        spielertyp = pSpielertyp;

    }
    void setzeMarkierung(int spalte, int reihe, Spielbrett &spielbrett){
        spielbrett.spielbrett[reihe-1][spalte-1] = spielertyp;
    }

};


int main(){
    Spielbrett spielbrett1;
    Spieler spieler1{'x'};
    Spieler spieler2{'o'};

    spielbrett1.spielbrettZuruecksetzen();
    int eingabe1;
    int eingabe2;
    
    bool vorbei = false;
    while(vorbei == false)   {
        std::cout << "Spieler 1 ist an der Reihe. Spalte: ";
        std::cin >> eingabe1;
        std::cout << " " << std::endl;
        std::cout << "Spieler 1 ist an der Reihe. Reihe: ";
        std::cin >> eingabe2;
        spieler1.setzeMarkierung(eingabe1, eingabe2, spielbrett1);
        spielbrett1.gibSpielbrettAus();

        std::cout << "Spieler 2 ist an der Reihe. Spalte: ";
        std::cin >> eingabe1;
        std::cout << " " << std::endl;
        std::cout << "Spieler 2 ist an der Reihe. Reihe: ";
        std::cin >> eingabe2;
        spieler2.setzeMarkierung(eingabe1, eingabe2, spielbrett1);
        spielbrett1.gibSpielbrettAus();


        if(spielbrett1.endbedingungen()==true){
            vorbei = true;
        }
    }   


}
