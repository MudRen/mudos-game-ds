// File: /d/duli_port/map_11_10.c
// Updated by tmr (Thu Feb 28 01:52:45 2002)

inherit ROOM;

void create()
{
	  set("short", "�����s��");
	  set("long", @LONG
�o�̬O�@�B���a��j�������s���A�n�_�V���D���A�H�ӤH���A�Q����
���x�C�s���������\�F�Ӥj�����A�Ѥf�������H�ܤ��ΡC
LONG
	  );
	  set("map_long", 1);
	  set("objects", ([ /* 1 element(s) */
	__DIR__"obj/pot" : 1,
]));
        set("no_fight",1);
	  set("exits", ([ /* 4 element(s) */
	"east" : __DIR__"map_11_11",
	"north" : __DIR__"map_10_10",
	"west" : __DIR__"map_11_9",
	"south" : __DIR__"map_12_10",
]));
	  set("outdoors", "land");

	setup();
	load_object("/daemon/board/duli_board");
	load_object("/daemon/board/duli_board");
}
