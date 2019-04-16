#include "Graphe.h"


void svgTest();

int main()
{



    Graphe g{"broadway.txt", "broadway_weights_0.txt"};

    g.dessinerGraphe();
    g.afficher();


    //On ouvre le ficher "output.svg"
    system("start output.svg");


    system("PAUSE");          //On attend que l'utilisateur appuis sur une touche

    //system("TASKKILL /IM chrome.exe"); // On ferme tous les ficher de Google Chrome

    //system("cls"); //On clean la console pour bien montrer que c'est la fin


    return 0;
}


void svgTest()
{
    /// Sortie graphique dans le fichier output.svg
    /// ( options � voir svgfile.h ligne 23 )


    /// Dessin du rep�re cart�sien


    //svgout.addDisk(100, 100, 90, "greyball");
   // svgout.addDisk(500, 100, 50, "blueball");
    /*svgout.addDisk(300, 100, 70, "greenball");
    svgout.addDisk(500, 100, 50, "blueball");
    svgout.addDisk(700, 100, 30, "greyball");

    /// Dessins de disques
    svgout.addDisk(100, 300, 30, "red");
    svgout.addDisk(300, 300, 50, "green");
    svgout.addDisk(500, 300, 70, "blue");
    svgout.addDisk(700, 300, 90, "grey");*/

    /// Dessins de croix
    //svgout.addCross(300, 300, 50);


    /// L'objet svgout est automatiquement lib�r� � la sortie
    /// de ce sous-programme : le fichier output.svg est alors ferm�
}


