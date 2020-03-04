// Room: /open/world1/tmr/hasake/caoyuan7.c

inherit ROOM;

void create()
{
	set("short", "�j���");
	set("long", @LONG
�A���i�F�o�M�����������j���A�}�U�O�o�p���C��A�n�������ٯu
���n���A�ݨӶR�ǰ��ӥN�B��O���n�D�N�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"caoyuan9",
  "north" : __DIR__"caoyuan3",
  "south" : __DIR__"caoyuan8",
  "east" : __DIR__"majiu",
]));

	setup();
	replace_program(ROOM);
}
