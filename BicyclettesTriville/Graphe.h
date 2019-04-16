#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include "Sommet.h"
#include "Arete.h"

#include "svgfile.h"

#include <unordered_map>
#include <string>
#include <queue>

#include <iostream>

class Graphe
{
    public:
        Graphe(std::string nomFichier, std::string nomFic2);

        void dessinerGraphe();
        void afficher() const;
        ~Graphe();


    private:
        std::unordered_map <std::string,Sommet *> m_s;
        std::unordered_map <std::string,Arete *> m_a;
};



#endif // GRAPHE_H_INCLUDED
