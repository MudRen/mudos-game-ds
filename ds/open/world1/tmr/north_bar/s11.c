// Room: /open/world1/tmr/north_bar/s11.c

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
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"s10",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
