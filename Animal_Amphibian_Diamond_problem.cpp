//Multiple inheritance, Diamond problem

#include <iostream>
#include <string>

class Animal
{
    std::string name;
    int count;

public:
    static int constr_count;

    Animal()
    {
        std::cout << __func__ << std::endl;
        name = " ";
        count = 0;

        constr_count++;
    }

    Animal(std::string s, int c)
    {
        std::cout << __func__ << std::endl;
        name = s;
        count = c;

        constr_count++;
    }

    virtual ~Animal()
    {
        std::cout << __func__ << std::endl;
    }

    Animal(const Animal& ob)
    {
        std::cout << "Copy constructor " << __func__ << std::endl;

        this->name = ob.name;
        this->count = ob.count;
    }

    Animal& operator=(const Animal& ob)
    {
        std::cout << "Animal " << __func__ << std::endl;

        if (this != &ob)
        {
            this->name = ob.name;
            this->count = ob.count;
        }
        return *this;
    }

    virtual void voice() = 0;

    virtual void move() = 0;

};

int Animal::constr_count = 0;

class Land_animals : virtual public Animal {
    bool is_wild; //is wild or domestic
    bool is_mammal; //is mammal or reptile

public:
    Land_animals()
    {
        is_wild = false;
        is_mammal = false;
        std::cout << __func__ << std::endl;
    }

    Land_animals(bool w, bool m)
    {
        is_wild = w;
        is_mammal = m;
        std::cout << __func__ << std::endl;
    }

    virtual ~Land_animals()
    {
        std::cout << __func__ << std::endl;
    }

    Land_animals(const Land_animals& ob)
    {
        std::cout << "Copy constructor " << __func__ << std::endl;

        this->is_wild = ob.is_wild;
        this->is_mammal = ob.is_mammal;

    }

    Land_animals& operator=(const Land_animals& ob)
    {
        std::cout << "Land_animals " << __func__ << std::endl;

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

    void operator()()
    {
        std::cout << "Functor\n";
    }

};



class Water_animals : virtual public Animal
{
    bool is_fish; //or sea horse, octopus

public:
    Water_animals()
    {
        std::cout << __func__ << std::endl;

        is_fish = false;
    }

    Water_animals(bool f)
    {
        std::cout << __func__ << std::endl;

        is_fish = f;
    }

    virtual  ~Water_animals()
    {
        std::cout << __func__ << std::endl;
    }

    Water_animals(const Water_animals& ob)
    {
        std::cout << "Copy constructor " << __func__ << std::endl;

        this->is_fish = ob.is_fish;
    }

    Water_animals& operator=(const Water_animals& ob)
    {
        std::cout << "Water_animals " << __func__ << std::endl;

        if (this != &ob)
        {
            this->is_fish = ob.is_fish;
        }
        return *this;
    }

    void move() override
    {
        std::cout << "All water animals are swimming\n";
    }

    virtual void voice() = 0;

    int getIfIsFish()const
    {
        return is_fish;
    }

    void setIfIsFish(bool f)
    {
        if (f == false)
        {
            std::cout << "It is not a fish\n";
        }
        else
        {
            std::cout << "It is a fish\n";
        }
        is_fish = f;
    }
};


class Amphibian : virtual public Land_animals, virtual public Water_animals
{
private:
    int color;

public:
   
    Amphibian()
    {
        std::cout << __func__ << std::endl;
    }

    Amphibian(std::string name, int count, bool is_wild, bool is_mammal, bool is_fish, int c): Animal(name, count), Land_animals(is_wild, is_mammal), Water_animals(is_fish), color(c)
    {
        std::cout << __func__ << std::endl;
    }

    ~Amphibian()
    {
        std::cout << __func__ << std::endl;
    }


    Amphibian(const Amphibian& ob)
    {
        this->color = ob.color;

        std::cout << "Copy constructor " << __func__ << std::endl;
    }

    Amphibian& operator =(const Amphibian& ob)
    {
        std::cout << "Amphibian " << __func__ << std::endl;

        if (this != &ob)
        {
            this->color = ob.color;
        }
        return *this;
    }


    void voice()
    {
        std::cout << "I am amphibian\n";
    }

    void move()
    {
        std::cout << "I am swimming, jumping, climbing\n";
    }
};


int main()
{
    Animal* ptr = new Amphibian;

    ptr->voice();
    ptr->move();

    Amphibian a;
    Amphibian a_cp = a;

    a();

    std::cout << "Animal constructor was called " << Animal::constr_count << " times " << std::endl;

    delete ptr;

    return 0;
}

