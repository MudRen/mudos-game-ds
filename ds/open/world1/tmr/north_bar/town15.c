// Room: /open/world1/tmr/north_bar/town15.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���е�D");
	set("long", @LONG
�Ө�o�̡A�A�oı�P��}�l�����F�A�ӥB���춧���Ӯg����
�n�}�l��֤F�A�F�_�������Z�����A�p�G�A���ݭn���ܡA�]�i�H
�h����ݬݡC���L�o���@�V�M���A�]�S������ɪ��A�������ͷN
�]�N�T�T���F�C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"town26",
  "south" : __DIR__"town13",
  "west" : __DIR__"town7",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
