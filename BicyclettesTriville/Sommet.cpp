#include "Sommet.h"

//Constructeur de sommet
Sommet::Sommet(std::string id,double x,double y):m_id{id},m_x{x},m_y{y}
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

