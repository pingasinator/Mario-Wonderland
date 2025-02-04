#ifndef Game_System_H
#define Game_System_H

int Get_GameMode(void);
void Set_GameMode(int i);

void Input_Update(void);

int GetButtonDown(unsigned char input);
int GetButton(unsigned char input);

#endif