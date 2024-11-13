#include "set.h"

#include <fstream>
#include <ios>
#include <sstream>
#include <string>

using namespace std;

string toStr(Set &set) {
  string str;
  for (size_t i = 0; i < SIZE; i++) {
    if (set.node[i]) {
      Node *current = set.node[i];
      while (current) {
        str += current->value + ' ';
        current = current->next;
      }
    }
  }

  return str;
}

void processLine(const string &path, const string &setName, Set &set,
                 bool repl) {
  string line;
  string word;
  ifstream file(path);
  ofstream tFile("tmp.txt");

  while (getline(file, line)) {
    istringstream stream(line);
    stream >> word;
    if (word == setName && repl) {
      string str = toStr(set);
      if (str[0]) {
        tFile << word + " " + str << endl;
      }
    } else if (word == setName && !repl) {
      continue;
    } else {
      tFile << line << endl;
    }
  }

  file.close();
  tFile.close();

  remove(path.c_str());
  rename("tmp.txt", path.c_str());
}

Set *parse(const string &path, const string &setName) {
  string line;
  string word;
  ifstream file(path);

  while (word != setName && getline(file, line)) {
    istringstream stream(line);
    stream >> word;
  }

  file.close();

  if (!line[0]) {
    ofstream file(path, ios::app);
    file << setName << endl;
    file.close();
  }

  Set *set = new Set;
  istringstream stream(line);
  stream >> word;

  while (stream >> word) {
    set->insert(word);
  }

  return set;
}

void checkVal(istringstream &stream, string &word) {
  if (!(stream >> word)) {
    throw runtime_error("Err: not enough parametrs");
  }
}

void setsOp(const string &path, const string &fstName, const string &scndName,
            Set &set1, Set *(*op)(Set &, Set &)) {

  Set *set2 = parse(path, scndName);
  Set *set = op(set1, *set2);

  processLine(path, scndName, set1, false);
  processLine(path, fstName, *set, true);

  delete set2;
  delete set;
}

void menu(const string &path, const string &query) {
  istringstream stream(query);
  string q;
  string setName;
  string word;

  stream >> q;
  if (!(stream >> setName)) {
    throw runtime_error("Err: you must specify the name of the set");
  }

  if (q == "SETADD" || q == "SETDEL" || q == "SETUNION" || q == "SETINT" ||
      q == "SETDIF" || q == "SET_AT) {
    checkVal(stream, word);
  } else if (q != "SETPRINT" && q != "SET_AT") {
    throw runtime_error("Err: wrong query");
  }

  Set *set1 = parse(path, setName);

  if (q == "SETADD") {
    set1->insert(word);
    processLine(path, setName, *set1, true);
  } else if (q == "SETDEL") {
    set1->remove(word);
    processLine(path, setName, *set1, true);
  } else if (q == "SET_AT") {
    cout << (set1->find(word) ? "True" : "False") << endl;
  } else if (q == "SETUNION") {
    setsOp(path, setName, word, *set1, setUnion);
  } else if (q == "SETINT") {
    setsOp(path, setName, word, *set1, setIntersection);
  } else if (q == "SETDIF") {
    setsOp(path, setName, word, *set1, setDifference);
  } else if (q == "SETPRINT") {
    cout << toStr(*set1) << endl;
  }

  delete set1;
}
