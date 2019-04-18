#ifndef NUAGE_H_INCLUDED
#define NUAGE_H_INCLUDED

#include "Graphe.h"
#include <vector>
#include <algorithm>

class Nuage
{
    public:
        Nuage(Graphe* g);
        void Kruskal(int p, Svgfile& fichier_svg, std::string fichier_1, std::string fichier_2);
        void graphique();
        void Possibilites();
        void toutesPossibilites();
        void afficherNuage();
        void test();
        void pareto(Svgfile& ficsvg);

        ~Nuage();


    private:

        std::vector<Graphe*> m_vg;

};

#endif // NUAGE_H_INCLUDED