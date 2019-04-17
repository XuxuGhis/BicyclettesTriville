#include "Nuage.h"

Nuage::Nuage(Graphe* g)
{
    m_vg.push_back(g);
}

void Nuage::Kruskal(int p, Svgfile& fichier_svg, std::string fichier_1, std::string fichier_2)
{
    m_vg.push_back(new Graphe(fichier_1, fichier_2));

    m_vg[m_vg.size()-1]->kruskal(p);

    m_vg[m_vg.size()-1]->dessinerGrapheKruskal(fichier_svg, 500);

}


Nuage::~Nuage()

{
    //dtor
}
