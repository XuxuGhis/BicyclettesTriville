#include "Sommet.h"

//Constructeur de sommet
Sommet::Sommet(int id,double x,double y):m_id{id},m_x{x},m_y{y}
{ }

//Retourne le degre d'un sommet
int Sommet::getDegre()
{
    int dg;
    for(auto it = m_voisins.begin(); it != m_voisins.end(); ++it)
        ++dg;

    return dg;
}

//Méthode pour l'ajout des voisins
void Sommet::ajouterVoisin (Sommet* voisin)
{
    m_voisins.push_back(voisin);

    std::cout << m_id << " : ajout du voisin " << voisin->m_id << std::endl;
}



//Affichage des données sur la console
    //Pour le sommet
void Sommet::afficherData() const
{
     std::cout<<"    "<<m_id<<" : "<<"(x,y)=("<<m_x<<","<<m_y<<")"<<std::endl;
}
    //Pour ses voisins
void Sommet::afficherVoisins() const
{
    std::cout<<"  voisins :"<<std::endl;
    for(auto v:m_voisins)
    {
        v->afficherData();
    }
}

void Sommet::dessinerSommet(Svgfile& fichiersvg, int decalage)
{
    std::string couleur =  "rgb(200, 0, 110)";

   // fichiersvg.addgroupe(decalage+m_x, decalage+m_y);
  //  fichiersvg.lireSVG("Somaison.txt");
  //  fichiersvg.fingroupe();
      fichiersvg.addDisk(m_x+decalage, m_y, 7, couleur);
      fichiersvg.addText(m_x+7.7+decalage, m_y -3, m_id, couleur);

}

void Sommet::dessinerSomaison(Svgfile& fichiersvg, int decalage)
{
    //fichiersvg.addDisk(m_x+dec)
   fichiersvg.addDisk(150+m_x+decalage, 15+m_y+decalage, 30, "#F4F4F9");
   fichiersvg.addDisk(140+m_x+decalage, 60+m_y+decalage, 20, "#B8DBD9");
   fichiersvg.addDisk(120+m_x+decalage, 80+m_y+decalage, 10, "#a1a1a1");
   fichiersvg.addRectanglePosition(110+m_x+decalage, 90+m_y+decalage, 20, 50,"#8C5E58");
   fichiersvg.addPolygon(100+m_x+decalage,m_y+decalage+100,150+decalage+m_x,m_y+decalage+150, 50+decalage+m_x, 150+decalage+m_y,"#8C5E58");
   fichiersvg.addRectanglePosition(110+m_x+decalage, 90+m_y+decalage, 80, 50,"#8C5E58");
   fichiersvg.addRectanglePosition(100+m_x+decalage, 170+m_y+decalage, 20, 30,"#0D1F22");



   // fichiersvg.addDisk(m_x+decalage, m_y, rayon, couleur);
   // fichiersvg.addText(m_x+7.7+decalage, m_y -3, m_id, couleur);

}



double Sommet::getX()
{
    return m_x;
}

double Sommet::getY()
{
    return m_y;
}

int Sommet::getIdSommet()
{
    return m_id;
}
