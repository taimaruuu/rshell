#ifndef __PARSE_H__
#define __PARSE_H__

#include <string>
#include<boost/tokenizer.hpp>

typedef boost::tokenizer<boost::char_separator<char> > tokenizer;

void parse(string &input, vector<string> &argsList){
  vector<string> cast(1);

  tokenizer token(input);
  tokenizer::iterator it = token.begin();
    int i = 0;
    while (it != token.end()) {
      cast.at(0) = *it;
      if(cast.at(0) == "#"){
        break;
      }
      if(cast.at(0) == "&&"){

      }
      if(cast.at(0) == "||"){

      }
      if(cast.at(0) == ";"){

      }
      argsList.push_back(cast.at(0));
      cout << "argslist: " << argsList.at(i) << " ";
      it++;
      i++;
    }
}

#endif
