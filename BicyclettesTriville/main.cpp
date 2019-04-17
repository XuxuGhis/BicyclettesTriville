#include "Graphe.h"



void Kruskal_1(Graphe g);
void Kruskal_2(Graphe g);

int main()
{


   // Graphe g{"cubetown.txt", "cubetown_weights_0.txt"};
   Graphe g{"manhattan.txt", "manhattan_weights_0.txt"};
   Graphe g2{"manhattan.txt", "manhattan_weights_0.txt"};
    // Graphe g{"triville.txt", "triville_weights_0.txt"};
    //Graphe g{"broadway.txt", "broadway_weights_2.txt"};



    Kruskal_1(g);
    Kruskal_2(g2);

    //On ouvre le ficher "output.svg"
    system("start output.svg");
    system("start output2.svg");



    system("PAUSE");          //On attend que l'utilisateur appuis sur une touche

    //system("TASKKILL /IM chrome.exe"); // On ferme tous les ficher de Google Chrome

    //system("cls"); //On clean la console pour bien montrer que c'est la fin


    return 0;
}


void Kruskal_1(Graphe g)
{

    Svgfile svgout;

 // std::cout<< n<<"!!!!"<<std::endl;
    g.dessinerGraphe(svgout);

    g.kruskal(1);


    g.dessinerGrapheKruskal(svgout, 500);

}

void Kruskal_2(Graphe g)
{

    Svgfile svgout2("output2.svg");

    g.dessinerGraphe(svgout2);

    g.kruskal(2);

    g.dessinerGrapheKruskal(svgout2, 500);

}

