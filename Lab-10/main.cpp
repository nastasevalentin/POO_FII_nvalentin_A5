// the CommandManager class should implement a mini terminal that receive commands and dispatches them.
// example: copy a.jpg b.jpg
// this will search the map for a "copy" command, and if it finds it, it will invoke its callback with a vector made of {"a.jpg", "b.jpg"}
// no global variables allowed
#include <map>
#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class CommandManager
{
private:
    map<string, function<void(vector<string>)>> commands;

public:
    void add(string name, function<void(vector<string>)> fn);

    // run shall read a line from stdin in a loop, split it by whitespaces.
    // the first word will be the command name. if no word has been found, it will do nothing
    // then it will search the map for the name, and it will invoke the callback if it founds it
    // or it will show a message if it can't find it
    // the args for the callback will not contain the command name
    // if the `stop` command is found, the function will return
    // try doing this yourself; if you spent too much time on this, look at https://gist.github.com/xTachyon/9e698a20ce6dfcae9a483b28778af9fb
    void run();
};

void CommandManager::add(string name, function<void(vector<string>)> fn)
{
    commands[name] = fn;
}

void CommandManager::run()
{
    string tmp;
    vector<string> args;

    while (true)
    {
        getline(cin, tmp);
        if (tmp == "stop")
            return;

        args.clear();
        auto ptr = strtok(&tmp[0], " ");

        while (ptr)
        {
            args.push_back(ptr);
            ptr = strtok(nullptr, " ");
        }

        if (args.empty())
        {
            continue;
        }
        auto it = commands.find(args[0]);
        if (it == commands.end())
        {
            printf("No commands with that name!\n");
            continue;
        }
        args.erase(args.begin());

        it->second(args);
    }
}

int main()
{
    CommandManager manager;
    // number_of_errors represents the number of IO errors (eg. file errors) that happened in the commands
    // this is only relevant for the append and copy commands
    unsigned number_of_errors = 0;

    // prints pong!
    auto ping = [](vector<string> args)
    { printf("pong!\n"); };
    manager.add("ping", ping);

    // prints the number of arguments it received
    // `count a b c` -> will print `counted 3 args`
    // auto count = ...;
    auto count = [](vector<string> args)
    { printf("counted %d args ", args.size()); };
    manager.add("count", count);

    auto append = [count = 0](vector<string> args){

    };

    // the first argument will be treated as a file name
    // the rest of the arguments will be appended to that file with a space as delimiter
    // remember to count the errors, if any
    // auto append = ...;
    // manager.add("append", append);

    // will print the number of times the command was called
    // do not capture any reference for this lambda
    // auto times = ...;
    // manager.add("times", times);

    // copy a file; args[0] will provide the source, and args[1] the destination
    // make sure it works with binary files (test it with an image)
    // remember to count the errors, if any
    // auto copy = ...;
    // manager.add("copy", copy);

    // will sort the arguments by size
    // `sort_size abc a 1234` -> will print `a abc 1234`
    // use std::sort with a lambda comparator to sort
    // and std::for_each with a lambda to print afterwards
    // auto sort_size = ...;
    // manager.add("sort_size", sort_size);

    // add one more command of anything you'd like

    manager.run();

    printf("number of errors: %u\ndone!\n", number_of_errors);
}