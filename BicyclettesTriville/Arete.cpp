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
    std::string couleur3 = "rgb(0, 200, 0)";

    x_som1 = v_tmp[m_idS1]->getX();
    y_som1 = v_tmp[m_idS1]->getY();

    x_som2 = v_tmp[m_idS2]->getX();
    y_som2 = v_tmp[m_idS2]->getY();

    double x_text = (x_som1+x_som2)/2;
    double y_text = (y_som1+y_som2)/2;

    double moins = 15;

    if (selec == 1)
    {
        fichiersvg.addLine(x_som1, y_som1, x_som2, y_som2);
        fichiersvg.addText(x_text, y_text - 3.7, m_id, couleur2);
       // fichiersvg.addText(x_text-moins, y_text - 3.7-moins, "(", couleur2);
        fichiersvg.addText(x_text-moins-3, y_text - 3.7-moins, m_p1, couleur3);
       // fichiersvg.addText(x_text-moins-5, y_text - 3.7-moins, ",", couleur3);
        fichiersvg.addText(x_text-moins-7, y_text - 3.7, m_p2, couleur3);
        //fichiersvg.addText(x_text-moins-9, y_text - 3.7-moins, ")", couleur3);
    }

    else if (selec == 0)
        std::cout<<"ON AFFICHE R"<<std::endl;
    else
        std::cout<<"PAS COMPRIS !!"<<std::endl;

}

void Arete::dessinerAreteKruskal(Svgfile& fichiersvg, std::vector<Sommet*> v_tmp, int id1, int id2, int decalage)
{
    double x_som1, y_som1;
    double x_som2, y_som2;

    std::string couleur = "rgb(0, 0, 0)";
    std::string couleur2 = "rgb(0, 119, 179)";

    x_som1 = v_tmp[id1]->getX();
    y_som1 = v_tmp[id1]->getY();

    x_som2 = v_tmp[id2]->getX();
    y_som2 = v_tmp[id2]->getY();


    //std::cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa!!"<<std::endl;


    double x_text = (x_som1+x_som2)/2;
    double y_text = (y_som1+y_som2)/2;

    fichiersvg.addLine(x_som1+decalage, y_som1, x_som2+decalage, y_som2);
    fichiersvg.addText(x_text+decalage, y_text - 3.7, m_id, couleur2);


}



std::vector<std::pair<int, arete>> Arete::Ajoutpoidsarete(int choix_p)
{

    std::vector<std::pair<int, arete>> G;
    G.clear();

  //  std::cout<< "MARCHE PUTAIN !"<<std::endl;

    int p ;

    if (choix_p == 1)
    {
        p = m_p1;
    }

    else if (choix_p == 2)
        p = m_p2;

    std::cout << "m_p1__-"<< m_p1<< std::endl;

    G.push_back(make_pair(p, arete(m_idS1, m_idS2)));

    for (size_t i = 0; i<G.size(); ++i)
        std::cout << "G_--___"<< G[i].first<< std::endl;
    return G;

}

/*
bool Arete::triArete(std::vector<std::pair<int, arete>> v_tri)
{
    for (size_t t = 0; t<v_tri.size(); ++t)
    {
        if (v_tri[t].first > v_tri[t+1].first)
            return 0;

        else
            return 1;
    }
}*/

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
