#pragma once


int LoadSaveData();
int WriteSaveData();

// Save data
class Save {
public:
    char playerName[16]{};
    bool gender; // false = male, true = female
    int hair; // id
    int hairColor; // id
    int skinColor; //0-4
    int eye; // id
    int eyeColor;

    // Offsets relative to computer time
    int t_yearOffset;
    int t_dayOffset;
    int t_hourOffset;
    int t_minuteOffset;

    int inventory[16]{}; // itemid of each
    int bells_Wallet; 
    int bells_inBank;
    int savedBeforeQuit = false;

    // Progression
    int house_Stage;
    int house_Stage_moneyPaid; // how much money paid towards current loan
    int nookShop_Stage; // 0-9
    int nookShop_Stage_MoneyPaid; // how much money this player has spent at the nookshop during its current phase

    // Physical layout of house
    
    // Physical town layout

};