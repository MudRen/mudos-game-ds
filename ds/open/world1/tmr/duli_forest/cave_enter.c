// File: /d/duli_forest/cave_enter.c
// Updated by tmr (Sat Aug 16 20:39:33 2003)

inherit ROOM;

void create()
{
	  set("short", "�F��");
	  set("long", @LONG
�A���B�b�@�Ӥ��j���F�ޤ��A�Y���W���ӥX�h���}�f�A���F�O���`��
�������p�D�A�Q���ٶª��A�������B������C
LONG
	  );
	  set("exits", ([ /* 2 element(s) */
	"east" : __DIR__"cave_path1",
	"up" : __DIR__"map_6_9",
]));

	setup();
	  replace_program(ROOM);
}
