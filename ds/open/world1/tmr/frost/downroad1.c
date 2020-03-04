// Room: /open/world1/tmr/freezetaoism/downroad1.c

inherit ROOM;

void create()
{
	set("short", "�a�U���D");
	set("long", @LONG
�A���b�@���a�U���D�̡A��q�D���e�A���i�e�Ǥ@�ӤH���ۨ��l�q�L
�A�|�P�R�o�s�@�ڰw���b�a�W����ť���@�M�G���C
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"downroad2",
  "up" : __DIR__"temple7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
