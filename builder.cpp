#include <iostream>
using namespace std;

/* Product */
class Pizza
{
    string dough = ""; // тесто, корж
    string sauce = ""; // соус
    string topping = ""; // начинка

public:
    void setDough(string dough)
    {
        this->dough = dough;
    }

    void setSauce(string sauce)
    {
        this->sauce = sauce;
    }

    void setTopping(string topping)
    {
        this->topping = topping;
    }
};

/* Abstract Builder */
class PizzaBuilder abstract // абстрактный пиццеол :)
{
protected:
    Pizza* pizza;

public:
    Pizza* getPizza()
    {
        return pizza;
    }

    void createNewPizzaProduct()
    {
        pizza = new Pizza();
    }

    virtual void buildDough() = 0;

    virtual void buildSauce() = 0;

    virtual void buildTopping() = 0;
};

/* Concrete Builder #1 */
class HawaiianPizzaBuilder : public PizzaBuilder
{
public:

    HawaiianPizzaBuilder()
    {
        cout << "Hawaiian Pizza:\n";
    }

    void buildDough()
    {
        pizza->setDough("thick");
        cout << "thick dough\n";
    }

    void buildSauce()
    {
        pizza->setSauce("mild"); // не острый
        cout << "mild sause\n";
    }

    void buildTopping()
    {
        pizza->setTopping("ham + pineapple");
        cout << "ham+pineapple topping\n";
    }
};

/* Concrete Builder #2 */
class SpicyPizzaBuilder : public PizzaBuilder
{
public:

    SpicyPizzaBuilder()
    {
        cout << "Spicy Pizza:\n";
    }

    void buildDough()
    {
        pizza->setDough("thin");
        cout << "thin dough\n";
    }

    void buildSauce()
    {
        pizza->setSauce("hot"); // острый
        cout << "hot sause\n";
    }

    void buildTopping()
    {
        pizza->setTopping("pepperoni + salami");
        cout << "pepperoni+salami topping\n";
    }
};

/* Director */
class Waiter
{
    PizzaBuilder* pizzaBuilder;

public:
    void setPizzaBuilder(PizzaBuilder* pb)
    {
        pizzaBuilder = pb;
    }

    Pizza* getPizza() {
        return pizzaBuilder->getPizza();
    }

    void constructPizza()
    {
        pizzaBuilder->createNewPizzaProduct();
        pizzaBuilder->buildDough();
        pizzaBuilder->buildSauce();
        pizzaBuilder->buildTopping();
    }

    void constructPizzaWithoutSause() // для тех, кто хочет пиццу без соуса
    {
        pizzaBuilder->createNewPizzaProduct();
        pizzaBuilder->buildDough();
        pizzaBuilder->buildTopping();
    }
};

int main()
{
    Waiter waiter;
    waiter.setPizzaBuilder(new HawaiianPizzaBuilder);
    waiter.constructPizza();
    // waiter.constructPizzaWithoutSause();

    Pizza* pizza = waiter.getPizza();
}