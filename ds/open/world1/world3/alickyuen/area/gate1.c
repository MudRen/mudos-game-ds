#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST�CGate�ISouth"NOR);
	set("long", @LONG
�o�̴N�O�j����Saint���n�����A���O�H�y�K�����䤤�@�Ӧa��A�]��
�o�ӫn�����O��q���ϯáA�פ�H�ӤH���A�ҥH�H�̳����o�D�����@�ӯS
�O���٩I�ССi�t���j�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dst4.c",
"out":__DIR__"dst17.c",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard.c" : 1,
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
