#ifndef NUAGE_H_INCLUDED
#define NUAGE_H_INCLUDED

#include "Graphe.h"

class Nuage
{
    public:
        Nuage(Graphe* g);
        void Kruskal(int p, Svgfile& fichier_svg, std::string fichier_1, std::string fichier_2);
        void graphique();
        void afficherNuage();

        ~Nuage();


    private:

        std::vector<Graphe*> m_vg;

};

#endif // NUAGE_H_INCLUDED
