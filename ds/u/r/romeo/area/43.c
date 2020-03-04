// Room: /u/k/king/area/43.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m�C�P�L");
	set("long", @LONG
�o�̬O�Q�j���⤧�@���D�ߪ���ҡA�ݰ_�ӤQ�������ءA���e���Y��
�۷�l�A�ݰ_�Ӯݮݦp�͡A�[�W�����⪺�j���A�@�ݴN���D�O�����H�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"42",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yulo" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
