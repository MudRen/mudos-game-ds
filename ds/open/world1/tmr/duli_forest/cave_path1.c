// File: /d/duli_forest/cave_path1.c
// Updated by tmr (Sat Aug 16 20:43:20 2003)

inherit ROOM;

void create()
{
	  set("short", "�F�ޤp�D");
	  set("long", @LONG
�A�����b�@���F�ޤp�D���A���g�N�N�|�M�|�P���F���i����A���_��
�ǹ����H�y�³s�s�C
LONG
	  );
	  set("exits", ([ /* 3 element(s) */
	"south" : __DIR__"cave_path3",
	"east" : __DIR__"cave_path2",
	"west" : __DIR__"cave_enter",
]));

	setup();
	  replace_program(ROOM);
}
