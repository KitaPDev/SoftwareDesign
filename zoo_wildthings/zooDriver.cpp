/*
 * Authors:
 *   Kita Pairojtanachai
 *   Roger Smith Rivas Guevara
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

#include "kangarooplains.h"
#include "lemurcage.h"
#include "serpentlair.h"
#include "tigerhill.h"
#include "time.h"
#include "wolfden.h"

KangarooPlains* KangarooPlains::instance = 0;
LemurCage* LemurCage::instance = 0;
SerpentLair* SerpentLair::instance = 0;
TigerHill* TigerHill::instance = 0;
WolfDen* WolfDen::instance = 0;

int main(int argc, char* argv[]) {
    srand(time(NULL));

    std::vector<std::string> vNames = {
        "Amber",
        "Arthur",
        "Arya",
        "Atticus",
        "Aurora",
        "Ava",
        "Baby Girl",
        "Barney",
        "Basil",
        "Benji",
        "Billy",
        "Biscuit",
        "Blaze",
        "Blu",
        "Bobby",
        "Boomer",
        "Bootsie",
        "Boris",
        "Bowie",
        "Bubbles",
        "Bug",
        "Bunny",
        "Buttercup",
        "Butters",
        "Calvin",
        "Casey",
        "Cash",
        "Cassie",
        "Chance",
        "Charlie",
        "Chase",
        "Chewy",
        "Chip",
        "Cinnamon",
        "Clover",
        "Cocoa",
        "Cody",
        "Cuddles",
        "Cupcake",
        "Dash",
        "Diamond",
        "Diego",
        "Diesel",
        "Dixie",
        "Domino",
        "Dora",
        "Duchess",
        "Duke",
        "Echo",
        "Eddie",
        "Elvis",
        "Ember",
        "Emily",
        "Emmy",
        "Ernie",
        "Evie",
        "Finnegan",
        "Freddie",
        "Gary",
        "Georgie",
        "Ghost",
        "Guy",
        "Hank",
        "Harvey",
        "Hobbes",
        "Hope",
        "Indy",
        "Isabella",
        "Jerry",
        "Juno",
        "Kali",
        "Karma",
        "Kat",
        "Kevin",
        "Kit",
        "Kiwi",
        "Kona",
        "Lady",
        "Larry",
        "Lilo",
        "Link",
        "Linus",
        "Logan",
        "Lucifer",
        "Luna",
        "Mabel",
        "Mac",
        "Macy",
        "Maddie",
        "Magic",
        "Maui",
        "Maverick",
        "Maxwell",
        "Mikey",
        "Mila",
        "Miles",
        "Misha",
        "Mo",
        "Moe",
        "Mojo",
        "Monster",
        "Monty",
        "Moo",
        "Moon",
        "Mowgli",
        "Munchkin",
        "Nacho",
        "Neko",
        "Nemo",
        "Niko",
        "Nina",
        "Noah",
        "Noodle",
        "Norman",
        "Nyx",
        "Odin",
        "Oliver",
        "Opie",
        "Orion",
        "Panda",
        "Panther",
        "Parker",
        "Pebbles",
        "Pete",
        "Phoenix",
        "Pip",
        "Pippin",
        "Poe",
        "Polly",
        "Quinn",
        "Remi",
        "Remy",
        "Rex",
        "Ringo",
        "Ripley",
        "Rocket",
        "Rory",
        "Roscoe",
        "Rose",
        "Roxie",
        "Rudy",
        "Rufus",
        "Sabrina",
        "Sammie",
        "Sampson",
        "Sandy",
        "Sheba",
        "Shelby",
        "Sheldon",
        "Skittles",
        "Sky",
        "Sonny",
        "Sox",
        "Spencer",
        "Spike",
        "Stanley",
        "Stitch",
        "Suki",
        "Sully",
        "Sunshine",
        "Sweet Pea",
        "Sweetie",
        "Tabby",
        "Tabitha",
        "Thunder",
        "Tilly",
        "Tink",
        "Tinkerbell",
        "Tiny",
        "Tony",
        "Toothless",
        "Trouble",
        "Vader",
        "Waffles",
        "Walter",
        "Whiskey",
        "Willie",
        "Wilson",
        "Xena",
        "Yoshi",
        "Yuki",
        "Zeke"};
    std::vector<std::string> usedNames;

    std::vector<std::shared_ptr<Animal>> vKangaroo;
    std::vector<std::shared_ptr<Animal>> vLemur;
    std::vector<std::shared_ptr<Animal>> vSerpent;
    std::vector<std::shared_ptr<Animal>> vTiger;
    std::vector<std::shared_ptr<Animal>> vWolf;

    KangarooPlains* kangarooPlains = kangarooPlains->getInstance();
    LemurCage* lemurCage = lemurCage->getInstance();
    SerpentLair* serpentLair = serpentLair->getInstance();
    TigerHill* tigerHill = tigerHill->getInstance();
    WolfDen* wolfDen = wolfDen->getInstance();

    while (!std::cin.eof()) {
        std::string line;
        std::getline(std::cin, line);

        if (std::cin.fail()) break;
        if (line.length() == 0) continue;

        char species[10];
        int count;

        sscanf(line.c_str(), "%s %d\n", species, &count);

        for (int i = 0; i < count; i++) {
            std::string name = vNames[rand() % (vNames.size() - 1)];
            while (std::find(usedNames.begin(), usedNames.end(), name) != usedNames.end()) {
                name = vNames[rand() % (vNames.size() - 1)];
            }
            usedNames.push_back(name);

            std::shared_ptr<Animal> a;
            if (strcmp(species, "kangaroo") == 0) {
                if (vKangaroo.size() > 0) {
                    a = vKangaroo[0]->clone();
                } else {
                    a = kangarooPlains->create();
                }

                a->setName(name);
                vKangaroo.push_back(std::move(a));

            } else if (strcmp(species, "lemur") == 0) {
                if (vLemur.size() > 0) {
                    a = vLemur[0]->clone();
                } else {
                    a = lemurCage->create();
                }

                a->setName(name);
                vLemur.push_back(std::move(a));

            } else if (strcmp(species, "serpent") == 0) {
                std::shared_ptr<Serpent> s;

                if (vSerpent.size() > 0) {
                    a = vSerpent[0]->clone();
                } else {
                    a = std::make_shared<Serpent>();
                }

                a->setName(name);
                vSerpent.push_back(std::move(a));

            } else if (strcmp(species, "tiger") == 0) {
                if (vTiger.size() > 0) {
                    a = vTiger[0]->clone();
                } else {
                    a = tigerHill->create();
                }

                a->setName(name);
                vTiger.push_back(std::move(a));

            } else if (strcmp(species, "wolf") == 0) {
                if (vWolf.size() > 0) {
                    a = vWolf[0]->clone();
                } else {
                    a = wolfDen->create();
                }

                a->setName(name);
                vWolf.push_back(std::move(a));

            } else {
                std::cout << "Error: animal " << species << " not in zoo." << std::endl;
            }
        }
    }

    int numAnimals = vKangaroo.size() + vLemur.size() + vTiger.size() + vSerpent.size() + vWolf.size();

    std::cout << "Zoo \"WildThings\" is home to the following animals:" << std::endl
              << "--------------------" << std::endl
              << "There are a total of " << numAnimals << " animals in the Zoo." << std::endl
              << "There are " << vTiger.size() << " tigers, "
              << vWolf.size() << " wolves, "
              << vKangaroo.size() << " kangaroos, "
              << vLemur.size() << " lemurs and "
              << vSerpent.size() << " serpents." << std::endl;

    for (int i = 0; i < (int)vTiger.size(); i++) {
        std::cout << vTiger[i]->introduce();
    }

    for (int i = 0; i < (int)vWolf.size(); i++) {
        std::cout << vWolf[i]->introduce();
    }

    for (int i = 0; i < (int)vKangaroo.size(); i++) {
        std::cout << vKangaroo[i]->introduce();
    }

    for (int i = 0; i < (int)vLemur.size(); i++) {
        std::cout << vLemur[i]->introduce();
    }

    for (int i = 0; i < (int)vSerpent.size(); i++) {
        std::cout << vSerpent[i]->introduce();
    }
}