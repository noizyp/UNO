#include "card.h"
#include "game_state.h"

Color Card::getColor() const{
    return color;
}
    
int Card::getNumber() const{
    return number;
}

void Card::setColor(Color c){
    color = c;
}

void Card::setNumber(int n){
    number = n;
}

NumberCard::NumberCard(Color c, int n) {
    setColor(c);
    setNumber(n);
}


string NumberCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|     " <<  number << "     |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool NumberCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        return true;
    } else {
        return false;
    }
}


ReverseCard::ReverseCard(Color c, int n) {
    setColor(c);
    setNumber(n);
}


string ReverseCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|  REVERSE  |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool ReverseCard::play(Card* discard, GameState &gameState){
    
    
    if(color == discard->getColor() || (number >= 10 && number <= 11)){
        
        
        if (gameState.turnDirection == LEFT){
            
            gameState.turnDirection = RIGHT;
            
        } else if (gameState.turnDirection == RIGHT){
            
            gameState.turnDirection = LEFT;
            
        }

        
    }
}

SkipCard::SkipCard(Color c, int n) {
    setColor(c);
    setNumber(n);
}

string SkipCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|    SKIP   |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool SkipCard::play(Card* discard, GameState &gameState) {
    
    if(color == discard->getColor() || (number >= 12 && number <= 13)){
        gameState.skipTurn = true;
    }

}

WildCard::WildCard(Color c, int n) {
    setColor(c);
    setNumber(n);
}

string WildCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|   Wild    |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool WildCard::play(Card* discard, GameState &gameState) {
    int colorNum;
    bool doneWithColors = false;
    cout << "You chose the wild card, please choose a color: 0-RED, 1-BLUE, 2-GREEN, 3-YELLOW" << endl;
    cin >> colorNum;
    while (doneWithColors != true) {
        if (colorNum == 0) {
            color = RED;
            doneWithColors = true;
        }
        else if (colorNum == 1) {
            color = BLUE;
            doneWithColors = true;
        }
        else if (colorNum == 2) {
            color = GREEN;
            doneWithColors = true;
        }
        else if (colorNum == 3) {
            color = YELLOW;
            doneWithColors = true;
        }
        else {
            cout << "Invalid entry, please try again." << endl;
            cin >> colorNum;
        }
    }
    
    return true;
}


DrawTwo::DrawTwo(Color c, int n) {
    setColor(c);
    setNumber(n);
}

string DrawTwo::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|  DrawTwo  |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}


bool DrawTwo::play(Card* discard, GameState &gameState) {
    
    if(color == discard->getColor() || (number >= 14 && number <= 15)){
        
        gameState.numCardsToDraw = 2;
        gameState.skipTurn = true;
        
    }

}
