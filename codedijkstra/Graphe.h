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
        Graphe(std::vector<Arete* > va, std::vector<Sommet* > vs);

        void dessinerGraphe(Svgfile& fichiersvg);
        void dessinerGrapheKruskal(Svgfile& fichiersvg, int decalage,int choix_p);
        void afficher() const;

       // std::vector<Arete* >toutesPossibilites ();
        void toutesPossibilites ();

        //void Ajoutpoidsarete(int u, int v, int w);
        void Ajoutpoidsarete(int choix_p);
        int trouver_parent(int i);
        void union_set(int u, int v);
        void kruskal(int choix_p);
        void afficher();

        void pareto(Svgfile& fichiersvg,int m_p1,int m_p2);
        void dessinerGraphePareto(Svgfile& fichiersvg, int m_p1, int m_p2);
        std::vector<Arete* > choisirArete(std::vector<bool> vect);
        int getOrdre();
        int getTaille();

        std::vector<Arete* > getA();
        Arete* getAindice(int i);
        Sommet* getSindice(int i);
        std::vector<Sommet* > getS();
        double sommePoids(int choix_p);//Représente la somme total du poids 1 du graphe


        void Dijkstra(int m_ordre, int m_taille/*vecteur de sommet et d'aretes?*/);

        ~Graphe();


    private:

        std::vector<Sommet* > m_s;
        std::vector<Arete* > m_a;

        int m_ordre;
        int m_taille;

        std::vector<std::pair<int, arete>> G; // graph
        std::vector<std::pair<int, arete>> T; // mst
        int *parent;
        int nbsommet; // number of vertices/nodes in graph
};

bool triArete(std::vector<std::pair<int, arete>> v_tri);


#endif // GRAPHE_H_INCLUDED
