// Room: /open/world1/tmr/north_bar/s12.c

inherit ROOM;

void create()
{
	set("short", "�d�~�j�}-�a�U�G�h");
	set("long", @LONG
�o�̪��a���٬O����Ʒƪ��A������S���e�����Y���F�A��
�O�o�̪��a�����G�`�`�b�_�ʡA�ӥB�X�G�S����L�C�����|���|
��@�b��M��Ӭ}���U�ӡE�E
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
      __DIR__"npc/anthropophagi-monster" : 3,
      __DIR__"npc/horn-monster" : 3,
    __DIR__"npc/predator-monster" : 3,
    __DIR__"npc/rough-monster" : 3,
    __DIR__"npc/single-monster" : 3,

	]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"s13",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
