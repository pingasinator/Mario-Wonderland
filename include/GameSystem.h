#ifndef Game_System_H
#define Game_System_H

void Add_Coin(int i);
void Add_Life(int i);

int Get_GameMode(void);
void Set_GameMode(int i);

int Get_Coin_Number(void);
int Get_Life_Number(void);
int GetButtonDown(unsigned char input);
int GetButton(unsigned char input);
void Set_Time(int i);
int Get_Time(void);
#endif