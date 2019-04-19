#include "Graphe.h"
#include "Sommet.h"
#include <stdlib.h>

Graphe::Graphe(std::vector<Arete* > va, std::vector<Sommet* > vs)
{
    m_taille = va.size();
    m_ordre = vs.size();

    for(int i =0; i<m_taille; ++i)
        m_a.push_back(va[i]);

    for(int n =0; n<m_ordre; ++n)
        m_s.push_back(vs[n]);

}



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
    m_taille = taille;
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

std::vector<Arete* > Graphe::choisirArete(std::vector<bool> vect)
{
    std::vector<Arete* > v_choisi;

    return v_choisi;
}

void Graphe::afficher ()const
{

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


void Graphe::dessinerGrapheKruskal(Svgfile& fichiersvg, int decalage, int choix_p)
{


    //fichiersvg.addGrid();

    for(auto itS : m_s)
    {
        itS->dessinerSommet(fichiersvg, decalage);
    }

    std::vector<Arete* >::iterator itA;


    for (int unsigned i = 0; i < T.size(); i++)
    {
        m_a[i]->dessinerAreteKruskal(fichiersvg, m_s, T[i].second.first, T[i].second.second, decalage, choix_p);

       // std::cout<<"sssssssssssssssssssss !!" << T[i].second.first <<std::endl;

    }

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

double Graphe::sommePoids(int choix_p)
{
    int p ;
    int somme_pg;

    for(auto it2 : m_a)
    {
        if (choix_p == 1)
            p = it2->getP1();

        else if (choix_p == 2)
            p = it2->getP2();

        somme_pg = somme_pg+p;
    }

    return somme_pg;
}

void Graphe::kruskal(int choix_p)
{

    int p ;

    for(auto it2 : m_a)
    {
        if (choix_p == 1)
            p = it2->getP1();

        else if (choix_p == 2)
            p = it2->getP2();

      //  std::cout << "m_p__-"<< p<< std::endl;

        G.push_back(make_pair(p, arete(it2->getIdArete_s1(), it2->getIdArete_s2())));

    }


    // std::cout << "DEBUT KRUSKAL" << std::endl;

    int unsigned i;
    int uRep, vRep;


    //sort(G.begin(), G.end(), triArete(G)); // tri de poids

    sort(G.begin(), G.end()); // tri de poids

    for (i = 0; i < G.size(); i++)
    {
        uRep = trouver_parent(G[i].second.first);
       // std::cout << G[i].first<< std::endl;
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

   // std::cout << "FIN KRUSKAL" << std::endl;
}
void Graphe::afficher()
{
   // std::cout << "Arete :" << " Poids" << std::endl;
    for (int unsigned i = 0; i < T.size(); i++)
    {
        std::cout << T[i].second.first << " - " << T[i].second.second << " : "
                << T[i].first;
        std::cout << std::endl;
    }
}



void Graphe::toutesPossibilites ()
 {

   std::vector<Arete* > va_selec;
    ///affiche toutes les combinaisons possibles : c-a-d 2^nbdaretes
    //std::cout<<"toutes les combinaisons possibles sont :"<<std::endl;
   // int n = m_ordre; /// NOMBRE DE SOMMET
    int k = m_taille; ///NOMBRE DARETE
    std::vector<bool> vect_tmp(k,true);
    for(int i = 0; i<k; i++)
    {
        ///I = NOMBRE DARETE QUON GARDE POUR CET ESSAI
        std::vector<bool> vect(k,true);

        for(int j = 0; j< k-i;j++)
        {
            vect[j] = false;///J = LARRETE QUON ENLEVE MAINTENANT LA
        }

        do{
        /*for (auto it=vect.begin(); it!=vect.end(); it++)
                std::cout <<*it;
        for (auto it=vect.begin(); it!=vect.end(); it++)
                std::cout<<"vect 0 "<< vect[0]<<std::endl;*/

            for (int n=0; n<m_taille; ++n)
            {
                std::cout<<"vect "<< n << vect[n]<<std::endl;
                //std::cout<<"vect "<< n <<std::endl;
            }


            //std::cout <<"size"<< va_selec.size()<< std::endl;
            std::cout << std::endl;
         }while(std::next_permutation(vect.begin(),vect.end()));

         vect_tmp = vect;
      /*  for(auto it2 : vect_tmp)
            std::cout<<"vect temp "<< it2<<std::endl;*/
    }

/*
    for(auto it2 : vect_tmp)
        std::cout<<"vect temp "<< it2<<std::endl;*/


 }






void Graphe::dessinerGraphePareto(Svgfile& fichiersvg, int m_p1, int m_p2)
{


    std::string couleur = "rgb(255, 0, 0)";
    /*fichiersvg.addLine(100,50,100,400,couleur);
    fichiersvg.addLine(100,400,400,400,couleur);*/
   // fichiersvg.addDisk(m_p1, m_p2, 10, couleur);
   fichiersvg.addDisk(m_p1, m_p2, 1, couleur);


}



auto comp = [](const std::pair<int, int> &a, const std::pair<int, int> &b) {return a.second > b.second; };

void Graphe::Dijkstra(int Sommetdepart)
 {

     int NbSommet;
     NbSommet=m_ordre;



      std::vector<std::vector<std::pair<int, int>>> G(NbSommet); // vecteur de graphe avec le nbdesommet
      int sommet1, sommet2, poids;                                                                           // chaque sommet est relié à un autre par une arete ayant un poids
      for (int i = 0; i <m_taille-1; ++i)
        {

        sommet1= m_a[i]->getIdArete_s1();
        sommet2= m_a[i]->getIdArete_s2();
        poids = m_a[i]->getP2();

        G[sommet1].push_back(std::make_pair(sommet2, poids));                       // chaque paire contient : first=indice du sommet conncecté au sommet1, second=poids de sommet1 à sommet2
        G[sommet2].push_back(std::make_pair(sommet1, poids));

        }
       // for (size_t n =0; n<m_taille-1; ++n)



      std::vector<int> Distances(NbSommet, std::numeric_limits<int>::max());         // Distances est un vecteur contenant nbsommet cases. Toutes les cases sont initialisées avec max().
                                                                                    // ca j'ai pas trop compris pourquoi max
                                                                                  // Distances[i] est la distance du sommetdepart jusqu'au sommet d'indice i

      Distances[Sommetdepart] = 0;                                                    // Distance initialisée à 0

      std::vector<int> Parents(NbSommet, -1);                                        // Parents est un vecteur avec nbsommets cases. Toutes initialisées à -1 (pourquoi? jsp)

                                                                                    // Priority queue contient des paires et utilise une fonction de comparaison spécifique
                                                                                    // A cause du comparateur on doit mettre 3 paramètres
                                                                                    // Le comparateur fait en sort que le sommet le plus proche est celui au dessus de la queue
                                                                                    // chaque paire est composée de l'indice du sommet et de la distance au sommetdepart
      std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> Q(comp);
      Q.push(std::make_pair(Sommetdepart, 0));                                              // On initialise la priority queue avec le sommet de départ

      while (!Q.empty())
        {                                                          // Dijkstra
        int sommet2 = Q.top().first;                                                      // On recupère l'indice du sommet le plus proche
        int poids = Q.top().second;                                                     // on recupère le poids
        Q.pop();

        if (poids <= Distances[sommet2])
            {

          for (const auto& i : G[sommet2])
            {                                                                       // sommet2 est l'indice du sommet le plus proche
            auto sommet2_2 = i.first;                                                      // Pour chaque sommet connecté à sommet2
            auto poids2 = i.second;

            if (Distances[sommet2] + poids2 < Distances[sommet2_2])
            {                                                                                     // Si la distance du sommetdepart jusqu'au sommet2_2 à travers sommet2 est plus courteque la distance actuelle de sommetdepart à sommet2
              Distances[sommet2_2] = Distances[sommet2] + poids2;                                // alors on met à jour la distance du sommetdepart à sommet2_2 et parent[sommet2_2]
              Parents[sommet2_2] = sommet2;
              Q.push(std::make_pair(sommet2_2, Distances[sommet2_2]));
            }
           }
        }
      }

      for (auto i = 0; i != NbSommet; ++i)
      {                                                                                      //on affiche
        std::cout << "\n Sommet  " << Sommetdepart << " au Sommet " << i << " Poids " << Distances[i] << std::endl;

        std::cout << i;
        for (auto p = Parents[i]; p != -1; p = Parents[p])
          std::cout << " <- " << p;
        std::cout << std::endl;

      }

}
















int Graphe::getOrdre()
{
    return m_ordre;
}

int Graphe::getTaille()
{
    return m_taille;
}

Arete*  Graphe::getAindice(int i)
{
    return m_a[i];
}

Sommet*  Graphe::getSindice(int i)
{
    return m_s[i];
}

std::vector<Sommet* > Graphe::getS()
{
    return m_s;
}

std::vector<Arete* > Graphe::getA()
{
    return m_a;
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


