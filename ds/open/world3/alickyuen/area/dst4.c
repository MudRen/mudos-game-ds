#include <ansi.h>
//update 26/12
inherit ROOM;
void create()
{
	set("short", HIC"ST�CRoad�ISouth"NOR);
	set("long", @LONG
�ѩ�n���N�O�����A�ҥH�o�̲פ�D�`�h�H�A��O���}Saint���D�n�q
�D�C�ӥ_���N�i�H�i�J�c�ت�Saint City Centre�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"gate1.c",
  "north" : __DIR__"dst1.c",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
