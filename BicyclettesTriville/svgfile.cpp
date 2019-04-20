#include "svgfile.h"
#include <iostream>
#include <sstream>
#include <fstream>

const std::string svgHeader =
    "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
    "<svg xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" version=\"1.1\"  ";

const std::string svgEnding = "\n\n</svg>\n";

/// Effets "Boule en relief", voir donn�es � la fin de ce fichier
extern const std::string svgBallGradients;

std::set<std::string> Svgfile::s_openfiles;

Svgfile::Svgfile(std::string _filename, int _width, int _height) :
    m_filename{_filename}, m_width{_width}, m_height{_height}
{

    std::cout << "Opening SVG output file : "
              << m_filename << std::endl;

    if ( s_openfiles.count(m_filename) )
        throw std::runtime_error( "File " + m_filename + " already open !" );

    m_ostrm.open(m_filename);
    s_openfiles.insert(m_filename);

    if (!m_ostrm)
    {
        std::cout << "Problem opening " << m_filename << std::endl;
        throw std::runtime_error("Could not open file " + m_filename );
    }

    std::cout << "OK" << std::endl;

    // Writing the header into the SVG file
    m_ostrm << svgHeader;
    m_ostrm << "width=\"" << m_width << "\" height=\"" << m_height << "\">\n\n";
}

Svgfile::~Svgfile()
{
    // Writing the gradients into the SVG file
    m_ostrm << svgBallGradients;

    // Writing the ending into the SVG file
    m_ostrm << svgEnding;

    // Removing this file from the list of open files
    s_openfiles.erase(m_filename);

    // No need to explicitly close the ofstream object (automatic upon destruction)
}

// Helper templated function
//On ne pr�cise pas le type
template<typename T>
std::string attrib(std::string name, T val)
{
    std::ostringstream oss;
    oss << name << "=\"" << val << "\" ";
    return oss.str();
}

void Svgfile::addDisk(double x, double y, double r, std::string color)
{
    m_ostrm << "<circle "
            << attrib("cx", x)
            << attrib("cy", y)
            << attrib("r",  r)
            << attrib("fill", fillBallColor(color) )
            << "/>\n";
}

void Svgfile::addLine(double x1, double y1, double x2, double y2, std::string color)
{
    m_ostrm << "<line "
            << attrib("x1", x1)
            << attrib("y1", y1)
            << attrib("x2", x2)
            << attrib("y2", y2)
            << attrib("stroke", color)
            << "/>\n";
}

void Svgfile::addroute(double x1, double y1, double x2, double y2, std::string color)
{
    m_ostrm << "<line "
            << attrib("x1", x1)
            << attrib("y1", y1)
            << attrib("x2", x2)
            << attrib("y2", y2)
            << attrib("stroke", "black")
            << attrib("stroke-width",20)
            << "/>\n"
            << "<line "
            << attrib("x1", x1)
            << attrib("y1", y1)
            << attrib("x2", x2)
            << attrib("y2", y2)
            << attrib("stroke", color)
            << attrib("stroke-width",2)
            << attrib("stroke-dasharray",4)
            << "/>\n";
}


void Svgfile::addRectangle(double x, double y, std::string color)
{
       m_ostrm << "<rect "
               <<attrib("width", x)
               <<attrib("height", y)
               <<attrib("fill", color)
               <<  "/>";

}

void Svgfile::addRectanglePosition(double x, double y, double w, double h, std::string color)
{
       m_ostrm << "<rect "
               <<attrib("x", x)
               <<attrib("y", y)
               <<attrib("width", w)
               <<attrib("height", h)
               <<attrib("fill", color)
               <<  "/>";

}

void Svgfile::addPolygon(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, std::string colorFill, double thickness, std::string colorStroke)
{

    m_ostrm << "<polygon points=\" "
            << x1 << "," << y1 << " "
            << x2 << "," << y2 << " "
            << x3 << "," << y3 << " "
            << x4 << "," << y4 << " "
            << "\" style=\"fill:" << colorFill
            << ";stroke:" << colorStroke
            << ";stroke-width:" << thickness
            << "\" />\n";
}

void Svgfile::lireSVG(std::string fichierNom) ///RESSOURCES : Projet INFO 1
{

    std::ifstream file (fichierNom.c_str(), std::ios::in);
    std::string contenu;

    if(file)
    {
        while(getline(file, contenu))
        {
            m_ostrm<< contenu << "\n";
        }
        file.close();
    }

    else
        std::cerr<< "ERREUR A L'OUVERTURE"<< std::endl;


            ///ICI FAIRE UN FOR POUR DEPLACER LES BLOCS DE PLUIE

}


void Svgfile::addCross(double x, double y, double span, std::string color)
{
    addLine(x-span, y-span, x+span, y+span, color);
    addLine(x-span, y+span, x+span, y-span, color);
}

void Svgfile::addText(double x, double y, std::string text, std::string color)
{
    /// <text x="180" y="60">Un texte</text>
    m_ostrm << "<text "
            << attrib("x", x)
            << attrib("y", y)
            << attrib("fill", color)
            << ">" << text << "</text>\n";
}


void Svgfile::addText(double x, double y, double val, std::string color)
{
    std::ostringstream oss;
    oss << val;
    addText(x, y, oss.str(), color);
}

void Svgfile::addGrid(double span, bool numbering, std::string color)
{
    double y=0;
    while (y<=m_height)
    {
        addLine(0, y, m_width, y, color);
        if (numbering)
            addText(5, y-5, y, color);
        y+=span;
    }

    double x=0;
    while (x<=m_width)
    {
        addLine(x, 0, x, m_height, color);
        if (numbering)
            addText(x+5, 15, x, color);
        x+=span;
    }
}


void Svgfile::PlaneteAnime(double planetex, double planetey, double rayon)
{
    m_ostrm<<"<circle "
           <<attrib("cx", planetex)
           <<attrib("cy", planetey)
           <<attrib("r", rayon)
           <<" /> \n"
           <<"<g "
           <<attrib("transform", " matrix(0.866, -0.5, 0.25, 0.433, 800, 80)")
           <<" >\n"
           <<"<path "
           <<attrib("d","M 0,70 A 65,70 0 0,0 65,0 5,5 0 0,1 75,0 75,70 0 0,1 0,70Z")
           <<attrib("fill", "rgb(255,0,0)")
           <<" >\n"
           <<"< animateTransform"
           <<attrib("attributeName","transform")
           <<attrib("type", "rotate")
           <<attrib("from", "360 0 0")
           <<attrib("to", "0 0 0")
           <<attrib("dur","1s")
           <<attrib("repeatCount", "indefinite")
           <<" /> \n"
           <<"</path>"
           <<"</g>"
           <<"<path "
           <<attrib("d", "M 50,0 A 50,50 0 0,0 -50,0Z")
           <<attrib("transform","matrix(0.866, -0.5, 0.5, 0.866,")
           << planetex <<", "<< rayon<<")"
           <<" /> \n";
}




std::string makeRGB(int r, int g, int b)
{
    std::ostringstream oss;
    oss << "rgb(" << r << "," << g << "," << b << ")";
    return oss.str();
}

std::string fillBallColor(std::string col)
{
    if ( col.size()>4 && col.substr(col.size()-4) == "ball" )
        col =   "url(#" + col + ")";

    return col;
}


/// Horrible bricolage : ces donn�es devraient soit �tre dans un fichier auxiliaire
/// ( c'�tait l'approche initiale qui marchait bien sur Firefox mais pas sur les autres )
/// soit g�n�r�es dynamiquement en fonction des besoins (couleurs param�trables...)
/// On fera mieux l'an prochain !
extern const std::string svgBallGradients =
"  \n\n<defs>\n"
"    <radialGradient id=\"redball\" cx=\"30%\" cy=\"30%\" r=\"100%\" fx=\"30%\" fy=\"30%\">\n"
"      <stop offset=\"0%\" style=\"stop-color:rgb(255,250,250)\" />\n"
"      <stop offset=\"3%\" style=\"stop-color:rgb(255,250,250)\" />\n"
"      <stop offset=\"7%\" style=\"stop-color:rgb(255,160,160)\" />\n"
"      <stop offset=\"70%\" style=\"stop-color:rgb(255,0,0)\" />\n"
"      <stop offset=\"100%\" style=\"stop-color:rgb(255,0,0)\" />\n"
"    </radialGradient>\n"
"    <radialGradient id=\"greenball\" cx=\"30%\" cy=\"30%\" r=\"100%\" fx=\"30%\" fy=\"30%\">\n"
"      <stop offset=\"0%\" style=\"stop-color:rgb(250,255,250)\" />\n"
"      <stop offset=\"3%\" style=\"stop-color:rgb(250,255,250)\" />\n"
"      <stop offset=\"7%\" style=\"stop-color:rgb(160,255,160)\" />\n"
"      <stop offset=\"70%\" style=\"stop-color:rgb(0,255,0)\" />\n"
"      <stop offset=\"100%\" style=\"stop-color:rgb(0,255,0)\" />\n"
"    </radialGradient>\n"
"    <radialGradient id=\"blueball\" cx=\"30%\" cy=\"30%\" r=\"100%\" fx=\"30%\" fy=\"30%\">\n"
"      <stop offset=\"0%\" style=\"stop-color:rgb(250,250,255)\" />\n"
"      <stop offset=\"3%\" style=\"stop-color:rgb(250,250,255)\" />\n"
"      <stop offset=\"7%\" style=\"stop-color:rgb(160,160,255)\" />\n"
"      <stop offset=\"70%\" style=\"stop-color:rgb(0,0,255)\" />\n"
"      <stop offset=\"100%\" style=\"stop-color:rgb(0,255,0)\" />\n"
"    </radialGradient>\n"
"    <radialGradient id=\"yellowball\" cx=\"30%\" cy=\"30%\" r=\"100%\" fx=\"30%\" fy=\"30%\">\n"
"      <stop offset=\"0%\" style=\"stop-color:rgb(255,255,250)\" />\n"
"      <stop offset=\"3%\" style=\"stop-color:rgb(255,255,250)\" />\n"
"      <stop offset=\"7%\" style=\"stop-color:rgb(255,255,160)\" />\n"
"      <stop offset=\"70%\" style=\"stop-color:rgb(255,255,0)\" />\n"
"      <stop offset=\"100%\" style=\"stop-color:rgb(255,255,0)\" />\n"
"    </radialGradient>\n"
"    <radialGradient id=\"greyball\" cx=\"30%\" cy=\"30%\" r=\"100%\" fx=\"30%\" fy=\"30%\">\n"
"      <stop offset=\"0%\" style=\"stop-color:rgb(250,250,250)\" />\n"
"      <stop offset=\"3%\" style=\"stop-color:rgb(250,250,250)\" />\n"
"      <stop offset=\"7%\" style=\"stop-color:rgb(160,160,160)\" />\n"
"      <stop offset=\"70%\" style=\"stop-color:rgb(100,100,100)\" />\n"
"      <stop offset=\"100%\" style=\"stop-color:rgb(100,100,100)\" />\n"
"    </radialGradient>\n"
"  </defs>\n";


