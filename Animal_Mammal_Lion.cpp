
#include <iostream>
#include <string>

class Animal
{
    std::string name;
    int count;
    int* count_arr;

public:
    Animal():name(" "), count(0)
    {
        std::cout << "Animal Default constructor\n";
        count_arr = new int[count];
    }

    Animal(std::string s, int c):name(s), count(c)
    {
        std::cout << "Animal Parameterized constructor\n";
        count_arr = new int[count];
    }

    virtual ~Animal()
    {
        std::cout << "Animal Destructor\n";
        delete[]count_arr;
    }

    Animal(const Animal& ob): name(ob.name), count(ob.count), count_arr(ob.count_arr)
    {
        std::cout << "Copy Constructor\n";
    }

    Animal& operator=(const Animal& ob)
    {
        std::cout << "Animal Opeartor assignment\n";
        if (this != &ob)
        {
            this->name = ob.name;
            this->count = ob.count;

            this->count_arr = ob.count_arr;
        }
        return *this;
    }

    virtual void voice() = 0;

    virtual void move() = 0;

};

class Mammal : public Animal {
    bool is_wild; //is wild or domestic
    bool is_mammal; //is mammal or reptile

public:
    Mammal():is_wild(false), is_mammal(false)
    {
        std::cout << "Mammal Default constructor\n";
    }

    Mammal(bool w, bool m): is_wild(w), is_mammal(m)
    {
        std::cout << "Mammal Parametrized constructor\n";
    }

    virtual ~Mammal()
    {
        std::cout << "Mammal Destructor\n";
    }

    Mammal(const Mammal& ob) : is_wild(ob.is_wild), is_mammal(ob.is_mammal)
    {
        std::cout << "Mammal copy constructor\n";
    }

    Mammal& operator=(const Mammal& ob)
    {
        std::cout << "Mammal operator =\n";
        if (this != &ob)
        {
            this->is_wild = ob.is_wild;
            this->is_mammal = ob.is_mammal;
        }
        return *this;
    }

    virtual void voice() = 0;


    void move() override
    {
        if (is_mammal == true)
        {
            std::cout << "Mammals are running\n";
        }
        else
        {
            std::cout << "Reptiles are crawling\n";
        }
    }


    int getIsWild()const
    {
        return is_wild;
    }

    void setIsWild(bool w)
    {
        if (w == false)
        {
            std::cout << "Animal is domestic\n";
        }
        else
        {
            std::cout << "Animal is wild\n";
        }
        is_wild = w;
    }

    int getIsMammal()const
    {
        return is_mammal;
    }

    void setIsMammal(bool m)
    {
        if (m == false)
        {
            std::cout << "Animal is a reptile\n";
        }
        else
        {
            std::cout << "Animal is a mammal\n";
        }
        is_mammal = m;
    }

};


class Lion : public Mammal {
    bool if_has_pride;

public:
    Lion():if_has_pride(false)
    {
        std::cout << "Lion Default constructor\n";
        setIsMammal(true);
        setIsWild(true);
    }

    Lion(bool f): if_has_pride(f)
    {
        std::cout << "Lion Parametrized constructor\n";
        setIsMammal(true);
        setIsWild(true);
    }

    ~Lion()
    {
        std::cout << "Lion Destructor\n";
    }

    Lion(const Lion& ob) : if_has_pride(ob.if_has_pride)
    {
        std::cout << "Lion copy constructor\n";
    }

    Lion& operator=(const Lion& ob)
    {
        std::cout << "Lion operator =\n";
        if (this != &ob)
        {
            this->if_has_pride = ob.if_has_pride;
        }
        return *this;
    }

    virtual void voice()
    {
        std::cout << "I am a lion\n";
    }
    virtual void move()
    {
        std::cout << "I am running\n";
    }

};



int main()
{
    Animal* ptr = new Lion;
    ptr->voice();
    ptr->move();
    std::cout << std::endl;

    Lion lion;
    Lion lion_cp = lion;

    Lion lion1 = lion;

    return 0;
}

