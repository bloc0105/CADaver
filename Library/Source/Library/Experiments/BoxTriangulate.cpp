#include "BoxTriangulate.h"

#include <BRepMesh_IncrementalMesh.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <Poly_Array1OfTriangle.hxx>
#include <Poly_Triangulation.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <iostream>

//gemini ai generated example for using BRepMesh_IncrementalMesh  

BoxTriangulator::BoxTriangulator()
{
    // 1. Erstelle eine einfache B-Rep-Form (hier ein Würfel)
    BRepPrimAPI_MakeBox boxMaker(gp_Pnt(0, 0, 0), 2, 3, 4); // Korrigierte Klasse
    TopoDS_Shape        boxShape = boxMaker.Shape();
}

void BoxTriangulator::triangulate(const TopoDS_Shape& boxShape)
{
    // 2. Erstelle ein Objekt der Klasse BRepMesh_IncrementalMesh
    //    und initialisiere es mit der Form und einer maximalen Durchbiegung (Deflection)
    //    Die Durchbiegung steuert die Feinheit des Netzes. Ein kleinerer Wert
    //    führt zu einem feineren Netz, dauert aber länger.
    BRepMesh_IncrementalMesh mesher(boxShape, 0.1);

    // 3. Führe die Vernetzung durch
    mesher.Perform();

    // 4. Überprüfe, ob die Vernetzung erfolgreich war
    if (mesher.IsDone())
    {
        std::cout << "Vernetzung erfolgreich!" << std::endl;

        // 5. Iteriere über die Flächen des Körpers und hole die zugehörigen Triangulierungen
        TopExp_Explorer faceExplorer(boxShape, TopAbs_FACE);
        for (; faceExplorer.More(); faceExplorer.Next())
        {
            TopoDS_Face     currentFace              = TopoDS::Face(faceExplorer.Current());
            TopLoc_Location l                        = TopLoc_Location();
            Handle(Poly_Triangulation) triangulation = BRep_Tool::Triangulation(currentFace, l);

            if (!triangulation.IsNull())
            {
                std::cout << "\nTriangulierung für eine Fläche gefunden:" << std::endl;
                int nbNodes     = triangulation->NbNodes();
                int nbTriangles = triangulation->NbTriangles();
                std::cout << "  Anzahl Knoten: " << nbNodes << std::endl;
                std::cout << "  Anzahl Dreiecke: " << nbTriangles << std::endl;

                // Optional: Zugriff auf Knoten und Dreiecke
                // for (int i = 1; i <= nbNodes; ++i) {
                //   gp_Pnt vertex = triangulation->Node(i);
                //   std::cout << "    Knoten " << i << ": (" << vertex.X() << ", " << vertex.Y() << ", " << vertex.Z() << ")" << std::endl;
                // }
                // for (int i = 1; i <= nbTriangles; ++i) {
                //   Poly_Triangle triangle = triangulation->Triangle(i);
                //   std::cout << "    Dreieck " << i << ": " << triangle.Get()[0] << ", " << triangle.Get()[1] << ", " << triangle.Get()[2] << std::endl;
                // }
            }
            else
            {
                std::cout << "\nKeine Triangulierung für eine Fläche gefunden." << std::endl;
            }
        }
    }
    else
    {
        std::cerr << "Fehler bei der Vernetzung!" << std::endl;
    }

}