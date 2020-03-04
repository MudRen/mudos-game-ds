// Room: /open/world1/tmr/north_bar/town13.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���е�D");
	set("long", @LONG
�o�̥k��N�O�����a�����f�Ať���������H�ܵ��}�A���O��
��o�n��������дo���Ʊ��C�ө������O���̪��ߤ@���@�f
�j���C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"town11",
  "east" : __DIR__"town20",
  "north" : __DIR__"town15",
  "west" : __DIR__"town6",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
