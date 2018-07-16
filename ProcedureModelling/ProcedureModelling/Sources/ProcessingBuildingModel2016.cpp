// ProcessingBuildingModel2016.cpp : Defines the entry point for the console application.
//

// BuildingModel 2016.cpp : Defines the entry point for the console application.
//


#include "Parsing.h"
#include "Model.h"
#include "Render.h"

int main(int argc, char** argv)
{
	parse::Parsing parser;
	model::Modelling modeler;
	rend::Rendering renderer;

	parser.Parse();
	modeler.Model(parser.GetRuleSet());
	renderer.Render(modeler.GetDeviationTree());
}