// Room: /open/world1/tmr/north_bar/s3.c

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
      __DIR__"npc/anthropophagi-monster" : 3,
      __DIR__"npc/horn-monster" : 3,
    __DIR__"npc/predator-monster" : 3,
    __DIR__"npc/rough-monster" : 3,
    __DIR__"npc/single-monster" : 3,

 ]));

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"s2",
  "north" : __DIR__"s9",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
