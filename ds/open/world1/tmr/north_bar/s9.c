// Room: /open/world1/tmr/north_bar/s9.c

inherit ROOM;

void create()
{
	set("short", "�d�~�j�}-�a�U�G�h");
	set("long", @LONG
�o�̪��a�����O�d�h�A�u�n�A�@���p�ߡA�}�N�|���J�d�ڤ�
�A���A��ʤQ���x���C�S����ư����~���l���A�٬O�p�ߤ@�I�a
�C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"s3",
  "east" : __DIR__"s5",
  "west" : __DIR__"s8",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
