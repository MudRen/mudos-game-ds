// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�}���j�D"NOR);
	set("long", @LONG
�A�b���Z�}�����}���j�D�W�A�o���j�D�O��󫰸̪��F�b��A���F��
���N�O�F�����F�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room013",
	    "west" : __DIR__"room011",
	    "south": __DIR__"room078",
	    "north": __DIR__"room087",
            ]));

	set("light", 1);

	setup();
	replace_program(ROOM);
}