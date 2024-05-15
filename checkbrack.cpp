#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Bracket {
    Bracket(){};
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

string is_balanced(string text) {
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
          Bracket item;
          item.type=next;
          item.position=position;
          opening_brackets_stack.push(item);
            // Process opening bracket, write your code here
        }

        else if (next == ')' || next == ']' || next == '}') {

          if (opening_brackets_stack.empty()) return std::to_string(position+1);
          Bracket taup=opening_brackets_stack.top();
          opening_brackets_stack.pop();

          if((taup.type== '(' && next !=')') || (taup.type== '[' && next != ']') ||(taup.type== '{' &&  next != '}')) return std::to_string(position+1);
            // Process closing bracket, write your code here
        }

    }
    
    return (opening_brackets_stack.empty() ? "Success" : std::to_string(opening_brackets_stack.top().position +1));
}
int main(){
    std::string text;
    getline(std::cin, text);

    cout<<is_balanced(text);
    // Printing answer, write your code here
    return 0;
}

