// updated 26/12
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST�CRoad�INorth"NOR);
	set("long", @LONG
�o�̤S�O�@�ӤQ�r���f�A�V�F�O�@�������橱�A�ӦV��O�@���^��
�ΡC�ӥ_���O�q���F���j�Ӫ��D���A���n�K�O�A�Ӫ������ߡC�o���񪺭�
���ܴ��q�A�S������S�O���B�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"shop1.c",
  "south" : __DIR__"dst8.c",
  "north" : __DIR__"dst10.c",
  "east" : __DIR__"shop3",
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
