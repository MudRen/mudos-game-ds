// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�ĤG�ӵ�"NOR);
	set("long", @LONG
�o�̬O���Z�}�����ĤG�ӵ�A�o�̬O�������̼��x���a�褧�@�A�b�o
�}�}�A�@�w�|���ܦh��ì���C
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
	    "west" : __DIR__"room060",
	    "south": __DIR__"room068",
	    "north": __DIR__"room011",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}