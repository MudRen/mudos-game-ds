// File: /d/down_cave/down_maze4.c
// Updated by tmr (Mon Aug 18 02:28:55 2003)

inherit ROOM;

void create()
{
	  set("short", "�Ŭ}��");
	  set("long", @LONG
�A���b�@�ӪŪŦp�]���}�ޤ��A�|�P�º������A�ݪ����O�ܲM���C
LONG
	  );
	  set("exits", ([ /* 2 element(s) */
	"south" : __DIR__"down_maze1",
	"east" : __DIR__"down_maze5",
]));

	setup();
	  replace_program(ROOM);
}
