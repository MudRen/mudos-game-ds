// Room: /open/world1/tmr/bagi/area/1f/map_7_7.c

inherit ROOM;

void create()
{
	set("short", "�H��}�@�h");
	set("long", @LONG
�|�g�����ߤ��_�a�m�˪��A�}�����ūפ@���~�����U�A�����H���֩�
�Y�F�C�b�۹D�W���B���U���}�ޡC
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "down" : "/open/world1/tmr/bagi/area/2f/map_2_2",
  "southeast" : __DIR__"map_8_8",
  "southwest" : __DIR__"map_8_6",
  "northeast" : __DIR__"map_6_8",
  "northwest" : __DIR__"map_6_6",
]));
	set("map_long", 1);
	set("current_light", 3);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
