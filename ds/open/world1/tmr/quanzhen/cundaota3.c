// cundaota3.c �s�D��T�h
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�s�D��T�h");
        set("long", @LONG
�o�̬O�s�D�𪺤T�h�A���¶�۶𤺦V�𳻩����C�o�̪ŪŦp
�]�A�g�Ѥ]�\���Q���u�̤l�̭ɥh�\Ū�F�C
LONG
        );
        set("exits", ([
                "westup" : __DIR__"cundaota4",
                "westdown" : __DIR__"cundaota2",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2780);
	set("coor/y", 130);
	set("coor/z", 190);
	setup();
        replace_program(ROOM);
}