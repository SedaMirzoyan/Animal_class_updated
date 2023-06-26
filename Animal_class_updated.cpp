
#include <iostream>
#include <string>

class Animal
{
    std::string name;
    int count;
    int* count_arr;

public:
    Animal()
    {
        std::cout << "Animal Default constructor\n";
        name = " ";
        count = 0;

        count_arr = new int[count];
    }

    Animal(std::string s, int c)
    {
        std::cout << "Animal Parameterized constructor\n";
        name = s;
        count = c;

        count_arr = new int[count];
    }

    virtual ~Animal()
    {
        std::cout << "Animal Destructor\n";

        delete[]count_arr;
    }

    Animal(const Animal& ob)
    {
        std::cout << "Copy Constructor\n";
        this->name = ob.name;
        this->count = ob.count;

        this->count_arr = ob.count_arr;
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

    virtual void voice()
    {
        std::cout << "I am an Animal\n";
    }

    virtual void move() 
    {
        std::cout << "Move function in base class\n";
    }
};

class Land_animals : public Animal {
    bool is_wild; //is wild or domestic
    bool is_mammal; //is mammal or reptile

public:
    Land_animals()
    {
        is_wild = false;
        is_mammal = false;
        std::cout << "Land animal Default constructor\n";
    }

    Land_animals(bool w, bool m)
    {
        is_wild = w;
        is_mammal = m;
        std::cout << "Land animal Parametrized constructor\n";
    }

    virtual ~Land_animals()
    {
        std::cout << "Land animal Destructor\n";
    }

    Land_animals(const Land_animals& ob)
    {
        std::cout << "Land animal copy constructor\n";
        this->is_wild = ob.is_wild;
        this->is_mammal = ob.is_mammal;

    }

    Land_animals& operator=(const Land_animals& ob)
    {
        std::cout << "Land animal operator =\n";
        if (this != &ob)
        {
            this->is_wild = ob.is_wild;
            this->is_mammal = ob.is_mammal;
        }
        return *this;
    }

    virtual void voice()
    {
        std::cout << "I am a land animal\n";
    }

    void move() override
    {
        if (is_mammal == true)
        {
            std::cout << "Mammals are running\n";
        }
        else
        {
            std::cout << "Reptils are crawling\n";
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

class Birds : public Animal {
    bool is_wild; //is wild or domestic
    bool if_can_fly; //for example penguins vs eagle

public:
    Birds()
    {
        std::cout << "Birds Default constructor\n";
        is_wild = false;
        if_can_fly = false;
    }

    Birds(bool w, bool f)
    {
        std::cout << "Birds Parametrized constructor\n";
        is_wild = w;
        if_can_fly = f;
    }

    virtual ~Birds()
    {
        std::cout << "Birds Destructor\n";
    }

    Birds(const Birds& ob)
    {
        std::cout << "Birds copy constructor\n";
        this->is_wild = ob.is_wild;
        this->if_can_fly = ob.if_can_fly;
    }

    Birds& operator=(const Birds& ob)
    {
        std::cout << "Birds operator =\n";
        if (this != &ob)
        {
            this->is_wild = ob.is_wild;
            this->if_can_fly = ob.if_can_fly;
        }
        return *this;
    }

    virtual void voice()
    {
        std::cout << "I am a bird\n";
    }


    void move() override
    {
        std::cout << "Move function in Birds class\n";
    }

    int getIsWild()const
    {
        return is_wild;
    }

    void setIsWild(bool w)
    {
        if (w == false)
        {
            std::cout << "Bird is domestic\n";
        }
        else
        {
            std::cout << "Bird is wild\n";
        }
        is_wild = w;
    }


    int getIfCanFly()const
    {
        return if_can_fly;
    }

    void setIfCanFly(bool f)
    {
        if (f == false)
        {
            std::cout << "Bird can't fly\n";
        }
        else
        {
            std::cout << "Bird can fly\n";
        }
        if_can_fly = f;
    }
};

class Sea_animals : public Animal
{
    bool is_fish; //or sea horse, octopus

public:
    Sea_animals()
    {
        std::cout << "Sea animals Default constructor\n";

        is_fish = false;
    }

    Sea_animals(bool f)
    {
        std::cout << "Sea animals Default constructor\n";

        is_fish = f;
    }

    virtual ~Sea_animals()
    {
        std::cout << "Sea animals Destructor\n";

    }

    Sea_animals(const Sea_animals& ob)
    {
        std::cout << "Sea_animals copy constructor\n";
        this->is_fish = ob.is_fish;
    }

    Sea_animals& operator=(const Sea_animals& ob)
    {
        std::cout << "Sea_animals operator =\n";
        if (this != &ob)
        {
            this->is_fish = ob.is_fish;
        }
        return *this;
    }

    void move() final
    {
        std::cout << "All sea animals are swimming\n";
    }

    virtual void voice()
    {
        std::cout << "I am a Sea animal\n";
    }

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

//Land animals
class Lion : public Land_animals {
    bool if_has_pride;

public:
    Lion()
    {
        std::cout << "Lion Default constructor\n";
        setIsMammal(true);
        setIsWild(true);
        if_has_pride = false;
    }

    Lion(bool f)
    {
        std::cout << "Lion Parametrized constructor\n";
        setIsMammal(true);
        setIsWild(true);
        if_has_pride = f;
    }

    ~Lion()
    {
        std::cout << "Lion Destructor\n";
    }

    Lion(const Lion& ob)
    {
        std::cout << "Lion copy constructor\n";
        this->if_has_pride = ob.if_has_pride;
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

class Snake : public Land_animals {
private:
    bool is_poisonous;
public:
    Snake()
    {
        std::cout << "Snake Default constructor\n";
        is_poisonous = false;
        setIsMammal(false);
        setIsWild(true);
    }

    Snake(bool p)
    {
        std::cout << "Snake Parametrized constructor\n";
        is_poisonous = p;
        setIsMammal(false);
        setIsWild(true);
    }

    ~Snake()
    {
        std::cout << "Snake Destructor\n";
    }

    Snake(const Snake& ob)
    {
        std::cout << "Snake copy constructor\n";
        this->is_poisonous = ob.is_poisonous;
    }

    Snake& operator=(const Snake& ob)
    {
        std::cout << "Snake operator =\n";
        if (this != &ob)
        {
            this->is_poisonous = ob.is_poisonous;
        }
        return *this;
    }

    virtual void voice()
    {
        std::cout << "I am a snake\n";
    }

    virtual void move()
    {
        std::cout << "I am crawling\n";
    }
};

class Cow : public Land_animals {
    int color;
public:
    Cow()
    {
        std::cout << "Cow Default constructor\n";
        color = 0;
        setIsMammal(true);
        setIsWild(false);
    }

    Cow(int c)
    {
        std::cout << "Cow Parametrized constructor\n";
        color = c;
        setIsMammal(true);
        setIsWild(false);
    }

    ~Cow()
    {
        std::cout << "Cow Destructor\n";
    }

    Cow(const Cow& ob)
    {
        std::cout << "Cow copy constructor\n";
        this->color = ob.color;
    }

    Cow& operator=(const Cow& ob)
    {
        std::cout << "Cow operator =\n";
        if (this != &ob)
        {
            this->color = ob.color;
        }
        return *this;
    }

    virtual void voice()
    {
        std::cout << "I am a cow\n";
    }

    virtual void move()
    {
        std::cout << "I am walking\n";
    }
};


//Birds
class Eagle : public Birds {
    int color;
public:
    Eagle()
    {
        std::cout << "Eagle Default constructor\n";
        color = 0;
        setIfCanFly(true);
        setIsWild(true);
    }

    Eagle(int c)
    {
        std::cout << "Eagle Parametrized constructor\n";
        color = c;
        setIfCanFly(true);
        setIsWild(true);
    }

    ~Eagle()
    {
        std::cout << "Eagle Destructor\n";
    }

    Eagle(const Eagle& ob)
    {
        std::cout << "Eagle copy constructor\n";
        this->color = ob.color;
    }

    Eagle& operator=(const Eagle& ob)
    {
        std::cout << "Eagle operator =\n";
        if (this != &ob)
        {
            this->color = ob.color;
        }
        return *this;
    }

    virtual void voice()
    {
        std::cout << "I am an eagle\n";
    }

    virtual void move()
    {
        std::cout << "I am flying\n";
    }
};

class Penguin : public Birds {
    int num;

public:
    Penguin()
    {
        std::cout << "Penguin Default constructor\n";
        num = 0;
        setIfCanFly(false);
        setIsWild(true);
    }

    Penguin(int n)
    {
        std::cout << "Penguin Parametrized constructor\n";
        num = n;
        setIfCanFly(false);
        setIsWild(true);
    }

    ~Penguin()
    {
        std::cout << "Penguin Destructor\n";
    }

    Penguin(const Penguin& ob)
    {
        std::cout << "Penguin copy constructor\n";
        this->num = ob.num;
    }

    Penguin& operator=(const Penguin& ob)
    {
        std::cout << "Penguin operator =\n";
        if (this != &ob)
        {
            this->num = ob.num;
        }
        return *this;
    }

    virtual void voice()
    {
        std::cout << "I am a penguin\n";
    }

    virtual void move()
    {
        std::cout << "I can't fly, I am walking\n";
    }
};

class Parrot : public Birds {
    int color;
public:
    Parrot()
    {
        std::cout << "Parrot Default constructor\n";
        color = 0;
        setIfCanFly(true);
        setIsWild(false);
    }

    Parrot(int c)
    {
        std::cout << "Parrot Parametrized constructor\n";
        color = c;
        setIfCanFly(true);
        setIsWild(false);
    }

    ~Parrot()
    {
        std::cout << "Parrot Destructor\n";
    }

    Parrot(const Parrot& ob)
    {
        std::cout << "Parrot copy constructor\n";
        this->color = ob.color;
    }

    Parrot& operator=(const Parrot& ob)
    {
        std::cout << "Parrot operator =\n";
        if (this != &ob)
        {
            this->color = ob.color;
        }
        return *this;
    }

    virtual void voice()
    {
        std::cout << "I am a parrot\n";
    }

    virtual void move()
    {
        std::cout << "I can fly\n";
    }

};

//Sea animals

class Fish : public Sea_animals {
    int color;
public:
    Fish()
    {
        std::cout << "Fish Default constructor\n";
        color = 0;
        setIfIsFish(true);
    }

    Fish(int c)
    {
        std::cout << "Fish Parametrized constructor\n";
        color = c;
        setIfIsFish(true);
    }

    ~Fish()
    {
        std::cout << "Fish Destructor\n";
    }

    Fish(const Fish& ob)
    {
        std::cout << "Fish copy constructor\n";
        this->color = ob.color;
    }

    Fish& operator=(const Fish& ob)
    {
        std::cout << "Fish operator =\n";
        if (this != &ob)
        {
            this->color = ob.color;
        }
        return *this;
    }

    virtual void voice()
    {
        std::cout << "I am a fish\n";
    }
};

class Seahorse : public  Sea_animals {
    int color;
public:
    Seahorse()
    {
        std::cout << "Seahorse Default constructor\n";
        color = 0;
        setIfIsFish(false);
    }

    Seahorse(int c)
    {
        std::cout << "Seahorse Parametrized constructor\n";
        color = c;
        setIfIsFish(false);
    }

    ~Seahorse()
    {
        std::cout << "Seahorse Destructor\n";
    }

    Seahorse(const Seahorse& ob)
    {
        std::cout << "Seahorse copy constructor\n";
        this->color = ob.color;
    }

    Seahorse& operator=(const Seahorse& ob)
    {
        std::cout << "Seahorse operator =\n";
        if (this != &ob)
        {
            this->color = ob.color;
        }
        return *this;
    }

    virtual void voice()
    {
        std::cout << "I am a seahorse\n";
    }
};

class Octopus : public Sea_animals {
    int color;
public:
    Octopus()
    {
        std::cout << "Octopus Default constructor\n";
        color = 0;
        setIfIsFish(false);
    }

    Octopus(int c)
    {
        std::cout << "Octopus Parametrized constructor\n";
        color = c;
        setIfIsFish(false);
    }

    ~Octopus()
    {
        std::cout << "Octopus Destructor\n";
    }

    Octopus(const Octopus& ob)
    {
        std::cout << "Octopus copy constructor\n";
        this->color = ob.color;
    }

    Octopus& operator=(const Octopus& ob)
    {
        std::cout << "Octopus operator =\n";
        if (this != &ob)
        {
            this->color = ob.color;
        }
        return *this;
    }

    virtual void voice()
    {
        std::cout << "I am an octopus\n";
    }
};


int main()
{
    Animal* ptr = new Snake;
    ptr->voice();
    std::cout << std::endl;

    Animal* ptr1 = new Eagle;
    ptr1->voice();
    std::cout << std::endl;

    Lion lion;
    lion.move();

    Lion lion_cp = lion;

    std::cout << std::endl;
    Octopus octopus;
    octopus.move();

    std::cout << std::endl;
    Animal* ptr2 = new Penguin;
    ptr2->move();

    delete ptr;
    delete ptr1;
    delete ptr2;

    return 0;
}

