// File: /d/duli_forest/map_17_1.c
// Updated by tmr (Mon Mar 11 02:35:11 2002)

inherit ROOM;

void create()
{
	  set("short", "�p��");
	  set("long", @LONG
�@�����F�����A���L���ȫȲ������Q���F�B�\��A���H�C�}�C
LONG
	  );
	  set("outdoors", "land");
	  set("map_long", 1);
	  set("objects", ([ /* 1 element(s) */
	__DIR__"npc/oldman" : 1,
]));
	  set("exits", ([ /* 2 element(s) */
	"east" : __DIR__"map_17_2",
	"north" : __DIR__"map_16_1",
]));

	setup();
	  replace_program(ROOM);
}
