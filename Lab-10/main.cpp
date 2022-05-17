#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;
using std::exception;
using std::function;
using std::getline;
using std::map;
using std::sort;
using std::string;
using std::vector;

class MyException : public exception {
 private:
  string reason;

 public:
  MyException(string reason) : reason(reason) {}
  const char* what() const throw() { return reason.c_str(); }
};

class OpenFileException : public MyException {
 public:
  OpenFileException(string filename)
      : MyException(string("can't open file ") + filename){};
};

class ReadFileException : public MyException {
 public:
  ReadFileException(string filename)
      : MyException(string("can't read file ") + filename){};
};

class WriteFileException : public MyException {
 public:
  WriteFileException(string filename)
      : MyException(string("can't write file ") + filename){};
};

// the CommandManager class should implement a mini terminal that receive
// commands and dispatches them. example: copy a.jpg b.jpg this will search the
// map for a "copy" command, and if it finds it, it will invoke its callback
// with a vector made of {"a.jpg", "b.jpg"} no global variables allowed

class CommandManager {
 private:
  map<string, function<void(vector<string>)>> commands;

 public:
  void add(string name, function<void(vector<string>)> fn);

  // run shall read a line from stdin in a loop, split it by whitespaces.
  // the first word will be the command name. if no word has been found, it will
  // do nothing then it will search the map for the name, and it will invoke the
  // callback if it founds it or it will show a message if it can't find it the
  // args for the callback will not contain the command name if the `stop`
  // command is found, the function will return try doing this yourself; if you
  // spent too much time on this, look at
  // https://gist.github.com/xTachyon/9e698a20ce6dfcae9a483b28778af9fb
  void run();
};

void CommandManager::add(string name, function<void(vector<string>)> fn) {
  commands[name] = fn;
}

void CommandManager::run() {
  string command;
  vector<string> arguments;

  while (true) {
    getline(cin, command);

    if (command == "stop") {
      return;
    }

    arguments.clear();

    const char* separators = " ";
    char* p = strtok(&command[0], separators);
    while (p) {
      arguments.push_back(p);
      p = strtok(nullptr, separators);
    }

    if (arguments.size() == 0) {
      continue;
    }

    auto it = commands.find(arguments[0]);
    if (it == commands.end()) {
      printf("command does not exist\n");
      continue;
    }

    arguments.erase(arguments.begin());

    try {
      it->second(arguments);
    } catch (exception& e) {
      printf("Exception occurred: %s\n", e.what());
    }
  }
}

int main() {
  CommandManager manager;
  // number_of_errors represents the number of IO errors (eg. file errors) that
  // happened in the commands this is only relevant for the append and copy
  // commands
  // unsigned number_of_errors = 0;

  // prints pong!
  auto ping = [](vector<string> args) { printf("pong!\n"); };
  manager.add("ping", ping);

  // prints the number of arguments it received
  // `count a b c` -> will print `counted 3 args`

  auto count = [](vector<string> args) {
    printf("counted %lu args\n", args.size());
  };

  manager.add("count", count);

  // the first argument will be treated as a file name
  // the rest of the arguments will be appended to that file with a space as
  // delimiter remember to count the errors, if any
  auto append = [](vector<string> args) {
    if (args.empty()) {
      throw std::runtime_error("no filename was given");
    }

    FILE* file = fopen(args[0].c_str(), "a");

    if (!file) {
      fclose(file);
      throw OpenFileException(args[0]);
    }

    for (int i = 1; i < args.size(); i++) {
      fprintf(file, "%s ", args[i].c_str());
    }

    printf("done\n");

    fclose(file);
  };

  manager.add("append", append);

  // will print the number of times the command was called
  // do not capture any reference for this lambda

  auto times = [count = 0](vector<string> args) mutable {
    count++;

    printf("count is %d\n", count);
  };

  manager.add("times", times);

  // copy a file; args[0] will provide the source, and args[1] the destination
  // make sure it works with binary files (test it with an image)
  // remember to count the errors, if any
  auto copy = [](vector<string> args) {
    if (args.size() < 2) {
      throw std::runtime_error("not enough arguments given");
    }
  };

  manager.add("copy", copy);

  auto alloc = [](vector<string> args) {
    int x = -1;
    char* allocated_string = new char[x];

    allocated_string[0] = 'a';
  };

  manager.add("alloc", alloc);

  // will sort the arguments by size
  // `sort_size abc a 1234` -> will print `a abc 1234`
  // use std::sort with a lambda comparator to sort
  // and std::for_each with a lambda to print afterwards

  auto sort_size = [](vector<string> args) {};

  manager.add("sort_size", sort_size);

  // add one more command of anything you'd like

  manager.run();

  // printf("number of errors: %u\ndone!\n", number_of_errors);
}