#include "Nuage.h"



void ouvrirOutput();
void fermerOutput();
void dessinerAxe(Svgfile& fichiersvg);

int main()
{

    {

    Svgfile svgout;
    Svgfile svgout2("output2.svg");
    Svgfile svgout3("output3.svg");
    Svgfile svgout4("output4.svg");



    std::string nomFich_1 = "broadway.txt";
    std::string nomFich_2= "broadway_weights_0.txt";


    Graphe g{nomFich_1,nomFich_2};
    Graphe g2{nomFich_1,nomFich_2};


    Nuage n(&g);
    Nuage n2(&g2);

    n.bruteForce(svgout3);



    n.pareto(svgout3);
    n.bruteForceDij();
    n.DijkstraGraphe(svgout4);
    n.pareto(svgout4);





    dessinerAxe(svgout3);
    dessinerAxe(svgout4);


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
    system("start output4.svg");
}

void fermerOutput()
{
    //On attend que l'utilisateur appuis sur une touche
    system("PAUSE");
    // On ferme tous les ficher de Google Chrome
    system("TASKKILL /IM chrome.exe");
    system("cls");
}

void dessinerAxe(Svgfile& fichiersvg)
{
    std::string couleurouge = "rgb(255, 0, 0)";
    std::string couleurnoir = "rgb(0, 0, 0)";

    int ptrefx=100;
    int ptrefy=700;

    //fichiersvg.addGrid();

    fichiersvg.addText(700,720 , "poids 1", couleurnoir);
    fichiersvg.addText(20,50 , "poids 2", couleurnoir);
    fichiersvg.addLine(ptrefx,50,ptrefx,ptrefy,couleurnoir); //axe y
    fichiersvg.addLine(ptrefx,ptrefy,ptrefx+600,ptrefy,couleurnoir); //axe x
    fichiersvg.addLine(ptrefx,50,ptrefx-20,70,couleurnoir); //fleche y
    fichiersvg.addLine(ptrefx,50,ptrefx+20,70,couleurnoir); //fleche y
    fichiersvg.addLine(ptrefy-20,ptrefy-20,ptrefy,ptrefy,couleurnoir); //fleche x
    fichiersvg.addLine(ptrefy-20,ptrefy+20,ptrefy,ptrefy,couleurnoir);//fleche x

}

