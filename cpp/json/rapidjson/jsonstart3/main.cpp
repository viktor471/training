#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <map>
#include "shortenings.h"


int main() {

   SCOPE_OPENING    
   
	// 1. Parse a JSON string into DOM.
   Document d;
   d.Parse(json);

   //FILE* fp = fopen("first_json.json", "w");
   std::ofstream ofs("first_json.json");
   OStreamWrapper osw(ofs);
   
   Writer< OStreamWrapper> writer_out(osw);
   d.Accept( writer_out );
   return 0;
}
