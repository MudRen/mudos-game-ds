// Room: /open/world1/tmr/north_bar/s8.c

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
	set("objects", ([
	  __DIR__"npc/mucus-odd.c" : 3,
 ]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"s9",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
