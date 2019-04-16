#include "Arete.h"

Arete::Arete(int id, double p1, double p2, int idS1, int idS2):m_id{id}, m_p1{p1}, m_p2{p2}, m_idS1{idS1}, m_idS2{idS2}
{ }

void Arete::afficherData() const
{
     std::cout<<"    "<<m_id<<" : "<<"(P1,P2)=("<<m_p1<<","<<m_p2<<")"<<std::endl;
     std::cout<<" sommet 1 :"<<m_idS1<<std::endl;
     std::cout<<" sommet 2 :"<<m_idS2<<std::endl;

}

void Arete::dessinerArete(Svgfile& fichiersvg, std::vector<Sommet*> v_tmp, int selec)
{
    double x_som1, y_som1;
    double x_som2, y_som2;

    std::string couleur = "rgb(0, 0, 0)";
    std::string couleur2 = "rgb(0, 119, 179)";

    x_som1 = v_tmp[m_idS1]->getX();
    y_som1 = v_tmp[m_idS1]->getY();

    x_som2 = v_tmp[m_idS2]->getX();
    y_som2 = v_tmp[m_idS2]->getY();

    double x_text = (x_som1+x_som2)/2;
    double y_text = (y_som1+y_som2)/2;

    if (selec == 1)
    {
        fichiersvg.addLine(x_som1, y_som1, x_som2, y_som2);
        fichiersvg.addText(x_text, y_text - 3.7, m_id, couleur2);
    }

    else if (selec == 0)
        std::cout<<"ON AFFICHE R"<<std::endl;
    else
        std::cout<<"PAS COMPRIS !!"<<std::endl;


}


int Arete::getIdArete()
{
    return m_id;
}

double Arete::getP1()
{
    return m_p1;
}

double Arete::getP2()
{
    return m_p2;
}


int Arete::getIdArete_s1()
{
    return m_idS1;
}

int Arete::getIdArete_s2()
{
    return m_idS2;
}
