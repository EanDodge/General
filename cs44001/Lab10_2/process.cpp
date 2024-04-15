// demonstrates state design pattern
// Mikhail Nesterenko
// 2/23/2014

#include <iostream>
#include <string>
#include <deque>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::deque;

class State;
// context
class Process
{
public:
    Process();
    static int processNum;
    // behaviors
    void suspend();
    void exit();
    void block();
    void unblock();
    void dispatch();
    string report();
    int getID() const { return ID; }

    // part of implementation of state pattern
    void changeState(State *state) { state_ = state; }

private:
    State *state_;
    int ID;
};

// absract state
class State
{
public:
    State(){};
    virtual void block(Process *){};
    virtual void unblock(Process *){};
    virtual void suspend(Process *){};
    virtual void exit(Process *){};
    virtual void dispatch(Process *){};
    virtual string report() = 0;
    void changeState(Process *c, State *s)
    {
        c->changeState(s);
    }
};

class Ready : public State
{
public:
    Ready(){};
    static State *instance()
    {
        static State *onlyInstance = new Ready;
        return onlyInstance;
    }

    // void block(Process*) override;
    // void unblock(Process*) override;
    // void suspend(Process*) override;
    // void exit(Process*) override;
    void dispatch(Process *) override;

    string report() override { return "Ready"; }

private:
    // here and elsewhere should be stated private constructor/assignment
    // to correctly implement singleton, skipped to simplify code
};

class Blocked : public State
{
public:
    static State *instance()
    {
        static State *onlyInstance = new Blocked;
        return onlyInstance;
    }
    Blocked(){};
    // void block(Process*) override;
    void unblock(Process *) override;
    // void suspend(Process*) override;
    // void exit(Process*) override;
    // void dispatch(Process*) override;
    string report() override { return "Blocked"; }
};

class Running : public State
{
public:
    static State *instance()
    {
        static State *onlyInstance = new Running;
        return onlyInstance;
    }
    Running(){};
    void block(Process *) override;
    // void unblock(Process*) override;
    void suspend(Process *) override;
    void exit(Process *) override;
    // void dispatch(Process*) override;
    string report() override { return "Running"; }
};

//    void suspend();
//    void exit();
//    void block();
//    void unblock();
//    void dispatch();
// state transitions member functions
// Ready
/////////////////////////////////////

void Ready::dispatch(Process *c)
{
    changeState(c, Running::instance());
}
//////////////////////////////////////
// Running
void Running::suspend(Process *c)
{
    changeState(c, Ready::instance());
}
void Running::exit(Process *c)
{
    // changeState(c, Hungry::instance());
    //delete c;
}
void Running::block(Process *c)
{
    changeState(c, Blocked::instance());
}

//////////////////////////////////////
// Blocked

void Blocked::unblock(Process *c)
{
    changeState(c, Ready::instance());
}
// Character member functions
Process::Process()
{
    state_ = Ready::instance();
    Process::processNum++;
    ID = Process::processNum;
}
int Process::processNum = 0;

// handles/behaviors
void Process::block() { state_->block(this); }
void Process::unblock() { state_->unblock(this); }
void Process::dispatch() { state_->dispatch(this); }
void Process::exit() { state_->exit(this); }
void Process::suspend() { state_->suspend(this); }
string Process::report() { return state_->report(); }

void processReport(Process zork)
{
    cout << "Process " << zork.getID() << " is " << zork.report() << endl;
}

int main()
{
    deque<Process *> myProcess;
    myProcess.push_back(new Process);
    bool flag = true;
    while (flag)
    {
        for (auto e : myProcess)
        {
            processReport(*e);
        }
        cout << "make a process? or deal with process?[m/d]";
        char decision;
        cin >> decision;
        switch (decision)
        {
        case 'm':
            myProcess.push_back(new Process);
            break;
        case 'd':
            int temp = rand() % 5 + 1;
            switch (temp)
            {
            case 1:
                myProcess[0]->block();
                break;
            case 2:
                myProcess[0]->unblock();
                break;
            case 3:
                myProcess[0]->dispatch();
                break;
            case 4:
                myProcess[0]->exit();
                if(myProcess[0]->report() == "Running")
                    myProcess.pop_front();
                if (myProcess.size() == 0)
                    flag = false;
                break;
            case 5:
                myProcess[0]->suspend();
                break;
            }
            break;
        }
    }

    //    while(zork.report() != "dead"){
    //       cout << "What would you like Zork to do? Eat or skip lunch? [e/s] ";
    //       char action; cin >> action;
    //       if(action == 'e')
    // 	   zork.dispatch();
    //       else
    // 	   zork.block();
    //       cout << "Zork is " << zork.report() << endl;
    //    }

    // demonstrates that two Characters
    // may be in two different states
    // cout << "Zork is " << zork.report() << " while "
    //<< "Grue is " << grue.report() << endl;
}
