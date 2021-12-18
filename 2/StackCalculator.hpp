//
// Created by gav on 08/10/2021.
//

#ifndef CPP_LABS_STACKCALCULATOR_H
#define CPP_LABS_STACKCALCULATOR_H

#include <stack>
#include <vector>
#include <map>

#include "lib/SafeInt/SafeInt.hpp"

#include "Commands.h"
#include "CommandFactory.h"

using std::stack;
using std::string;
using std::vector;
using std::map;

class StackCalculator {
    stack<SafeInt<int64_t>> _stack;
    map<string, SafeInt<int64_t>> m;
public:
    void exec(Command* cmd) {
        cmd->exec(_stack, m);
    }

    void parse_stream(std::istream &in){
        CommandFactory factory;

        while (!in.eof()){
            string line;
            getline(in, line);
//            cout << "cmd line: " << line << endl;
            stringstream ls(line);
            Command *shit = factory.parseCmd(ls);
            if (shit != nullptr)
                this->exec(shit);
        }
    }

    map<string, SafeInt<int64_t>> getM() { return m; }
};

#endif //CPP_LABS_STACKCALCULATOR_H