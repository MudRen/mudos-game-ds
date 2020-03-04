// Room: /open/world1/tmr/north_bar/town11.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���е�D");
	set("long", @LONG
�o�̤Q�����x�A��B�R���F���x���n���n�A���p�Ī������n
�A�]���q�����ǨӪ��s���n�A�e�������B���@�f���A���̤]�E��
�ܦh�H�A�]�\�����򦳽쪺�ơC
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"town32",
  "north" : __DIR__"town13",
  "west" : __DIR__"town5",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
