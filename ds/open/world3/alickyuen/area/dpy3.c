#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST.FIRE�IDPY�a�U�T��"NOR);
	set("long", "�A�U�@�h�A�Ať�즳�@�j�Z�H�b�ټM�A��ӬO�@�ӳܾK�F���H�b�K�s
�x�ơA�ݰ_�Ө��H�ܥ��r�A�A�٬O�p�߬����L�L�L�V�W���K�O�A��Ӫ��G
�ӡC\n");
 set("exits",([ 
"up":__DIR__"dpy2.c",
]));
        set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/q1" : 1,
]));
set("light", 1);
	setup();
	replace_program(ROOM);
}
