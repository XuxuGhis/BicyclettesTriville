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
    int rayon = 3;
    std::string couleur = "rgb(200, 0, 0)";
    fichiersvg.addDisk(m_x+decalage, m_y, rayon, couleur);
    fichiersvg.addText(m_x+7.7+decalage, m_y -3, m_id, couleur);

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
