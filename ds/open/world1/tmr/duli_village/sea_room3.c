// File: /d/duli_village/sea_room3.c
// Updated by tmr (Tue May  7 20:43:43 2002)

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
	"north" : __DIR__"sea_room1",
	"south" : __DIR__"sea_room4",
	"east" : __DIR__"sea_room3",
	"west" : __DIR__"sea_room2",
]));

        set("objects",([
                __DIR__"npc/shark":1,
        ]));
	setup();
	  replace_program(ROOM);
}
