// Room: /open/world1/tmr/north_bar/s7.c

inherit ROOM;

void create()
{
	set("short", "�d�~�j�}-�a�U�G�h");
	set("long", @LONG
�o�̪��a�O������|��ƤF�A���O�ۤϪ��a���o�_�ʱo��F
�`�F�C�e���i�H�ݨ�@�ӥΥۿj�سy�Ӧ����p�ж��A�����D�̭�
������_�S���F��A�Ϊ̬O�S����M�I�����~�H
LONG
	);
	set("objects", ([
	  __DIR__"npc/anthropophagi-monster" : 2,
	  __DIR__"npc/horn-monster" : 2,
//	  __DIR__"npc/predator-monster" : 1,
//	  __DIR__"npc/rough-monster" : 1,
//	  __DIR__"npc/single-monster" : 1,
 ]));

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s6",
  "east" : __DIR__"s17",
  "north" : __DIR__"s18",
  "west" : __DIR__"s16",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
