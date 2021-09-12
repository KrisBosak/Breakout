#include "FieldManager.h"

FieldManager::FieldManager() {}
FieldManager::~FieldManager() {}

using namespace std;
using namespace tinyxml2;

void FieldManager::drawBricks() {
    // I couldn't debug why those variable definitions didnt work as expected when i had them in the header file
    int charSize = 0;
    int counter = 0;
    int rowCount = 0;
    int columnCount = 0;
    int rowSpacing = 0;
    int columnSpacing = 0;
    int hitPoints = 0;
    int breakScore = 0;
    char fieldMap[3][20] = {};
    const char* path = "src/xml/Level1.xml";
    const char* brickCharArray;
    string backgroundTexturePath;
    string id;
    string brickTexturePath;
    string hitSoundPath;
    string breakSoundPath;
    string parsedCharBrickMap;
    string parsedCharArray;

    XMLDocument doc;
    XMLElement* rootElement = nullptr;
    XMLElement* brickTypes = nullptr;
    XMLElement* brickFormat = nullptr;
    XMLText* brickFormatToText = nullptr;

    //char amountText[100];

    // Load the XML file into the doc instance
    doc.LoadFile(path);
    // Get root Element
    rootElement = doc.RootElement();
    if (rootElement != NULL) {
        rowCount = rootElement->FindAttribute("RowCount")->IntValue();
        columnCount = rootElement->FindAttribute("ColumnCount")->IntValue();
        rowSpacing = rootElement->FindAttribute("RowSpacing")->IntValue();
        columnSpacing = rootElement->FindAttribute("ColumnSpacing")->IntValue();
        backgroundTexturePath = rootElement->FindAttribute("BackgroundTexture")->Value();

        //Get 'Levels' children
        brickTypes = rootElement->FirstChildElement("BrickTypes")->FirstChildElement("BrickType");
        do {
            id = brickTypes->FindAttribute("Id")->Value();
            brickTexturePath = brickTypes->FindAttribute("Texture")->Value();
            hitPoints = brickTypes->FindAttribute("HitPoints")->IntValue();
            hitSoundPath = brickTypes->FindAttribute("HitSound")->Value();
            if (id != "I") {
                breakSoundPath = brickTypes->FindAttribute("BreakSound")->Value();
                breakScore = brickTypes->FindAttribute("BreakScore")->IntValue();
            }

            brickTypes = brickTypes->NextSiblingElement();
        } while (brickTypes != NULL);

        //Get the text and give me the length of that text -> strlen() and .size() gave some warnings.
        brickCharArray = rootElement->LastChildElement()->GetText();
        while (brickCharArray[charSize] != '\0') {
            charSize++;
        }

        //TODO: ovo bi mogo ukomponirat u ovaj gore while - kasnije to prepravi ako ce se moc
        for (int i = 0; i < charSize; i++) {
            if (brickCharArray[i] != ' ' && brickCharArray[i] != '\n') parsedCharBrickMap += brickCharArray[i];
        }

        //Make a map out of that string 
        for (int row = 0; row < 3; row++) {
            for (int column = 0; column < 20; column++, counter++) {
                fieldMap[row][column] = parsedCharBrickMap[counter];
            }
        }

        char type = NULL;
        //Draw the bricks from that map 
        for (int row = 0; row < 3; row++) {
            for (int column = 0; column < 20; column++, counter++) {
                type = fieldMap[row][column];

                SDL_Rect sous;
                SDL_Rect desti;
                sous.x = desti.x = row * 32;
                sous.y = desti.y = row * 32;


                switch (type) {
                case 'H':
                    SDL_RenderCopy(GameSetup::renderer, IMG_LoadTexture(GameSetup::renderer, "assets / Bricks / Hard.dds"), &sous, &desti);

                }
            }
        }
    }
}
