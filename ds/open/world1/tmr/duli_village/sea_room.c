// File: /d/duli_village/sea_room.c
// Updated by tmr (Tue May  7 20:42:04 2002)

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
	"north" : __DIR__"sea_room",
	"south" : __DIR__"sea_room",
	"east" : __DIR__"sea_room1",
	"west" : __DIR__"sea_room2",
]));

	setup();
	  replace_program(ROOM);
}
