#include "Arete.h"

Arete::Arete(std::string id, float p1, float p2):m_id{id}, m_p1{p1}, m_p2{p2}
{ }

void Arete::afficherData() const
{
     std::cout<<"    "<<m_id<<" : "<<"(P1,P2)=("<<m_p1<<","<<m_p2<<")"<<std::endl;
}

/*std::string Sommet::getId()
{
    return m_id;
}

float Sommet::getP1()
{
    return m_p1;
}

float Sommet::getP2()
{
    return m_p2;
}

std::string Sommet::getId1()
{
    return m_idS1;
}

std::string Sommet::getId2()
{
    return m_idS2;
}*/
