// File: /d/duli_forest/map_17_14.c
// Updated by tmr (Mon Mar 11 02:37:01 2002)

inherit ROOM;

void create()
{
	  set("short", "�p��");
	  set("long", @LONG
�b�|�P���F�������F��W�A���X�B�S�O�����p�s�C�A�H�ۭ��_�ӱY�ѡC
LONG
	  );
	  set("outdoors", "land");
	  set("map_long", 1);
	  set("exits", ([ /* 3 element(s) */
	"east" : __DIR__"map_17_15",
	"west" : __DIR__"map_17_13",
	"north" : __DIR__"map_16_14",
]));

	setup();
	  replace_program(ROOM);
}
