// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�ǳN���D"NOR);
	set("long", @LONG
�A���b�@�����ǳN�𮧪����D�W�C���W���A�i�H��F���F�[�ǰ|���J
�f�C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room053",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}