#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED

#include "Sommet.h"
#include <iostream>
#include <fstream>
#include <string>

class Arete
{
    public:
        Arete (std::string,float,float);
        void afficherData() const;

        ~Arete();


    private:
        std::string m_id;
        std::string m_idS1;
        std::string m_idS2;
        float m_p1;
        float m_p2;
        //Sommet s1;
        //Sommet s2;
};


#endif // ARETE_H_INCLUDED
