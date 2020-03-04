// Room: /open/world1/tmr/north_bar/town14.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���е�D");
	set("long", @LONG
�Ө�o�̡A�A�oı�P��}�l�����F�A�ӥB���춧���Ӯg����
�n�}�l��֤F�A��_�����ЦV�������㩱�A�檺���O�����W�n��
����A���L�o���@�V�M���A�]�S������ɪ��A�������ͷN�]�N�T
�T���F�C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"town12",
  "east" : __DIR__"town7",
  "northwest" : __DIR__"town16",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
