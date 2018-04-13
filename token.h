/*
 #######################
  Parser aus Vorlesung:
  (12.12.2017 - BSP 9)
 #######################

*/

#include "att.h"
#include "txt.h"
//using namespace std;

class ClToken
   {
public:
   ClToken();
   char *name() { return tokenName; }
   ClToken *child() { return tokenChild; }
   ClToken *sibling() { return tokenSibling; }
   char *inhalt() { return tokenInhalt; }
   void druckeToken(ClText ObText, string datna);
   void search(string searchCat, string searchCon);
   int getToken(ifstream &datei);
   ClattToken att;


private:
   void cleanToken();
   int fillToken(int mode);
   char tokenName[64];
   ClToken *tokenChild;
   ClToken *tokenSibling;
   char *tokenInhalt;

   } ;

enum zustand { istStartTag, istEndTag } ;
