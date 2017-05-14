%{
#include <iostream>
%}

WORD [:alpha:][:alnum:]*

%%

[ \t]   { }
{WORD}
.       { std::cout << "Error" << std::endl; }

