#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include "Sommet.h"
#include "Arete.h"

#include "svgfile.h"

#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>

#include <iostream>



class Graphe
{
    public:
        Graphe(std::string nomFichier, std::string nomFic2);
      //  Graphe(int nbsommet);

        void dessinerGraphe(Svgfile& fichiersvg);
        void dessinerGrapheKruskal(Svgfile& fichiersvg, int decalage);
        void afficher() const;


        //void Ajoutpoidsarete(int u, int v, int w);
        void Ajoutpoidsarete(int choix_p);
        int trouver_parent(int i);
        void union_set(int u, int v);
        void kruskal(int choix_p);
        void afficher();

        int getOrdre();


        ~Graphe();


    private:

        std::vector<Sommet* > m_s;
        std::vector<Arete* > m_a;
        int m_ordre;

        std::vector<std::pair<int, arete>> G; // graph
        std::vector<std::pair<int, arete>> T; // mst
        int *parent;
        int nbsommet; // number of vertices/nodes in graph
};

bool triArete(std::vector<std::pair<int, arete>> v_tri);


#endif // GRAPHE_H_INCLUDED
