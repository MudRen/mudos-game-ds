// Room: /u/b/bennyng/area/room25.c

inherit ROOM;

void create()
{
	set("short", "�_�~�c");
	set("long", @LONG
�o�̥ե��@���A�|�P���������A��B�z�X�H��A�ϧA���餣�����o�_
�A�}�l���˭����Pı�D�A�u�Q��ǫO�x���窫���A�M�ӳo�O���i�઺��
�]���|�P���I�@���A�䤣�X����ƪ��D
LONG
	);
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room25",
  "south" : __DIR__"room25",
  "north" : __DIR__"room25",
  "west" : __DIR__"room24",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}