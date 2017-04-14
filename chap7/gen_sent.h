#ifndef GUARD_gen_sent_h
#define GUARD_gen_sent_h

// gen_sent.h
#include<vector>
#include<string>
#include<iostream>
#include <map>
#include <list>

typedef std::list<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream&);
std::list<std::string> gen_sentence(const Grammar&);
bool bracketed(const std::string&);
void gen_aux(const Grammar&, const std::string&, std::list<std::string>&);
int nrand(int);



#endif