#include <iostream>

using namespace std;

#include "C_Partie.h"

C_Partie::C_Partie()
{
    Vide= 0;
    Interdit= 99;

    PionBlanc = 11;
    CavalierBlanc = 12;
    FouBlanc = 13;
    TourBlanc = 14;
    DameBlanc =15;
    RoiBlanc =16;

    PionNoir = 1;
    CavalierNoir = 2;
    FouNoir = 3;
    TourNoir = 4;
    DameNoir =5;
    RoiNoir =6;

    Init();
}

//-----------------------------------------------------------------------------------
void C_Partie::Init()
{
    SetPiece();
//-------------------------------------------

    Tour = 0;
    if (Tour == 0)
    {
        MaCouleur = 0; //0 = Blanc
        cout<<"Au tour des blancs de jouer"<<endl;


    }

    if(Tour == 1)
    {
        MaCouleur = 1; //1 = Noir
        cout<<"Au tour des noirs de jouer"<<endl;

    }

}
//-----------------------------------------------------------------------------------
void C_Partie::SetPiece()
{
    int x;
    int y;


    // boucle tout vider
    for (x=1;x<9;x++)
    {
         for(y=3;y<7;y++)
        {
            Plateau[x][y] = Vide;
        }
    }


        y = 0;
        //boucle interdit
         for (x=0;x<9;x++)
        {

                Plateau[x][y] = Interdit;

        }

        x=0;
         for (y=0;y<9;y++)
        {

                Plateau[x][y] = Interdit;

        }



    Plateau[1][8] = TourBlanc;
    Plateau[2][8] = CavalierBlanc;
    Plateau[3][8] = FouBlanc;
    Plateau[4][8] = DameBlanc;
    Plateau[5][8] = RoiBlanc;
    Plateau[6][8] = FouBlanc;
    Plateau[7][8] = CavalierBlanc;
    Plateau[8][8] = TourBlanc;

    Plateau[1][7] = PionBlanc;
    Plateau[2][7] = PionBlanc;
    Plateau[3][7] = PionBlanc;
    Plateau[4][7] = PionBlanc;
    Plateau[5][7] = PionBlanc;
    Plateau[6][7] = PionBlanc;
    Plateau[7][7] = PionBlanc;
    Plateau[8][7] = PionBlanc;

//-------------------------------------------
    Plateau[1][1] = TourNoir;
    Plateau[2][1] = CavalierNoir;
    Plateau[3][1] = FouNoir;
    Plateau[4][1] = DameNoir;
    Plateau[5][1] = RoiNoir;
    Plateau[6][1] = FouNoir;
    Plateau[7][1] = CavalierNoir;
    Plateau[8][1] = TourNoir;

    Plateau[1][2] = PionNoir;
    Plateau[2][2] = PionNoir;
    Plateau[3][2] = PionNoir;
    Plateau[4][2] = PionNoir;
    Plateau[5][2] = PionNoir;
    Plateau[6][2] = PionNoir;
    Plateau[7][2] = PionNoir;
    Plateau[8][2] = PionNoir;

}
//-----------------------------------------------------------------------------------
void C_Partie::Deplacer()
{
   // XDepart =0 ,  YDepart =1 ,  XArriver =2 ,  YArriver =3
    Demander();
    int stockage; //utiliser pour le roque ps:fonctionne pas a 100%

    if (Verification()) {
        stockage = Plateau[XArriver][YArriver];

        Plateau[XArriver][YArriver] = Plateau[XDepart][YDepart];

        Plateau[XDepart][YDepart] = stockage;

        /*
        Plateau[XArriver][YArriver] = Plateau[XDepart][YDepart] ;
        Plateau[XDepart][YDepart] = 0;
        */
    }
}
//-----------------------------------------------------------------------------------
void C_Partie::Demander() //paramètre t = tabCordonnees
{
    std::cin >> XDepart >> YDepart >> XArriver >> YArriver;
}

//-----------------------------------------------------------------------------------
void C_Partie::Manger()
{

    Plateau[XArriver][YArriver] = 0;

    //-------------------------------------------

    /*
     if (Plateau[x][y]>=11 || MaCouleur<=16)
        {
            MaCouleur = 0; //Blanc
        }

        if (MaCouleur>=1 || MaCouleur<=6)
        {
            MaCouleur = 1; //Noir
        }
    */
}

//-----------------------------------------------------------------------------------

/*-Fonction Verification-*/

bool C_Partie::Verification() {
    
    bool check = false ;

    int Piece = Plateau[XDepart][YDepart];
    int TypePiece = Piece;

    if (TypePiece > 10) {
        TypePiece -= 10;
    }

    switch (TypePiece) {
    //Pion
    case 1:
        check = true;
        break;
    //Cavalier
    case 2:
        check = true;
        break;
    //Fou
    case 3:
        if (DiagonalMovement() && NoBodyIsHere()) {
            check = true;
        }
        break;
    //Tour
    case 4:
        if (LateralMovement() && NoBodyIsHere()) {
            check = true;
        }
        break;
    //Dame
    case 5:
        if (DiagonalMovement() || LateralMovement() && NoBodyIsHere()) {
            check = true;
        }
    //Roi
    case 6:
        check = true;
        break;
    }

    return check;
}

//-----------------------------------------------------------------------------------

/*-Fonction NoBodyIsHere-*/

bool C_Partie::NoBodyIsHere() {

    bool check = true;  //variable qui vérifie la condition NoBodyIsHere

    //Variables x et y pour ne pas modifié xDepart et yDepart
    int x = XDepart, y = YDepart ;           

    //Pour determiner le sens de déplacement en x et y 
    int caseX = XArriver - XDepart;
    int caseY = YArriver - YDepart;

    //Le sens de déplacement de la verification (case par case)
    int deplacementX = 0 , deplacementY = 0 ;                               

    //Si CaseX > 0 alors le déplacement en x est positif (monter)
    if (caseX > 0) {                                           
        deplacementX = 1;
    }
    //Si CaseX < 0 alors le déplacement en x est négatif (descendre)
    else if (caseX < 0) {                                       
        deplacementX = -1;
    }


    //Si CaseY > 0 alors le déplacement en y est positif (droite)   
    if (caseY > 0) {                                                              
        deplacementY = 1;
    }
    //Si CaseY > 0 alors le déplacement en y est négatif (gauche)
    else if (caseY < 0) {                                      
        deplacementY = -1;
    }

    //Tant que l'on à pas checker toutes les cases entre Départ et Arriver
    do {

        //permet de se déplacer d'une case par case entre Départ et Arriver
        x += deplacementX;
        y += deplacementY;

        //Check la case , si elle est occupé alors check = false
        if (Plateau[x][y] != 0)
        {
            check = false;
        }

    } while (x != XArriver || y != YArriver);

    return check;                                               
}

//-----------------------------------------------------------------------------------

/*-Fonction LateralMovement-*/

bool C_Partie::LateralMovement() {

    bool check = true;  //variable qui vérifie la condition LateralMovement

    //si la condition est vrai , alors c'est un déplacement diagonale
    if (XDepart != XArriver && YDepart != YArriver) { 
        check = false;
    }

    return check;
}

//-----------------------------------------------------------------------------------

/*-Fonction DiagonalMovement-*/

bool C_Partie::DiagonalMovement() {
    bool check = false;  //variable qui vérifie la condition DiagonalMovement

    //si la condition est vrai , alors c'est un déplacement diagonale
    if (XDepart != XArriver && YDepart != YArriver) {
        check = true;
    }

    return check;
}