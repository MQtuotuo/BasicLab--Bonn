#ifndef MODELING_H
#define MODELING_H

#include "Atrributes.h"
#include "Source.h"
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
using namespace attribute;
using namespace std;
namespace model
{
	class Modelling
	{
	private:
		// --- Variables ----------------------
		attribute::Symbol* tree;

		// --- Methods ------------------------
		attribute::Symbol* GenerateTestData();
	public:
		Modelling ();
		~Modelling();
		std::map <std::string, std::vector<int>> map1;
		std::map <int, Symbol>map2;
        void init();
        void print(Symbol* item);
        void printTree();
		void nullFunction(vector<string>childSymbolNames, Symbol* Parent);
		void comp(std::vector<std::string> childSymbolNames, Symbol* Parent);
		void insertMap1(int id, std::string symbolName);
		void addChildren(int id);
		void subDiv(std::vector<std::string> parameterValues, std::vector<std::string> childSymbolNames, Symbol* Parent);
		void repeat(std::vector<std::string> parameterValues, std::vector<std::string> childSymbolNames, Symbol* Parent);
		void S(std::vector<std::string> parameterValues, std::vector<std::string> childSymbolNames, Symbol* Parent);
		int nextInt(std::string s);
		double nextDouble(std::string s);

		void Model(std::unordered_map < std::string, std::vector<attribute::Rule>> ruleSet);
		attribute::Symbol* GetDeviationTree() {
			if (USE_TEST_DATA)
				return GenerateTestData();
			else
				return tree;
		}
	};
}

#endif
