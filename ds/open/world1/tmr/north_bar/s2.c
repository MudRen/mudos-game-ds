// Room: /open/world1/tmr/north_bar/s2.c

inherit ROOM;

void create()
{
	set("short", "�d�~�j�}-�a�U�G�h");
	set("long", @LONG
�A���ۨ��ۡA��M�A�Aı�o�a�W�H�H���B�n�n���A���G�|�W
���U�h�C��ӡA�o�a�W���@�j�����d�ڡA�Ϧ����A���_���ӧ�
��K�F�C
LONG
	);
	set("objects", ([
//	  __DIR__"npc/anthropophagi-monster" : 1,
//	  __DIR__"npc/horn-monster" : 1,
	  __DIR__"npc/predator-monster" : 1,
	  __DIR__"npc/rough-monster" : 1,
	  __DIR__"npc/single-monster" : 1,
 ]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s1",
  "east" : __DIR__"s4",
  "north" : __DIR__"s5",
  "west" : __DIR__"s3",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
