// File: /d/duli_village/sea_room6.c
// Updated by tmr (Wed May  8 22:47:47 2002)

inherit ROOM;

void create()
{
	  set("short", "�j���v���U");
	  set("long", @LONG
�A�����b�@�������Ū����v���U�A�L�L�i�ʪ����y�����عL�A����
��A�@�D���G�����~�z�L�������g�U�ӡA���A�j�j���@���|�P���ҡA�@�s
�s�����W�����ॿ�b�����t�@���V���B��ʡC
LONG
	  );
	  set("exits", ([ /* 2 element(s) */
	"east" : __DIR__"sea_room4",
	"west" : __DIR__"sea_room7",
]));

	setup();
	  replace_program(ROOM);
}
