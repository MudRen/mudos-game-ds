// File: /d/down_cave/down_maze2.c
// Updated by tmr (Mon Aug 18 02:28:39 2003)

inherit ROOM;

void create()
{
	  set("short", "�Ŭ}��");
	  set("long", @LONG
�A���b�@�ӪŪŦp�]���}�ޤ��A�|�P�º������A�ݪ����O�ܲM���C
LONG
	  );
	  set("exits", ([ /* 3 element(s) */
	"east" : __DIR__"down_maze5",
	"west" : __DIR__"down_maze1.c",
	"north" : __DIR__"down_maze4",
]));

	setup();
	  replace_program(ROOM);
}
