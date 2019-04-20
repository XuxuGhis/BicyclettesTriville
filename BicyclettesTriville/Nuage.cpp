#include "Nuage.h"

Nuage::Nuage(Graphe* g)
{
    m_vg.push_back(g);
}

void Nuage::Kruskal(int p, Svgfile& fichier_svg, std::string fichier_1, std::string fichier_2)
{
    m_vg.push_back(new Graphe(fichier_1, fichier_2));

    m_vg[m_vg.size()-1]->kruskal(p);

    m_vg[m_vg.size()-1]->dessinerGrapheKruskal(fichier_svg, p);

}


void Nuage::bruteForce(Svgfile& ficsvg)
{

    std::vector<Arete*> va;
    std::vector<Sommet* > vs;
    va.clear();
    vs.clear();

    int k = m_vg[0]->getTaille(); ///NOMBRE DARETE
    int n = m_vg[0]->getOrdre();/// NOMBRE DE SOMMET
    ///affiche toutes les combinaisons possibles : c-a-d 2^nbdaretes
    for(int i = 0; i<k;i++)
    { ///I = NOMBRE DARETE QUON GARDE POUR CET ESSAI
        std::vector<bool> vect(k,true);
        for(int j = 0; j< k-i-1;j++) ///J = LARRETE QUON ENLEVE MAINTENANT LA
            vect[j] = false;
        do{
            for (auto it=vect.begin(); it!=vect.end(); it++)
            {
               // std::cout<<*it;
            }
            //std::cout << std::endl;
         }while(std::next_permutation(vect.begin(),vect.end()));
    }
   // std::cout<<std::endl;

    ///affiche toutes les combinaisons avec nbsommets-1 aretes mais pas forcement couvrantes : c-a-d pas forcement tous les sommets
   // std::cout<<"toutes les combinaisons connexes mais pas forcement couvrantes sont :"<<std::endl;
    ///maintenant il faut verifier celles qui sont connexes et les eliminer de ces combinaisons
    for(int i = n-1; i<k-1;i++)
    { ///I = NOMBRE DARETE QUON GARDE POUR CET ESSAI
        std::vector<bool> vect(k,true);
        for(int j = 0; j< k-i;j++) ///J = LARRETE QUON ENLEVE MAINTENANT LA
            vect[j] = false;
        do{
               int sp1 = 0;
              int sp2 = 0;
            int nb = 0;
            for (auto it=vect.begin(); it!=vect.end(); it++)
            {
                //La somme des poids
                   // std::cout<<*it;
                    if (*it)
                    {
                      //std::cout<<"ca vaut UN"<<std::endl;
                     /**ON FAIT LA SOMME DES POIDS POUR P1 PUIS POUR P2**/
                      sp1 = sp1 + m_vg[0]->getAindice(nb)->getP1();
                      sp2 = sp2 + m_vg[0]->getAindice(nb)->getP2();
                    }
                   // else std::cout<<"ca vaut ZERO"<<std::endl;
                    ++nb;
            }
          //  std::cout<<std::endl;
                m_pairpoids.push_back({sp1,sp2});
                m_sommeP1.push_back(sp1);
                m_sommeP2.push_back(sp2);
                //LA ON FAIT L'AFFICHAGE
                m_vg[0]->dessinerGraphePareto(ficsvg, sp1*10, sp2*10, "rgb(255, 0, 0)");
         }while(std::next_permutation(vect.begin(),vect.end()));
    }
    for(auto ite = m_sommeP1.begin();ite!=m_sommeP1.end();ite++)
    {
      //std::cout << *ite <<std::endl;
    }
   // std::cout<<std::endl;
    for(auto ite2 = m_sommeP2.begin();ite2!=m_sommeP2.end();ite2++)
    {
    //  std::cout << *ite2 <<std::endl;
    }
    //std::cout<<std::endl;
}


void Nuage::bruteForceDij()
{

    std::vector<Arete*> va;
    std::vector<Sommet* > vs;
    va.clear();
    vs.clear();
    m_sommeP1.clear();
    m_sommeP2.clear();

    int k = m_vg[0]->getTaille(); ///NOMBRE DARETE
    int n = m_vg[0]->getOrdre();/// NOMBRE DE SOMMET
    ///affiche toutes les combinaisons possibles : c-a-d 2^nbdaretes
    for(int i = 0; i<k;i++)
    { ///I = NOMBRE DARETE QUON GARDE POUR CET ESSAI
        std::vector<bool> vect(k,true);
        for(int j = 0; j< k-i-1;j++) ///J = LARRETE QUON ENLEVE MAINTENANT LA
            vect[j] = false;
        do{
            for (auto it=vect.begin(); it!=vect.end(); it++)
            {
               // std::cout<<*it;
            }
            //std::cout << std::endl;
         }while(std::next_permutation(vect.begin(),vect.end()));
    }
   // std::cout<<std::endl;

    ///affiche toutes les combinaisons avec nbsommets-1 aretes mais pas forcement couvrantes : c-a-d pas forcement tous les sommets
   // std::cout<<"toutes les combinaisons connexes mais pas forcement couvrantes sont :"<<std::endl;
    ///maintenant il faut verifier celles qui sont connexes et les eliminer de ces combinaisons
    for(int i = n-1; i<k-1;i++)
    { ///I = NOMBRE DARETE QUON GARDE POUR CET ESSAI
        std::vector<bool> vect(k,true);
        for(int j = 0; j< k-i;j++) ///J = LARRETE QUON ENLEVE MAINTENANT LA
            vect[j] = false;
        do{
               int sp1 = 0;
             // int sp2 = 0;
            int nb = 0;
            for (auto it=vect.begin(); it!=vect.end(); it++)
            {
                //La somme des poids
                   // std::cout<<*it;
                    if (*it)
                    {
                      //std::cout<<"ca vaut UN"<<std::endl;
                     /**ON FAIT LA SOMME DES POIDS POUR P1 PUIS POUR P2**/
                      sp1 = sp1 + m_vg[0]->getAindice(nb)->getP1();
                      //sp2 = sp2 + m_vg[0]->getAindice(nb)->getP2();
                    }
                   // else std::cout<<"ca vaut ZERO"<<std::endl;
                    ++nb;
            }
          //  std::cout<<std::endl;
                //m_pairpoids.push_back({sp1,sp2});
                m_sommeP1.push_back(sp1);
               // m_sommeP2.push_back(sp2);
                //LA ON FAIT L'AFFICHAGE
                //m_vg[0]->dessinerGraphePareto(ficsvg, sp1*10, sp2*10, "rgb(255, 0, 0)");
         }while(std::next_permutation(vect.begin(),vect.end()));
    }
    for(auto ite = m_sommeP1.begin();ite!=m_sommeP1.end();ite++)
    {
      //std::cout << *ite <<std::endl;
    }
   // std::cout<<std::endl;

}

void Nuage::DijkstraGraphe(Svgfile& ficsvg)
{
   m_pairpoids.clear();

  int dis=0;
    m_sommeP2.clear();
    for (int i=0; i<m_vg[0]->getOrdre(); ++i)
    {
        dis = m_vg[0]->Dijkstra(i);

        /*std::cout<<std::endl;
        std::cout<<"fini pour sommet "<< i<<std::endl;
        std::cout<<std::endl;*/
        m_pairpoids.push_back({m_sommeP1[i],dis});
        m_sommeP2.push_back(dis);

    }

    int i =0;
    for (const auto& h : m_sommeP1)
    {

        m_vg[0]->dessinerGraphePareto(ficsvg,m_pairpoids[i].second*10,m_pairpoids[i].first*10,"rgb(255, 0, 0)");
       // std::cout<<"poids 2 : "<< m_sommeP2[i]<<std::endl;
        //std::cout<<"poids 1 : "<< m_sommeP1[i]<<std::endl;

        ++i;
    }
  //  m_sommeP2.clear();



}




void Nuage::paretoDij(Svgfile& ficsvg)
{
    //ON LE FAIT BOUCLER POUR TOUS LES GRAPHES DE NOTRE VECTEUR
    int pt_origine=0;
    int c =0;
    std::pair<int, int> tmp_pto;
    int tmp =sqrt(pow(m_sommeP1[0],2)+pow(m_sommeP2[0],2));

    for(size_t i=0;i<m_sommeP1.size();i++)
    {

        pt_origine = sqrt(pow(m_sommeP1[i],2)+pow(m_sommeP2[i],2));

        if(pt_origine<tmp)
        {
            tmp = pt_origine;
            c=1;

        }
      //std::cout<<"pto"<<pt_origine<<std::endl;
    }
   /* std::cout<<std::endl;
    std::cout<<"c"<<c<<std::endl;*/
    tmp_pto=m_pairpoids[c];
    //std::cout<<tmp<<std::endl;
    m_vg[0]->dessinerGraphePareto(ficsvg,m_pairpoids[c].first*10, m_pairpoids[c].second*10,"rgb(0, 255, 0)");


    std::sort(m_pairpoids.begin(),m_pairpoids.end(), [](std::pair<int, int> pair1, std::pair<int,int> pair2)
   {return pair1.first < pair2.first;} );


    std::pair<int,int> tmpair = tmp_pto;
   for (const auto& h : m_pairpoids)
   {
         //std::cout<<h.first<<std::endl;
         if (h.first > tmp_pto.first)
         {
           if (h.second < tmpair.second)
           {
             tmpair = h;
             m_vg[0]->dessinerGraphePareto(ficsvg,tmpair.first*10,tmpair.second*10,"rgb(0, 255, 0)");
           }
         }

     }

     std::sort(m_pairpoids.begin(),m_pairpoids.end(), [](std::pair<int, int> pair1, std::pair<int,int> pair2)
    {return pair1.second < pair2.second;} );

    tmpair = tmp_pto;


    for (const auto& h : m_pairpoids)
    {
      //std::cout<<h.second<<std::endl;
      if (h.second >tmp_pto.second)
      {
        if (h.first <tmpair.first)
        {
          tmpair = h;
          m_vg[0]->dessinerGraphePareto(ficsvg,tmpair.first*10,tmpair.second*10,"rgb(0, 255, 0)");
        }
      }

    }

}

void Nuage::pareto(Svgfile& ficsvg)
{
    //ON LE FAIT BOUCLER POUR TOUS LES GRAPHES DE NOTRE VECTEUR
    int pt_origine=0;
    int c =0;
    std::pair<int, int> tmp_pto;
    int tmp =sqrt(pow(m_sommeP1[0],2)+pow(m_sommeP2[0],2));

    for(size_t i=0;i<m_sommeP1.size();i++)
    {

        pt_origine = sqrt(pow(m_sommeP1[i],2)+pow(m_sommeP2[i],2));

        if(pt_origine<tmp)
        {
            tmp = pt_origine;
            c=i;

        }
      //std::cout<<"pto"<<pt_origine<<std::endl;
    }
   /* std::cout<<std::endl;
    std::cout<<"c"<<c<<std::endl;*/
    tmp_pto=m_pairpoids[c];
    //std::cout<<tmp<<std::endl;
    m_vg[0]->dessinerGraphePareto(ficsvg,m_pairpoids[c].first*10, m_pairpoids[c].second*10,"rgb(0, 255, 0)");


    std::sort(m_pairpoids.begin(),m_pairpoids.end(), [](std::pair<int, int> pair1, std::pair<int,int> pair2)
   {return pair1.first < pair2.first;} );


 std::pair<int,int> tmpair = tmp_pto;
   for (const auto& h : m_pairpoids)
   {
         //std::cout<<h.first<<std::endl;
         if (h.first > tmp_pto.first)
         {
           if (h.second < tmpair.second)
           {
             tmpair = h;
             m_vg[0]->dessinerGraphePareto(ficsvg,tmpair.first*10,tmpair.second*10,"rgb(0, 255, 0)");
           }
         }

     }

     std::sort(m_pairpoids.begin(),m_pairpoids.end(), [](std::pair<int, int> pair1, std::pair<int,int> pair2)
    {return pair1.second < pair2.second;} );

    tmpair = tmp_pto;


    for (const auto& h : m_pairpoids)
    {
      //std::cout<<h.second<<std::endl;
      if (h.second >tmp_pto.second)
      {
        if (h.first <tmpair.first)
        {
          tmpair = h;
          m_vg[0]->dessinerGraphePareto(ficsvg,tmpair.first*10,tmpair.second*10,"rgb(0, 255, 0)");
        }
      }

    }
    m_pairpoids.clear();
    m_sommeP1.clear();
    m_sommeP2.clear();
}



Nuage::~Nuage()

{   //dtor
}
