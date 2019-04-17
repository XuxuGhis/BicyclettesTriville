#include "Graphe.h"
#include "Sommet.h"
#include <stdlib.h>


Graphe::Graphe(std::string nomFichier, std::string nomFic2)
{
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    m_ordre = ordre;
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

    parent = new int[m_ordre];

    for (int i = 0; i < m_ordre; i++)
        parent[i] = i;

    G.clear();
    T.clear();

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
        itS->dessinerSommet(fichiersvg, 0);

    for(auto itA : m_a)
        itA->dessinerArete(fichiersvg, m_s, 1);

}


void Graphe::dessinerGrapheKruskal(Svgfile& fichiersvg, int decalage)
{


    //fichiersvg.addGrid();

    for(auto itS : m_s)
    {
        itS->dessinerSommet(fichiersvg, decalage);
    }

    std::vector<Arete* >::iterator itA;


    for (int unsigned i = 0; i < T.size(); i++)
    {
        m_a[i]->dessinerAreteKruskal(fichiersvg, m_s, T[i].second.first, T[i].second.second, decalage);

       // std::cout<<"sssssssssssssssssssss !!" << T[i].second.first <<std::endl;

    }

    T.clear();
}



int Graphe::trouver_parent(int i)
 {
    //Si i est son propre parent
    if (i == parent[i])
        return i;
    else
        // si non, on le cherche

        return trouver_parent(parent[i]);
}

void Graphe::union_set(int u, int v)
{
    parent[u] = parent[v];
}


void Graphe::kruskal(int choix_p)
{

    int p ;

    ///G = (m_a[n]->Ajoutpoidsarete(choix_p));

    for(auto it2 : m_a)
    {
        if (choix_p == 1)
            p = it2->getP1();

        else if (choix_p == 2)
            p = it2->getP2();

        std::cout << "m_p__-"<< p<< std::endl;

       // std::cout << "ordre"<< it2<< std::endl;
        G.push_back(make_pair(p, arete(it2->getIdArete_s1(), it2->getIdArete_s2())));

    }


    // std::cout << "DEBUT KRUSKAL" << std::endl;

    int unsigned i;
    int uRep, vRep;


   /// sort(G.begin(), G.end(), triArete(G)); // tri de poids
    sort(G.begin(), G.end()); // tri de poids

    for (i = 0; i < G.size(); i++)
    {
        uRep = trouver_parent(G[i].second.first);
        std::cout << G[i].first<< std::endl;
        vRep = trouver_parent(G[i].second.second);
       // std::cout << "DEBUT KRUSKAL" << std::endl;
        if (uRep != vRep)
        {
            T.push_back(G[i]); // ajout � l'arbre
           // std::cout << "T"<< T[i].first<< std::endl;
            union_set(uRep, vRep);
        }
       // std::cout << "T____"<< T[i].first<< std::endl;
    }

   /* for (size_t i = 0; i<T.size(); ++i)
        std::cout << "T_2___"<< T[i].first<< std::endl;*/

   // std::cout << "FIN KRUSKAL" << std::endl;
}
void Graphe::afficher()
{
    std::cout << "Arete :" << " Poids" << std::endl;
    for (int unsigned i = 0; i < T.size(); i++)
    {
        std::cout << T[i].second.first << " - " << T[i].second.second << " : "
                << T[i].first;
        std::cout << std::endl;
    }
}

//https://www.programiz.com/dsa/kruskal-algorithm

int Graphe::getOrdre()
{
    return m_ordre;
}


Graphe::~Graphe()
{
    //dtor
}



bool triArete(std::vector<std::pair<int, arete>> v_tri)
{
    for (size_t t = 0; t<v_tri.size(); ++t)
    {
        if (v_tri[t].first > v_tri[t+1].first)
            return 0;

        else
            return 1;
    }

    return 0;
}
