// Room: /open/world1/acme/bonze/b20.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�o�ӱ�ЩҺت��_�̬O�ѵ��u�ⶳ�x�v�M�|�ҭ��Ϊ��A�u�ⶳ�x
�v���j�j�p�p���O�a�o�ӱ�йL��l���C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"b11",
]));
        set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
