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
    int id;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i)
    {
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees sommet");
        m_s.push_back(new Sommet{id,x,y});
    }
    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    std::string id_voisin;


    //lecture des aretes
    std::ifstream ifs2{nomFic2};

    int taille2;
    int nbPoids;

    if (!ifs2)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFic2 );

    ifs2 >> taille2;
    if (ifs2.fail())
        throw std::runtime_error("Probleme lecture taille du graphe");
    ifs2 >> nbPoids;
    if (ifs2.fail())
        throw std::runtime_error("Probleme lecture nombre de poids du graphe");

    for (int i=0; i<taille; ++i)
    {




        int id2;
        float p1;
        float p2;

        //lecture des ids des deux extr�mit�s
        int idarete;
        int idS1, idS2;
        ifs>>idarete;
        if (idarete!=i)
            throw std::runtime_error( "Incoherence du nombre d'arrete" + nomFichier );

        ifs>>idS1; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>idS2; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");
        //ajouter chaque extremite a la liste des voisins de l'autre (graphe non orient�)
        ifs2>>id2; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees arete");
        ifs2>>p1; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees arete");
        ifs2>>p2; if(ifs.fail()) throw std::runtime_error("Probleme lecture donnees arete");


        m_a.push_back(new Arete{id2,p1,p2,idS1,idS2});

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
        it->afficherData();
        std::cout << ".........." << std::endl;
        it->afficherVoisins();
        std::cout << "============================" << std::endl << std::endl;
    }

    for(auto it2 : m_a)
    {
        std::cout<<"  arete : "<<std::endl;
        it2->afficherData();
    }



}

void Graphe::dessinerGraphe(Svgfile& fichiersvg)
{

    //fichiersvg.addGrid();

    for(auto itS : m_s)
        itS->dessinerSommet(fichiersvg);

    for(auto itA : m_a)
        itA->dessinerArete(fichiersvg, m_s, 1);



}


Graphe::~Graphe()
{
    //dtor
}
