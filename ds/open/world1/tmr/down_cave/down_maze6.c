// File: /d/down_cave/down_maze6.c
// Updated by tmr (Mon Aug 18 02:30:10 2003)

inherit ROOM;

void create()
{
	  set("short", "�Ŭ}��");
	  set("long", @LONG
�A���b�@�ӪŪŦp�]���}�ޤ��A�|�P�º������A�ݪ����O�ܲM���C
LONG
	  );
	  set("exits", ([ /* 4 element(s) */
	"south" : __DIR__"down_maze3",
	"east" : __DIR__"down_maze7",
	"west" : __DIR__"down_maze3",
	"north" : __DIR__"down_maze3",
]));

	setup();
	  replace_program(ROOM);
}
