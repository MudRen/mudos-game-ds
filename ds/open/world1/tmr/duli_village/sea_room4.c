// File: /d/duli_village/sea_room4.c
// Updated by tmr (Wed May  8 22:44:07 2002)

inherit ROOM;

void create()
{
	  set("short", "�j���v���U");
	  set("long", @LONG
�A�����b�@�������Ū����v���U�A�A���B�b�o�ӱI�R���@�ɤW�A�C
�C�a�w�g�����M�F�n��_�F�A�L�L�i�ʪ����y�����عL�A�����ߡC
LONG
	  );
	  set("exits", ([ /* 3 element(s) */
	"down" : __DIR__"sea_room5",
	"west" : __DIR__"sea_room6",
	"up" : __DIR__"map_6_2",
]));

	setup();
	  replace_program(ROOM);
}
