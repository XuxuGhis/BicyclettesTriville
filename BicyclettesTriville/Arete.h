#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED

#include "Sommet.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Sommet.h"
#include "svgfile.h"

class Arete
{
    public:
        Arete (int id, double p1, double p2, int idS1, int idS2);
        void afficherData() const;
        void dessinerArete(Svgfile& fichiersvg, std::vector<Sommet*> v_tmp, int selec);
        int getIdArete();

        double getP1();
        double getP2();

        int getIdArete_s1();
        int getIdArete_s2();


        ~Arete();


    private:
        int m_id;
        double m_p1;
        double m_p2;

        int m_idS1;
        int m_idS2;


        //Sommet s1;
        //Sommet s2;
};


#endif // ARETE_H_INCLUDED
