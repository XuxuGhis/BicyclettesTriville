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

        void bruteForce(Svgfile& ficsvg);
        void bruteForceDij();
        void DijkstraGraphe(Svgfile& ficsvg);
        void afficherNuage();
        void pareto(Svgfile& ficsvg);
        void paretoDij(Svgfile& ficsvg);

        ~Nuage();


    private:

        std::vector<Graphe*> m_vg;
        std::vector<int> m_vg_poids;
        std::vector<Graphe*> m_possibilite;
        std::vector<int> m_sommeP1;
        std::vector<int> m_sommeP2;
        std::vector<std::pair<int,int>> m_pairpoids;

};

#endif // NUAGE_H_INCLUDED
