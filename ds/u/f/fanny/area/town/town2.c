// Room: /u/f/fanny/area/town2.c

inherit ROOM;

void create()
{
	set("short", "���f");
	set("long", @LONG
���誽���A�C�C���i�J�F�����̡C���k��ƪ���𴣨ѧ��̦Ѧ�
�֤֥𶢪��a��A�_��O���W���y�d�B�ȴ̡z�A�ڻD���W�O�e�¤Ӥl
�ҽ窺�C
    �A���誽���N�O�H�ӤH�����j��F�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"town3",
  "north" : __DIR__"towninn1f.c",
  "east" : __DIR__"town1",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/u/f/fanny/area/npc/villager" : 2,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
