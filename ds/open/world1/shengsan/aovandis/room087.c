// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�s��u�|"NOR);
	set("long", @LONG
�A����F�@���U�p���ж��A�o�̪��˹��Y�㺡�ءA�n�������O�o�Ӧa
�Ϫ��F��C
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room100",
	    "south": __DIR__"room012",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}