// File: /d/down_cave/down_maze5.c
// Updated by tmr (Mon Aug 18 02:29:45 2003)

inherit ROOM;

void create()
{
	  set("short", "�Ŭ}��");
	  set("long", @LONG
�A���b�@�ӪŪŦp�]���}�ޤ��A�|�P�º������A�ݪ����O�ܲM���C
LONG
	  );
	  set("exits", ([ /* 4 element(s) */
	"south" : __DIR__"down_maze6",
	"east" : __DIR__"down_maze1",
	"west" : __DIR__"down_maze4",
	"north" : __DIR__"down_maze2",
]));

	setup();
	  replace_program(ROOM);
}
