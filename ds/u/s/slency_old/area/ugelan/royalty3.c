// Room: /u/s/slency/area/ugelan/royalty.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"�y �Ӯc�j�� �z"NOR);
	set("long", @LONG
�A�Ө�F�j���e�A���L�j���o�O�`��۪��A���W��ۯS�s������, 
�ݨӴM�`�L���O�L�k�N��}�a���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"royalty2",
  "south" : __DIR__"royalty",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
