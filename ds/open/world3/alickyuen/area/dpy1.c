#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST.FIRE�IDPY"NOR);
	set("long", @LONG
�o�̴N�O�~���H��������I--DPY�F�C�b�o�̧A�i�H�ɱ��g�w�F�A�]�i
�H�b�o�̵��Ѩ�ܦh�B�͡C���ݨ�o���f�����C�D�`���R�A�N���D�i�H�n
�n���@�ߤF�C
LONG
	);
 set("exits",([ 
"out":__DIR__"dst1.c",
"down":__DIR__"dpy2.c",
]));
        set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/bar" : 1,
]));
	set("light", 1);
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
