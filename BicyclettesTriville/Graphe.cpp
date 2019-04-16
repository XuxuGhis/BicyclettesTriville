#include "Graphe.h"
#include "Sommet.h"

Graphe::Graphe(std::string nomFichier, std::string nomFic2)
{
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    std::string id;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i)
    {
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees sommet");
        m_s.insert({id,new Sommet{id,x,y}});
    }
    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    std::string id_voisin;
    //lecture des aretes
    for (int i=0; i<taille; ++i)
    {
        //lecture des ids des deux extr�mit�s
        int idarete;
        ifs>>idarete;
        if (idarete!=i)
            throw std::runtime_error( "Incoherence ... " + nomFichier );

        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>id_voisin; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");
        //ajouter chaque extremite a la liste des voisins de l'autre (graphe non orient�)
        (m_s.find(id))->second->ajouterVoisin((m_s.find(id_voisin))->second);
        (m_s.find(id_voisin))->second->ajouterVoisin((m_s.find(id))->second);//remove si graphe orient�
    }


    std::ifstream ifs2{nomFic2};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFic2 );
    int taille2;
    int nbPoids;

    ifs2 >> taille2;
    if (ifs2.fail())
        throw std::runtime_error("Probleme lecture taille du graphe");
    ifs2 >> nbPoids;
    if (ifs2.fail())
        throw std::runtime_error("Probleme lecture nombre de poids du graphe");

    std::string id2;
    float p1;
    float p2;

    for (int t=0; t<taille2; ++t)
    {
        ifs2>>id2; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees arete");
        ifs2>>p1; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees arete");
        ifs2>>p2; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees arete");
        m_a.insert({id2,new Arete{id2,p1,p2}});
    }

}

void Graphe::afficher ()const
{
    //int n = 0;

    ///PAS super !!!!!
    //for(auto it = m_s.begin(); it != m_s.end(); ++it)
    //    ++n;

    int n = m_s.size();

    std::cout<<"graphe : "<<std::endl;
    std::cout<<"  ordre : "<< n <<std::endl;

    for(auto it : m_s)
    {
        std::cout<<"  sommet : "<<std::endl;
        it.second->afficherData();
        std::cout << ".........." << std::endl;
        it.second->afficherVoisins();
        std::cout << "============================" << std::endl << std::endl;
    }

    for(auto it2 : m_a)
    {
        std::cout<<"  arete : "<<std::endl;
        it2.second->afficherData();
    }



}

void Graphe::dessinerGraphe()
{
    Svgfile svgout;
    svgout.addGrid();
    svgout.addLine(100, 200, 0, 0); ///prendre les coods parcourir la map
    //svgout.addDisk(getX()->m_s,getY()->m_s, 8, "black");

}


Graphe::~Graphe()
{
    //dtor
}
