#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>
#include "svgfile.h"

class Sommet
{
    public:
        Sommet (int ,double ,double);
        void ajouterVoisin (Sommet* voisin);
        void afficherData ()const;
        void afficherVoisins () const;
        void dessinerSommet(Svgfile& fichiersvg, int decalage);
        void dessinerSomaison(Svgfile& fichiersvg, int decalage);

        int getIdSommet();
        double getX();
        double getY();

        int getDegre();

        ~Sommet ();

    private:

        std::vector<Sommet*> m_voisins;

        int m_id; // Identifiant
        double m_x, m_y; // Position
};


#endif // SOMMET_H_INCLUDED
