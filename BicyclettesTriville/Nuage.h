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
        //void bruteForce();
        void bruteForce(Svgfile& ficsvg);
        void toutesPossibilites();
        void supPossibilte();
        void afficherNuage();
        void test();
        void pareto(Svgfile& ficsvg);

        ~Nuage();


    private:

        std::vector<Graphe*> m_vg;
        std::vector<int> m_vg_poids;
        std::vector<Graphe*> m_possibilite;
        std::vector<int> m_sommeP1;
        std::vector<int> m_sommeP2;

};

#endif // NUAGE_H_INCLUDED
