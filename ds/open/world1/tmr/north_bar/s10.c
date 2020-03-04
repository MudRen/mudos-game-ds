// Room: /open/world1/tmr/north_bar/s10.c

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
//	  __DIR__"npc/anthropophagi-monster" : 1,
	  __DIR__"npc/horn-monster" : 1,
	  __DIR__"npc/predator-monster" : 1,
	  __DIR__"npc/rough-monster" : 1,
//	  __DIR__"npc/single-monster" : 1,
 ]));

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"s4",
  "east" : __DIR__"s11",
  "west" : __DIR__"s5",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
