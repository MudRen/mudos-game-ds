// Room: /open/world1/tmr/hasake/caoyuan5.c

inherit ROOM;

void create()
{
	set("short", "�j���");
	set("long", @LONG
�A���i�F�o�M�����������j���A�}�U�O�o�p���C��A�n�������ٯu
���n���A�ݨӶR�ǰ��ӥN�B��O���n�D�N�C
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/sheep" : 1,
  __DIR__"npc/hasake" : 1,
]));
	set("no_clean_up", 0);
	set("current_light", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"caoyuan6",
  "south" : __DIR__"caoyuan2",
  "east" : __DIR__"caoyuan4",
]));

	setup();
	replace_program(ROOM);
}
