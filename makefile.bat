lcc -Wf-ba0 -c -o .\LevelStorage\LevelStorage.o .\LevelStorage\LevelStorage.c
lcc -Wf-ba1 -c -o .\SaveFile\SaveFile.o .\SaveFile\savefile.c
lcc -Wm-yo32 -Wm-ya4 -Wm-yt0x1B  -o MarioWonderLand.gb .\SaveFile\SaveFile.o .\LevelStorage\LevelStorage.o *.c .\Sprites\*.c .\Worldmaps\*.c .\Sprites\Levels\*.c .\Components\*.c .\Levels\*.c .\Animations\*.c .\Animations\Mario\*.c .\TilePalettes\*.c
Pause