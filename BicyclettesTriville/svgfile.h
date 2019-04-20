#ifndef SVGFILE_H_INCLUDED
#define SVGFILE_H_INCLUDED


#include <string>
#include <fstream>
#include <set>

#define LargeurCiel 1510
#define LongueurCiel 780

constexpr char defcol[] = "black";

class Svgfile
{
    private:
        std::string m_filename;
        std::ofstream m_ostrm;
        int m_width;
        int m_height;

        // Pour �viter les ouverture multiples
        static std::set<std::string> s_openfiles;

    public:

        ///ICI SONT MODIFIER LES LA LARGEUR ET LONGUEUR DE LA FENETRE
        Svgfile(std::string _filename = "output.svg", int _width=LargeurCiel, int _height=LongueurCiel);
        ~Svgfile();

        void addDisk(double x, double y, double r, std::string color=defcol);
        void addLine(double x1, double y1, double x2, double y2, std::string color=defcol);
        void addCross(double x, double y, double span, std::string color=defcol);
        void PlaneteAnime(double planetex, double planetey, double rayon);
        void addText(double x, double y, std::string text, std::string color=defcol);
        void addText(double x, double y, double val, std::string color=defcol);

        ///TRUE ou FALSE pour afficher les nbr abscisses et ordonn�es

        void addGrid(double span=50.0, bool numbering=true, std::string color="grey");

        void addEllipse(double cx, double cy, double rx, double ry, std::string color, std::string filter);
        void addRectangle(double x, double y, std::string color);
        void addRectanglePosition(double x, double y, double w, double h, std::string color);
        void addPolygon(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, std::string colorFill,  double thickness, std::string colorStroke);
        void lireSVG(std::string fichierNom);
        void addroute(double x1, double y1, double x2, double y2, std::string color);
};


std::string makeRGB(int r, int g, int b);

std::string fillBallColor(std::string col);
#endif // SVGFILE_H_INCLUDED
