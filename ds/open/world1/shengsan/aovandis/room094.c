// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"����"NOR);
	set("long", @LONG
�A�Ө�@�������~���Фl���Y�A�a���\�������M���Ǫ�����ۡA�i
���o�a���D�H�O�h�򪺲Ӥ�.
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room082",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}