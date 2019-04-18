#include "Nuage.h"

Nuage::Nuage(Graphe* g)
{
    m_vg.push_back(g);
}

void Nuage::Kruskal(int p, Svgfile& fichier_svg, std::string fichier_1, std::string fichier_2)
{
    m_vg.push_back(new Graphe(fichier_1, fichier_2));

    m_vg[m_vg.size()-1]->kruskal(p);

    m_vg[m_vg.size()-1]->dessinerGrapheKruskal(fichier_svg, 500, p);

}
void Nuage::test()
{
     //m_vg[0]->toutesPossibilites();
}

void Nuage::bruteForce(Svgfile& ficsvg)
{

    std::vector<Arete*> va;
    std::vector<Sommet* > vs;
    va.clear();
    vs.clear();

    m_possibilite.push_back(m_vg[0]);

    int k = m_vg[0]->getTaille(); ///NOMBRE DARETE



    ///affiche toutes les combinaisons possibles : c-a-d 2^nbdaretes
    int n = m_vg[0]->getOrdre();/// NOMBRE DE SOMMET


    for(int i = 0; i<k;i++)
    { ///I = NOMBRE DARETE QUON GARDE POUR CET ESSAI
        std::vector<bool> vect(k,true);
        for(int j = 0; j< k-i-1;j++) ///J = LARRETE QUON ENLEVE MAINTENANT LA
            vect[j] = false;
        do{
            for (auto it=vect.begin(); it!=vect.end(); it++)
            {
              //  std::cout<<*it;
            }
            std::cout << std::endl;
         }while(std::next_permutation(vect.begin(),vect.end()));
    }
    std::cout<<std::endl;

    ///affiche toutes les combinaisons avec nbsommets-1 aretes mais pas forcement couvrantes : c-a-d pas forcement tous les sommets
    std::cout<<"toutes les combinaisons connexes mais pas forcement couvrantes sont :"<<std::endl;
    for(int i = n-1; i<k-1;i++)
    { ///I = NOMBRE DARETE QUON GARDE POUR CET ESSAI
        std::vector<bool> vect(k,true);
        for(int j = 0; j< k-i;j++) ///J = LARRETE QUON ENLEVE MAINTENANT LA
            vect[j] = false;
        do{
            for (auto it=vect.begin(); it!=vect.end(); it++)
            {
                //std::cout<<*it;
            }
            std::cout << std::endl;
         }while(std::next_permutation(vect.begin(),vect.end()));
    }
    std::cout<<std::endl; //A SUPPRIMER !!!!

    ///maintenant il faut verifier celles qui sont connexes et les eliminer de ces combinaisons
    std::cout<<"l espace de recherche est : "<<std::endl;
    for(int i = n-1; i<k-1;i++)
    { ///I = NOMBRE DARETE QUON GARDE POUR CET ESSAI
        std::vector<bool> vect(k,true);
        for(int j = 0; j< k-i;j++) ///J = LARRETE QUON ENLEVE MAINTENANT LA
            vect[j] = false;
        do{
            int nb = 0;
            for (auto it=vect.begin(); it!=vect.end(); it++)
            {

                    std::cout<<*it;
                    if (*it)
                        std::cout << "nb"<<nb<<std::endl;

                    va.push_back(m_vg[0]->getAindice(nb));

                    Graphe g0{va, m_vg[0]->getS()};
                   // m_possibilite.push_back(&g0);
                   //void Graphe::dessinerGraphePareto(Svgfile& fichiersvg, int m_p1, int m_p2)

                       double p1 = g0.sommePoids(1);
                       double p2 = g0.sommePoids(2);


                    g0.dessinerGraphePareto(ficsvg, p1, p2);

                    ++nb;
            }

         }while(std::next_permutation(vect.begin(),vect.end()));

    }

}






void Nuage::toutesPossibilites ()
 {

    std::vector<Arete*> va;
    std::vector<Sommet* > vs;

     ///On recupere les sommets du graphe original


    va.clear();
    vs.clear();

    ///toutes les combinaisons possibles : c-a-d 2^nbdaretes
    int k = m_vg[0]->getTaille(); ///NOMBRE DARETE

    for (int p = 0; p <pow(2, k); ++p)
    {
        for (int s = 0; s<m_vg[0]->getOrdre(); ++s)
            vs.push_back(m_vg[0]->getSindice(s));
    }

   // std::vector<bool> vect_tmp(k,true);


    for(int i = 0; i<k; i++)
    {
        ///I = NOMBRE DARETE QUON GARDE POUR CET ESSAI
        std::vector<bool> vect(k,true);

        for(int j = 0; j< k-i;j++)
        {
            vect[j] = false;///J = LARRETE QUON ENLEVE MAINTENANT LA
        }

        do{
            for (int s = 0; s<m_vg[0]->getOrdre(); ++i)
                vs.push_back(m_vg[0]->getSindice(s));

            for (int n=0; n<m_vg[0]->getTaille(); ++n)
            {

                if (vect[n])
                {

                    va.push_back(m_vg[0]->getAindice(n));
                    std::cout<<"val A* "<<m_vg[0]->getAindice(n) <<std::endl;
                    std::cout<<"Coucou"<<std::endl;

                    //std::cout<<"vectA111 :"<< va[n] <<std::endl;
                }

            }

            // new Sommet{id,x,y}


            //std::cout <<"size"<< va_selec.size()<< std::endl;
            std::cout << std::endl;
         }while(std::next_permutation(vect.begin(),vect.end()));


        /* Graphe g {va, vs};
         m_vg.push_back(&g);*/


    }




 }

void Nuage::supPossibilte()
{
    int n = m_vg[0]->getOrdre(); /// NOMBRE DE SOMMET
    int k = m_vg[0]->getTaille(); ///NOMBRE DARETE
    for(int i = n-4; i<k;i++)
    {
            ///affiche toutes les combinaisons avec nbsommets-1 aretes mais pas forcement couvrantes : c-a-d pas forcement tous les sommets
        std::cout<<"toutes les combinaisons connexes mais pas forcement couvrantes sont :"<<std::endl;
        for(int i = n-1; i<k-1;i++){ ///I = NOMBRE DARETE QUON GARDE POUR CET ESSAI
            std::vector<bool> vect(k,true);
            for(int j = 0; j< k-i;j++) ///J = LARRETE QUON ENLEVE MAINTENANT LA
                vect[j] = false;
            do{
                for (auto it=vect.begin(); it!=vect.end(); it++)
                {
                    std::cout<<*it;
                }
                std::cout << std::endl;
             }while(std::next_permutation(vect.begin(),vect.end()));
        }
        std::cout<<std::endl; //A SUPPRIMER !!!!

        ///maintenant il faut verifier celles qui sont connexes et les eliminer de ces combinaisons
        std::cout<<"l espace de recherche est : "<<std::endl;
        for(int i = n-1; i<k-1;i++)
        { ///I = NOMBRE DARETE QUON GARDE POUR CET ESSAI
            std::vector<bool> vect(k,true);
            for(int j = 0; j< k-i;j++) ///J = LARRETE QUON ENLEVE MAINTENANT LA
                vect[j] = false;
            do{
                for (auto it=vect.begin(); it!=vect.end(); it++)
                {
                    std::cout<<*it;
                }
                std::cout << std::endl;
             }while(std::next_permutation(vect.begin(),vect.end()));

        }


    }
}



void Nuage::Possibilites ()
 {
    int n = 0;
    std::vector<Sommet* > vs = m_vg[0]->getS(); ///On recupere les sommets du graphe original
    std::vector<Arete* > va ;
   // va = m_vg[0]->toutesPossibilites();

    for (int i = 0; i < pow(2, m_vg[0]->getTaille()); ++i)
        n = i+1; //Ca commence de 0

    std::cout<<"il y a "<<n<<" nombre de possiblite"<<std::endl;

    for (size_t i = 0; i < pow(2, m_vg[0]->getTaille()); ++i)
    {
        ///IL FAUT CHANGER LES ARETE A CHAQUE TOUR
        for (int n= 1; n<m_vg[0]->getOrdre(); ++n)
        {
            std::cout<<"n"<<n<<std::endl;
            Graphe g {va, vs};
            //m_vg[n] = &g;
            m_vg.push_back(&g);
        }
        std::cout<<"i"<<i<<std::endl;
    }

    m_vg[3]->afficher();
 }

void Nuage::pareto(Svgfile& ficsvg)
{
   // m_vg[3]->afficher();
    //ON LE FAIT BOUCLER POUR TOUS LES GRAPHES DE NOTRE VECTEUR
    /**ON FAIT LA SOMME DES POIDS POUR P1 PUIS POUR P2**/
    for (size_t i = 0; i <m_possibilite.size(); ++i)
    {
       double p1 = m_possibilite[i]->sommePoids(1);
       double p2 = m_possibilite[i]->sommePoids(2);

       std::cout<<"i"<<i<<std::endl;

        m_possibilite[i]->dessinerGraphePareto(ficsvg,p1,p2);
    }


}




Nuage::~Nuage()

{   //dtor
}
