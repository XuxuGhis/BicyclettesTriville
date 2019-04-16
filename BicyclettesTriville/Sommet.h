#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>

class Sommet
{
    public:
        Sommet (std::string,double,double);
        void ajouterVoisin (Sommet* voisin);
        void afficherData ()const;
        void afficherVoisins () const;

        int getDegre();

        ~Sommet ();

    private:

        std::vector<Sommet*> m_voisins;

        std::string m_id; // Identifiant
        double m_x, m_y; // Position
};


#endif // SOMMET_H_INCLUDED
