// File: /d/duli_forest/cave_path2.c
// Updated by tmr (Sat Aug 16 21:48:06 2003)

inherit ROOM;

void create()
{
	  set("short", "�F�ޤp�D");
	  set("long", @LONG
�A�����b�@���F�ޤp�D���A���g�N�N�|�M�|�P���F���i����A���_��
�ǹ����H�y�³s�s�C
LONG
	  );
	  set("exits", ([ /* 2 element(s) */
	"east" : "/d/down_cave/map_2_0",
	"west" : __DIR__"cave_path1",
]));

	setup();
	  replace_program(ROOM);
}
