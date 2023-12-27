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
    string featherColor; // Новый атрибут для класса Bird

    Bird(const string& n, int a, int w, bool fly, const string& color)
            : Animal(n, a, w), canFly(fly), featherColor(color) {}

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
    string furColor; // Новый атрибут для класса Mammal

    Mammal(const string& n, int a, int w, bool fur, const string& color)
            : Animal(n, a, w), hasFur(fur), furColor(color) {}

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
    string scaleType; // Новый атрибут для класса Reptile

    Reptile(const string& n, int a, int w, bool coldBlooded, const string& type)
            : Animal(n, a, w), isColdBlooded(coldBlooded), scaleType(type) {}

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
    string scaleColor; // Новый атрибут для класса Fish

    Fish(const string& n, int a, int w, bool saltwater, const string& color)
            : Animal(n, a, w), livesInSaltwater(saltwater), scaleColor(color) {}

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
    string skinTexture; // Новый атрибут для класса Amphibian

    Amphibian(const string& n, int a, int w, bool jump, const string& texture)
            : Animal(n, a, w), canJump(jump), skinTexture(texture) {}


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
    int swimSpeed; // Новый атрибут для класса Dolphin

    Dolphin(const string& n, int a, int w, bool fur, bool friendly, int speed)
            : Mammal(n, a, w, fur, "SomeColor"), isFriendly(friendly), swimSpeed(speed) {}


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
    string slidePreference; // Новый атрибут для класса Penguin

    Penguin(const string& n, int a, int w, bool fly, bool cold, const string& preference)
            : Bird(n, a, w, fly, "SomeColor"), likesCold(cold), slidePreference(preference) {}

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
    int jawStrength; // Новый атрибут для класса Crocodile

    Crocodile(const string& n, int a, int w, bool coldBlooded, bool sharpTeeth, int strength)
            : Reptile(n, a, w, coldBlooded, "SomeType"), hasSharpTeeth(sharpTeeth), jawStrength(strength) {}

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
    bool hasAttribute; // Новый атрибут
    string attributeValue; // Новый атрибут

    cout << "Enter the name of the new animal: ";
    cin >> name;

    cout << "Enter the age of the new animal: ";
    cin >> age;

    cout << "Enter the weight of the new animal: ";
    cin >> weight;

    switch (type) {
        case 1: // Bird
            cout << "Can the bird fly? (1 for true, 0 for false): ";
            cin >> hasAttribute;
            cout << "what color feathers does your bird have?";
            cin >> attributeValue;
            return new Bird(name, age, weight, hasAttribute, attributeValue);

        case 2: // Mammal
            cout << "Does the mammal have fur? (1 for true, 0 for false): ";
            cin >> hasAttribute;
            if (hasAttribute) {
                cout << "Enter the fur color of the mammal: ";
                cin >> attributeValue;
            }
            return new Mammal(name, age, weight, hasAttribute, attributeValue);

        case 3: // Reptile
            cout << "Is the reptile cold-blooded? (1 for true, 0 for false): ";
            cin >> hasAttribute;
            cout << "What type is your reptile?";
            cin >> attributeValue;
            return new Reptile(name, age, weight, hasAttribute, attributeValue);

        case 4: // Fish
            cout << "Does the fish live in saltwater? (1 for true, 0 for false): ";
            cin >> hasAttribute;
            cout << "what scale does your fish have?";
            cin >> attributeValue;
            return new Fish(name, age, weight, hasAttribute, attributeValue);

        case 5: // Amphibian
            cout << "Can the amphibian jump? (1 for true, 0 for false): ";
            cin >> hasAttribute;
            cout << "what skinTexture does your reptile have?";
            cin >> attributeValue;
            return new Amphibian(name, age, weight, hasAttribute, attributeValue);

        case 6: // Dolphin
            cout << "Is the dolphin friendly? (1 for true, 0 for false): ";
            cin >> hasAttribute;
            if (hasAttribute) {
                cout << "Enter the swim speed of the dolphin: ";
                cin >> attributeValue;
            }
            return new Dolphin(name, age, weight, true, hasAttribute, stoi(attributeValue));

        case 7: // Penguin
            cout << "Does the penguin like the cold? (1 for true, 0 for false): ";
            cin >> hasAttribute;
            cout << "Does your penguin like to slide?";
            cin >> attributeValue;
            return new Penguin(name, age, weight, false, hasAttribute, attributeValue);

        case 8: // Crocodile
            cout << "Is the crocodile aggressive? (1 for true, 0 for false): ";
            cin >> hasAttribute;
            if (hasAttribute) {
                cout << "Enter the jaw strength of the crocodile: ";
                cin >> attributeValue;
            }
            return new Crocodile(name, age, weight, true, hasAttribute, stoi(attributeValue));

        default:
            return nullptr;
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    list<Animal*> animals;

    Bird parrot("Polly", 5, 1, true, "White");
    Mammal dog("Buddy", 3, 10, true, "black");
    Reptile snake("Sly", 2, 2, true, "squad Scaly");
    Fish goldfish("Goldie", 1, 0, true, "gold");
    Amphibian frog("Freddy", 2, 0, true, "slimy");

    Dolphin dolphin("Flipper", 8, 300, false, true, 76);
    Penguin penguin("Chilly", 4, 5, false, true, "yes");
    Crocodile crocodile("Snappy", 6, 200, true, true,88);

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