// Room: /open/world1/whoami/birdarea/en8.c

inherit ROOM;

void create()
{
	set("short", "[1;37m�F�_[2;37;0m�A�L");
	set("long", @LONG
�A�{�b�Ө�@�B���O�g�۶����a��A�@�}�}���N�������Ө�
�A���O���F�����T�����n�A�N�A�]�S���䥦�����n���F�A�R����
����^�t�äF�@�������߷P�C�A�`�N��b���Ǳ״��ۤ@����P�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"en7",
  "north" : __DIR__"en9",
]));
	set("outdoors", "forest");
	set("no_clean_up", 0);
	set("mob_object", ({ /* sizeof() == 1 */
  __DIR__"npc/fox"
}));
	set("chance", 80);
	set("mob_amount", 3);
	set("current_light", 2);
	set("mob_max", 15);
	set("item_desc", ([ /* sizeof() == 1 */
  "��P" : "�A�³o��P�ݤF��, �o�{�W�����X�Ӥj�r,

       [1;31m�� �W ��     [5m[1;31m�ͤH�Ū�[2;37;0m

�A���T�N�����y, �A�Q�Q�]�\�Ӧ^�Y�F.
",
]));

	setup();
	replace_program(ROOM);
}
