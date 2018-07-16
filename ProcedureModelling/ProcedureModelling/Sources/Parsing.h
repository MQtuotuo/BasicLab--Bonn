#ifndef PARSEING_H
#define PARSEING_H

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Atrributes.h"
#include "Source.h"
#include <vector>
#include <unordered_map>
#include <string>

namespace parse
{
	class Parsing
	{
	private:
		// --- Variables ----------------------
		// pair < SymbolID, vector<Node> >
		std::unordered_map < std::string, std::vector<attribute::Rule>> ruleSet;

		// --- Methods ------------------------
		std::unordered_map < std::string, std::vector<attribute::Rule>> GenerateTestData();
	public:
		Parsing();
		~Parsing();
		void Parse();
		std::unordered_map < std::string, std::vector<attribute::Rule>> GetRuleSet() {
			if (USE_TEST_DATA)
				return GenerateTestData();
			else
				return ruleSet;
		}

	};
}

#endif