#include "Arete.h"

Arete::Arete(std::string id, float p1, float p2):m_id{id}, m_p1{p1}, m_p2{p2}
{ }

void Arete::afficherData() const
{
     std::cout<<"    "<<m_id<<" : "<<"(P1,P2)=("<<m_p1<<","<<m_p2<<")"<<std::endl;
}

std::string Arete::getId()
{
    return m_id;
}

float Arete::getP1()
{
    return m_p1;
}

float Arete::getP2()
{
    return m_p2;
}

std::string Arete::getId1()
{
    return m_idS1;
}

std::string Arete::getId2()
{
    return m_idS2;
}
