// Room: /u/l/lestia/area/sn19.c

inherit ROOM;

void create()
{
	set("short", "�_��j�˪L-�p�|");
	set("long", @LONG
�u�ۤp�D���F�L�ӡA�A�o�{�쥻�������p�D�}�l�s���U�p�A���G���\�h
�H����o�̫K�^�Y�ӥh�A�쥻�Q�񥭪��d�g�}�l�ܦ������O�ͪ���a�A�A��
���}�l�h�áA������L�̳��u����o�̦Ӥ��~�򪺩��e���O�H
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"sn20",
  "south" : __DIR__"sn18",
]));
set("objects", ([ 
__DIR__"npc/wolf":2,
]));

	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
