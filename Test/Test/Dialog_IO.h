#pragma once


int ShowDialog(const char* text, const char* speaker, bool waitForChoiceMenu = false, bool showSpeaker = true);
int Choices(const char* choice1, const char* choice2, const char* choice3 = nullptr);
int CueAnimation(int actor, const char* animation, bool blockUntilCompleted=false);