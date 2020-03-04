// Room: /open/world1/tmr/freezetaoism/downroad2.c

inherit ROOM;

void create()
{
	set("short", "�a�U���D");
	set("long", @LONG
�A���b�@���a�U���D�̡A��q�D���e�A���i�e�Ǥ@�ӤH���ۨ��l�q�L
�A�q�D���Y���B�q����U�@�h���۱�C
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"downroad3",
  "west" : __DIR__"downroad1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
