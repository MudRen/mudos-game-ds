// File: /d/duli_village/sea_room1.c
// Updated by tmr (Tue May  7 20:43:13 2002)

inherit ROOM;

void create()
{
	  set("short", "�j���v���U");
	  set("long", @LONG
�A�����b�@�������Ū����v���U�A�A���B�b�o�ӱI�R���@�ɤW�A�C
�C�a�w�g�����M�F�n��_�F�A�L�L�i�ʪ����y�����عL�A�����ߡC
LONG
	  );
	  set("exits", ([ /* 4 element(s) */
	"north" : __DIR__"sea_room2",
	"south" : __DIR__"sea_room3",
	"east" : __DIR__"sea_room",
	"west" : __DIR__"sea_room",
]));

	setup();
	  replace_program(ROOM);
}
