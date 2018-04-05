/*
 #######################
  Parser aus Vorlesung:
  (12.12.2017 - BSP 9)
 #######################
 */
class ClattToken
   {
private:
   int anzahlAtt;
   char *attName[10];
   char *attValue[10];
public:
   int getAttList(char *eingabe);
   char *zeigeAttName(int id) {return attName[id];}
   char *zeigeAttWert(int id) {return attValue[id];}
   int zahlAtt() {return anzahlAtt;}
   };
