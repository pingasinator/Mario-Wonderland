;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.3.2 #14228 (MINGW64)
;--------------------------------------------------------
	.module savefile
	.optsdcc -msm83
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _saveFile_1_World_4
	.globl _saveFile_1_World_3
	.globl _saveFile_1_World_2
	.globl _saveFile_1_World_1
	.globl _SaveFile_1
	.globl _LastPoint
	.globl _World_1_Points
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA_1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_World_1_Points::
	.ds 49
_LastPoint::
	.ds 1
_SaveFile_1::
	.ds 2
_saveFile_1_World_1::
	.ds 4
_saveFile_1_World_2::
	.ds 4
_saveFile_1_World_3::
	.ds 4
_saveFile_1_World_4::
	.ds 4
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
	.area _CODE
	.area _INITIALIZER
__xinit__World_1_Points:
	.dw #0x0001
	.dw #0x0005
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.dw #0x0007
	.dw #0x0003
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x00	; 0
	.dw #0x000c
	.dw #0x0003
	.db #0x01	; 1
	.db #0x02	; 2
	.db #0x00	; 0
	.dw #0x0011
	.dw #0x0003
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x00	; 0
	.dw #0x0005
	.dw #0x000e
	.db #0x02	; 2
	.db #0x00	; 0
	.db #0x00	; 0
	.dw #0x000a
	.dw #0x000e
	.db #0x01	; 1
	.db #0x03	; 3
	.db #0x00	; 0
	.dw #0x0010
	.dw #0x000d
	.db #0x01	; 1
	.db #0x04	; 4
	.db #0x00	; 0
__xinit__LastPoint:
	.db #0x00	; 0
__xinit__SaveFile_1:
	.dw _saveFile_1_World_1
__xinit__saveFile_1_World_1:
	.dw _World_1_Points
	.dw _World_1_Tilemap
__xinit__saveFile_1_World_2:
	.dw _World_1_Points
	.dw _World_1_Tilemap
__xinit__saveFile_1_World_3:
	.dw _World_1_Points
	.dw _World_1_Tilemap
__xinit__saveFile_1_World_4:
	.dw _World_1_Points
	.dw _World_1_Tilemap
	.area _CABS (ABS)
