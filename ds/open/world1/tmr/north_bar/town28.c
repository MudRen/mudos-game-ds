// Room: /open/world1/tmr/north_bar/town28.c

inherit ROOM;

void create()
{
	set("short", "�_�Z��-�۾��p�|");
	set("long", @LONG
�o�̧j�ۧN�檺���A���T���H�}�l�o�ݡA�o�̦��G�U�ӷU�S
���H�F�A�Ů������a�۪Ѯ��ƪ��𮧡A�����e��S�ǨӲr�~�H
�S���n���A���ǧ������A�֨ӳo�̡C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"town29",
  "west" : __DIR__"town9",
]));
	set("no_clean_up", 0);
	set("shrot", "�_�Z��-�۾��D��");
	set("outdoors", "land");
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
