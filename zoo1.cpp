#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal {
public:
    string name;
    int age;
    int weight;

    Animal(const string& n, int a, int w)
            : name(n), age(a), weight(w) {}

    virtual ~Animal() {}

    void eat() const {
        cout << name << " is eating.\n";
    }

    void move() const {
        cout << name << " is moving.\n";
    }

    void sleep() const {
        cout << name << " is sleeping.\n";
    }

    void pet() const {
        cout << "You are petting " << name << ".\n";
    }

    void feed() const {
        cout << "You are feeding " << name << ".\n";
    }

    virtual void makeSound() const {
        cout << "(Silent)\n";
    }

    virtual void interact() const {
        cout << name << " looks at you.\n";
    }

    virtual string getDescription() const {
        return "A generic animal";
    }
};

class Bird : public Animal {
public:
    bool canFly;

    Bird(const string& n, int a, int w, bool fly)
            : Animal(n, a, w), canFly(fly) {}

    void chirp() const {
        cout << name << " is chirping.\n";
    }

    void fly() const {
        if (canFly)
            cout << name << " is flying.\n";
        else
            cout << name << " cannot fly.\n";
    }

    void buildNest() const {
        cout << name << " is building a nest.\n";
    }

    void layEggs() const {
        cout << name << " is laying eggs.\n";
    }

    void interact() const override {
        cout << name << " sings a melody.\n";
    }

    string getDescription() const override {
        return string("A bird that ") + (canFly ? "can" : "cannot") + " fly";
    }
};

class Mammal : public Animal {
public:
    bool hasFur;

    Mammal(const string& n, int a, int w, bool fur)
            : Animal(n, a, w), hasFur(fur) {}

    void giveBirth() const {
        cout << name << " is giving birth.\n";
    }

    void nurse() const {
        cout << name << " is nursing.\n";
    }

    void play() const {
        cout << name << " is playing.\n";
    }

    void groom() const {
        cout << name << " is grooming.\n";
    }

    void interact() const override {
        cout << name << " nuzzles against you.\n";
    }

    string getDescription() const override {
        return string("A mammal with ") + (hasFur ? "fur" : "no fur");
    }
};

class Reptile : public Animal {
public:
    bool isColdBlooded;

    Reptile(const string& n, int a, int w, bool coldBlooded)
            : Animal(n, a, w), isColdBlooded(coldBlooded) {}

    void sunbathe() const {
        if (isColdBlooded)
            cout << name << " is sunbathing.\n";
        else
            cout << name << " regulates its body temperature differently.\n";
    }

    void crawl() const {
        cout << name << " is crawling.\n";
    }

    void shedSkin() const {
        cout << name << " is shedding its skin.\n";
    }

    void hunt() const {
        cout << name << " is hunting.\n";
    }

    void interact() const override {
        cout << name << " slithers around you.\n";
    }

    string getDescription() const override {
        return string("A reptile that is ") + (isColdBlooded ? "cold-blooded" : "not cold-blooded");
    }
};

class Fish : public Animal {
public:
    bool livesInSaltwater;

    Fish(const string& n, int a, int w, bool saltwater)
            : Animal(n, a, w), livesInSaltwater(saltwater) {}

    void swim() const {
        cout << name << " is swimming.\n";
    }

    void makeSound() const override {
        cout << "(Silent)\n";
    }

    void interact() const override {
        cout << name << " gracefully swims past you.\n";
    }

    string getDescription() const override {
        return string("A fish that lives in ") + (livesInSaltwater ? "saltwater" : "freshwater");
    }
};

class Amphibian : public Animal {
public:
    bool canJump;

    Amphibian(const string& n, int a, int w, bool jump)
            : Animal(n, a, w), canJump(jump) {}

    void jump() const {
        if (canJump)
            cout << name << " is jumping.\n";
        else
            cout << name << " cannot jump.\n";
    }

    void makeSound() const override {
        cout << "(Silent)\n";
    }

    void interact() const override {
        cout << name << " croaks.\n";
    }

    string getDescription() const override {
        return string("An amphibian that ") + (canJump ? "can" : "cannot") + " jump";
    }
};

class Dolphin : public Mammal {
public:
    bool isFriendly;

    Dolphin(const string& n, int a, int w, bool fur, bool friendly)
            : Mammal(n, a, w, fur), isFriendly(friendly) {}

    void swimWithHumans() const {
        if (isFriendly)
            cout << name << " is swimming playfully with humans.\n";
        else
            cout << name << " prefers to keep its distance.\n";
    }

    void performTricks() const {
        cout << name << " is performing tricks.\n";
    }

    void interact() const override {
        cout << name << " clicks and whistles, signaling to you.\n";
    }

    string getDescription() const override {
        return "A friendly dolphin";
    }
};

class Penguin : public Bird {
public:
    bool likesCold;

    Penguin(const string& n, int a, int w, bool fly, bool cold)
            : Bird(n, a, w, fly), likesCold(cold) {}

    void slideOnIce() const {
        if (likesCold)
            cout << name << " is sliding on ice.\n";
        else
            cout << name << " prefers warmer places.\n";
    }

    void catchFish() const {
        cout << name << " is catching fish.\n";
    }

    void interact() const override {
        cout << name << " waddles over to you.\n";
    }

    string getDescription() const override {
        return string("A penguin that ") + (likesCold ? "likes" : "does not like") + " the cold";
    }
};

class Crocodile : public Reptile {
public:
    bool hasSharpTeeth;

    Crocodile(const string& n, int a, int w, bool coldBlooded, bool sharpTeeth)
            : Reptile(n, a, w, coldBlooded), hasSharpTeeth(sharpTeeth) {}

    void baskOnRiverbank() const {
        cout << name << " is basking on the riverbank.\n";
    }

    void snapJaws() const {
        if (hasSharpTeeth)
            cout << name << " snaps its jaws shut.\n";
        else
            cout << name << " looks menacingly.\n";
    }

    void interact() const override {
        cout << name << " eyes you with a reptilian gaze.\n";
    }

    string getDescription() const override {
        return string("A crocodile with ") + (hasSharpTeeth ? "sharp teeth" : "no sharp teeth");
    }
};

// Функция для взаимодействия с животным
void interactWithAnimal(const Animal& animal) {
    cout << "You are interacting with " << animal.name << ". " << animal.getDescription() << "\n";
    animal.interact();
}

// Функция для кормления животного
void feedAnimal(const Animal& animal) {
    cout << "You are feeding " << animal.name << ". " << animal.getDescription() << "\n";
    animal.feed();
}

// Функция для ласкания животного
void petAnimal(const Animal& animal) {
    cout << "You are petting " << animal.name << ". " << animal.getDescription() << "\n";
    animal.pet();
}

// Функция для добавления нового животного определенного типа
Animal* addAnimalOfType(int type) {
    string name;
    int age, weight;

    cout << "Enter the name of the new animal: ";
    cin >> name;

    cout << "Enter the age of the new animal: ";
    cin >> age;

    cout << "Enter the weight of the new animal: ";
    cin >> weight;

    switch (type) {
        case 1:
            return new Bird(name, age, weight, true);
        case 2:
            return new Mammal(name, age, weight, true);
        case 3:
            return new Reptile(name, age, weight, true);
        case 4:
            return new Fish(name, age, weight, true);
        case 5:
            return new Amphibian(name, age, weight, true);
        case 6:
            return new Dolphin(name, age, weight, true, true);
        case 7:
            return new Penguin(name, age, weight, false, true);
        case 8:
            return new Crocodile(name, age, weight, true, true);
        default:
            return nullptr;
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    list<Animal*> animals;

    Bird parrot("Polly", 5, 1, true);
    Mammal dog("Buddy", 3, 10, true);
    Reptile snake("Sly", 2, 2, true);
    Fish goldfish("Goldie", 1, 0, true);
    Amphibian frog("Freddy", 2, 0, true);

    Dolphin dolphin("Flipper", 8, 300, false, true);
    Penguin penguin("Chilly", 4, 5, false, true);
    Crocodile crocodile("Snappy", 6, 200, true, true);

    animals.push_back(&parrot);
    animals.push_back(&dog);
    animals.push_back(&snake);
    animals.push_back(&goldfish);
    animals.push_back(&frog);
    animals.push_back(&dolphin);
    animals.push_back(&penguin);
    animals.push_back(&crocodile);

    cout << "Welcome to the Animal Interaction Program!\n";

    while (true) {
        cout << "\nChoose an action:\n"
             << "1. Interact with an animal\n"
             << "2. Feed an animal\n"
             << "3. Pet an animal\n"
             << "4. Add a new animal\n"
             << "5. Exit\n";

        int choice;
        cin >> choice;

        if (choice == 5) {
            break;  // Выход из программы
        }

        if (choice == 4) {
            cout << "Choose the type of animal to add:\n"
                 << "1. Bird\n"
                 << "2. Mammal\n"
                 << "3. Reptile\n"
                 << "4. Fish\n"
                 << "5. Amphibian\n"
                 << "6. Dolphin\n"
                 << "7. Penguin\n"
                 << "8. Crocodile\n";

            int animalType;
            cin >> animalType;

            Animal* newAnimal = addAnimalOfType(animalType);
            if (newAnimal != nullptr) {
                animals.push_back(newAnimal);
                cout << "New " << newAnimal->getDescription() << " added.\n";
            } else {
                cout << "Invalid animal type.\n";
            }
            continue;
        }

        cout << "Choose an animal (1-" << animals.size() << "):\n";
        int animalChoice;
        cin >> animalChoice;

        auto it = animals.begin();
        advance(it, animalChoice - 1);
        Animal* selectedAnimal = *it;

        switch (choice) {
            case 1:
                interactWithAnimal(*selectedAnimal);
                break;
            case 2:
                feedAnimal(*selectedAnimal);
                break;
            case 3:
                petAnimal(*selectedAnimal);
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }

    // Освободим память, выделенную для животных
    for (auto animal : animals) {
        delete animal;
    }

    return 0;
}