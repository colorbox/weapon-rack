
string replace(string target, string finder, string replacement){
  string result=string(target);

  string::size_type pos=0;

  pos = result.find(finder, pos);
  while(pos != string::npos){
    result.replace(pos, finder.length(), replacement);
    pos = result.find(finder);
  }

  return result;
}
