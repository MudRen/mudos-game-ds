// cundaota2.c �s�D��G�h
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�s�D��G�h");
        set("long", @LONG
�o�̬O�s�D�𪺤G�h�A���¶�۶𤺦V�𳻩����C�o�̪ŪŦp
�]�A�g�Ѥ]�\���Q���u�̤l�̭ɥh�\Ū�F�C
LONG
        );
        set("exits", ([
                "eastup" : __DIR__"cundaota3",
                "eastdown" : __DIR__"cundaota1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2790);
	set("coor/y", 130);
	set("coor/z", 180);
	setup();
        replace_program(ROOM);
}