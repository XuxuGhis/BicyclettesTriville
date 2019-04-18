#include "Nuage.h"



void ouvrirOutput();
void fermerOutput();

int main()
{

    {
    Svgfile svgout;
    Svgfile svgout2("output2.svg");
    Svgfile svgout3("output3.svg");

    std::string nomFich_1 = "broadway.txt";
    std::string nomFich_2= "broadway_weights_0.txt";


    Graphe g{nomFich_1,nomFich_2};


    Nuage n(&g);
    //n.Possibilites();
    n.toutesPossibilites();
    n.pareto(svgout3);









    g.dessinerGraphe(svgout);
    n.Kruskal(1, svgout, nomFich_1, nomFich_2);

    g.dessinerGraphe(svgout2);
    n.Kruskal(2, svgout2, nomFich_1, nomFich_2);


    }

   // ouvrirOutput();

   // fermerOutput();

    return 0;
}

void ouvrirOutput()
{
    //system("cls"); //On clean la console pour bien montrer que c'est la fin
    system("start output.svg");
    system("start output2.svg");
    system("start output3.svg");
}

void fermerOutput()
{
    //On attend que l'utilisateur appuis sur une touche
    system("PAUSE");
    // On ferme tous les ficher de Google Chrome
    system("TASKKILL /IM chrome.exe");
    system("cls");
}


