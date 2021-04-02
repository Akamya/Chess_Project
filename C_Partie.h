#ifndef C_PARTIE_H
#define C_PARTIE_H

class C_Partie
{
    //Attribut
    public:

    int Vide;
    int Interdit;

    int PionBlanc;
    int CavalierBlanc;
    int FouBlanc;
    int TourBlanc;
    int DameBlanc;
    int RoiBlanc;

    int PionNoir;
    int CavalierNoir;
    int FouNoir;
    int TourNoir;
    int DameNoir;
    int RoiNoir;

    int Plateau[9][9];
    int XDepart , YDepart , XArriver , YArriver;


    int Pieces_Blanc_Mort[16];
    int Pieces_Noir_Mort[16];

    std::string Historique [30];

    // var qui indique � qui de jouer : 0 veut dire blanc, 1 veut dire noir
    int Tour;


    bool MaCouleur;



    //M�thode
    public:

    C_Partie();
    void Init();
    void SetPiece();
    void Deplacer();
    std::string Convertir();
    void Tranmettre();
    void Verification();
    void Demander();
    int Reception();
    void Manger();
    void SystemeTour();

};

#endif // C_PARTIE_H
