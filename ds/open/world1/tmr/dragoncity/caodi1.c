// Room: /open/world1/tmr/dragoncity/caodi1.c

inherit ROOM;

void create()
{
	set("short", "���S���J-��a");
	set("long", @LONG
�o��O���S���J�s���~���j��a�A���_�i�H�樣�֫ӭx
�P��H�K��ڲצ~���Ԫ��D�n�Ԧa�ж��S���J�s���A���M�o
��S���b�I�Ԥ��A���|�g��^�o�O�R�����ݵ±�����C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"caodi3",
  "east" : __DIR__"caodi2",
  "south" : __DIR__"northgate2",
  "north" : __DIR__"caodi6",
]));
	set("mob_amount", 3);
	set("chance", 60);
	set("outdoors", "land");
	set("current_light", 3);
	set("mob_object", ({ /* sizeof() == 3 */
  __DIR__"npc/tiger1",
  __DIR__"npc/tiger2",
  __DIR__"npc/tiger3"
}));

	setup();
	replace_program(ROOM);
}
