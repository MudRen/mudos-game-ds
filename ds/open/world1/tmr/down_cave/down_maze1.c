// File: /d/down_cave/down_maze1.c
// Updated by tmr (Mon Aug 18 02:27:34 2003)

inherit ROOM;

void create()
{
	  set("short", "�Ŭ}��");
	  set("long", @LONG
�A���b�@�ӪŪŦp�]���}�ޤ��A�|�P�º������A�ݪ����O�ܲM���C
LONG
	  );
	  set("exits", ([ /* 2 element(s) */
	"east" : __DIR__"down_maze2.c",
	"west" : __DIR__"down_maze3.c",
]));

	setup();
	  replace_program(ROOM);
}
