// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�ǳN���D"NOR);
	set("long", @LONG
�A���b�@�����ǳN�𮧪����D�W�C�_��O�p�����A���n���i���k
�v�u�|�A���誽���i�H��F���F�[�ǰ|�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room051",
	    "west" : __DIR__"room053",
	    "south": __DIR__"room082",
	    "north": __DIR__"room083",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/guard" : 2,
	]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}