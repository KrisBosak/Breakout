#include "FieldManager.h"

using namespace std;
using namespace tinyxml2;

FieldManager::FieldManager() {
}
FieldManager::~FieldManager() {}

GameSetup* gme = new GameSetup();

void FieldManager::drawBricks() {
    path = "src/xml/Level1.xml";
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

    // Load the XML file into the doc instance
    doc.LoadFile(path);
    // Get root Element
    rootElement = doc.RootElement();
    if (rootElement != NULL) {
        rowCount = rootElement->FindAttribute("RowCount")->IntValue();
        columnCount = rootElement->FindAttribute("ColumnCount")->IntValue();
        rowSpacing = rootElement->FindAttribute("RowSpacing")->IntValue();
        columnSpacing = rootElement->FindAttribute("ColumnSpacing")->IntValue();

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

        //Get the text and give me the length of that text --> strlen() and .size() gave some warnings
        brickCharArray = rootElement->LastChildElement()->GetText();
        while (brickCharArray[charSize] != '\0') {
            charSize++;
        }

        //Make an array of all real characters with brick ids
        for (int i = 0; i < charSize; i++) {
            if (brickCharArray[i] != ' ' && brickCharArray[i] != '\n') parsedCharBrickMap += brickCharArray[i];
        }

        //Make a map out of that array or ids 
        for (int row = 0; row < 3; row++) {
            for (int column = 0; column < 20; column++, counter++) {
                fieldMap[row][column] = parsedCharBrickMap[counter];
            }
        }

        char type = NULL;
        //Draw the bricks from that map - unsuccessfully (OBVIOUSLY *Snape voice*)
        for (int row = 0; row < 3; row++) {
            for (int column = 0; column < 20; column++, counter++) {
                type = fieldMap[row][column];

                SDL_Rect desti;
                desti.x = row * 32;
                desti.y = row * 32;
                
                switch (type) {
                case 'H':
                    TextureManager::DrawTexture(IMG_LoadTexture(GameSetup::renderer, "assets/Bricks/Hard.dds"), desti);
                    break;
                }
            }
        }
    }
}


void FieldManager::getGameDetails() {
    const char* path = "src/xml/Level1.xml";
    XMLDocument doc;
    GameSetup* gme = new GameSetup();
    XMLElement* rootElement = nullptr;

    doc.LoadFile(path);
    rootElement = doc.RootElement();
    if (rootElement != NULL) {
    gme->loadTextures(rootElement->FindAttribute("BackgroundTexture")->Value());
    };
}