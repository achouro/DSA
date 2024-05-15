#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int get_index_in_symbol(char s){
  switch(s){
    case 'A': return 0;
    case 'C': return 1;
    case 'G': return 2;
    case 'T': return 3;
    default : return 4;} }

int get_index_in_right_column(vector<int>& symbol,char s, int count){
  switch(s){
    case 'A': return count;
    case 'C': return symbol[0] +count;
    case 'G': return symbol[1] +symbol[0] +count;
    case 'T': return symbol[2] +symbol[1] +symbol[0] +count;
    default : return 0;} }

string BWT_inverted(string text){
  if(text.size()==1) return text;

  vector<int> symbol(5,0);
  vector<int> indices(text.size(),0);

  auto* iptr=&indices[0];
  auto* sptr=text.c_str();

  while(*sptr)  *iptr++= ++symbol[get_index_in_symbol(*sptr++)];

  auto rsize=text.size();

  char r[rsize +1];
  r[rsize]='\0';

  char s=text[0];
  int  j=indices[0];
  int  k=text.size()-1;

  r[k--]='$'; r[k--]=s;

  for(int i=2, itres=text.size()-i; itres--;++i){
    int index_inrc=get_index_in_right_column(symbol, s,j);

    r[k--]=text[index_inrc];
    j=indices[index_inrc];
    s=r[k+1];}
  return r;}

int main(){
  string text;
  cin>> text;

  auto result =BWT_inverted(text);
  cout<< result;
 
  return 0;
}



