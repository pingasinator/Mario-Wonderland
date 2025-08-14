;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.5.1 #15267 (Linux)
;--------------------------------------------------------
	.module savefile
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _World_8
	.globl _World_7
	.globl _World_6
	.globl _World_5
	.globl _World_4
	.globl _World_3
	.globl _World_2
	.globl _World_1
	.globl _World_List
	.globl _SaveFile_1_Levels
	.globl _World_1_Points
	.globl _SaveFile_3
	.globl _SaveFile_2
	.globl _SaveFile_1
	.globl _SaveFile_1_World_8_Levels
	.globl _SaveFile_1_World_7_Levels
	.globl _SaveFile_1_World_6_Levels
	.globl _SaveFile_1_World_5_Levels
	.globl _SaveFile_1_World_4_Levels
	.globl _SaveFile_1_World_3_Levels
	.globl _SaveFile_1_World_2_Levels
	.globl _SaveFile_1_World_1_Levels
	.globl _SavedPoint
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA_1
_SavedPoint::
	.ds 1
_SaveFile_1_World_1_Levels::
	.ds 4
_SaveFile_1_World_2_Levels::
	.ds 4
_SaveFile_1_World_3_Levels::
	.ds 4
_SaveFile_1_World_4_Levels::
	.ds 4
_SaveFile_1_World_5_Levels::
	.ds 4
_SaveFile_1_World_6_Levels::
	.ds 4
_SaveFile_1_World_7_Levels::
	.ds 4
_SaveFile_1_World_8_Levels::
	.ds 4
_SaveFile_1::
	.ds 8
_SaveFile_2::
	.ds 8
_SaveFile_3::
	.ds 8
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_World_1_Points::
	.ds 70
_SaveFile_1_Levels::
	.ds 16
_World_List::
	.ds 16
_World_1::
	.ds 5
_World_2::
	.ds 5
_World_3::
	.ds 5
_World_4::
	.ds 5
_World_5::
	.ds 5
_World_6::
	.ds 5
_World_7::
	.ds 5
_World_8::
	.ds 5
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
	.dw #0x0002
	.dw #0x0005
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	; 0
	.dw #0x0004
	.dw #0x0003
	.db #0x04	; 4
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
	.db #0x06	; 6
	.dw #0x0005
	.dw #0x000e
	.db #0x03	; 3
	.db #0x00	; 0
	.db #0x05	; 5
	.dw #0x000a
	.dw #0x000e
	.db #0x01	; 1
	.db #0x03	; 3
	.db #0x00	; 0
	.dw #0x000f
	.dw #0x000e
	.db #0x04	; 4
	.db #0x00	; 0
	.db #0x00	; 0
	.dw #0x0010
	.dw #0x000d
	.db #0x05	; 5
	.db #0x04	; 4
	.db #0x00	; 0
__xinit__SaveFile_1_Levels:
	.dw _SaveFile_1_World_1_Levels
	.dw _SaveFile_1_World_2_Levels
	.dw _SaveFile_1_World_3_Levels
	.dw _SaveFile_1_World_4_Levels
	.dw _SaveFile_1_World_5_Levels
	.dw _SaveFile_1_World_6_Levels
	.dw _SaveFile_1_World_7_Levels
	.dw _SaveFile_1_World_8_Levels
__xinit__World_List:
	.dw _World_1
	.dw _World_2
	.dw _World_3
	.dw _World_4
	.dw _World_5
	.dw _World_6
	.dw _World_7
	.dw _World_8
__xinit__World_1:
	.dw _World_1_Points
	.dw #0x0001
	.db #0x0a	; 10
__xinit__World_2:
	.dw _World_1_Points
	.dw #0x0002
	.db #0x00	; 0
__xinit__World_3:
	.dw _World_1_Points
	.dw #0x0003
	.db #0x00	; 0
__xinit__World_4:
	.dw _World_1_Points
	.dw #0x0004
	.db #0x00	; 0
__xinit__World_5:
	.dw _World_1_Points
	.dw #0x0005
	.db #0x00	; 0
__xinit__World_6:
	.dw _World_1_Points
	.dw #0x0006
	.db #0x00	; 0
__xinit__World_7:
	.dw _World_1_Points
	.dw #0x0007
	.db #0x00	; 0
__xinit__World_8:
	.dw _World_1_Points
	.dw #0x0008
	.db #0x00	; 0
	.area _CABS (ABS)
