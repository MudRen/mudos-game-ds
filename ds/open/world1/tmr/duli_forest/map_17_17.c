// File: /d/duli_forest/map_17_17.c
// Updated by tmr (Mon Mar 11 02:37:08 2002)

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
	  set("exits", ([ /* 2 element(s) */
	"west" : __DIR__"map_17_16",
	"north" : __DIR__"map_16_17",
]));

	setup();
	  replace_program(ROOM);
}
