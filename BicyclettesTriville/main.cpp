#include "Graphe.h"

Svgfile svgout;

void Kruskal(Graphe g);

int main()
{

  //float p1,p2;




    Graphe g{"cubetown.txt", "cubetown_weights_0.txt"};
//    Graphe g{"manhattan.txt", "manhattan_weights_0.txt"};

    g.dessinerGraphe(svgout);



    Kruskal(g);

    //On ouvre le ficher "output.svg"
    system("start output.svg");


    system("PAUSE");          //On attend que l'utilisateur appuis sur une touche

    //system("TASKKILL /IM chrome.exe"); // On ferme tous les ficher de Google Chrome

    //system("cls"); //On clean la console pour bien montrer que c'est la fin


    return 0;
}


void Kruskal(Graphe g)
{

  int n = g.getOrdre();

 // std::cout<< n<<"!!!!"<<std::endl;

  for (int i = 0; i<n; ++i)
  {
      g.kruskal(i,1);
  }

  g.afficher();

  g.dessinerGrapheKruskal(svgout, 500);


}
