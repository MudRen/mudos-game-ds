// Room: /u/l/lestia/area/sn20.c

inherit ROOM;

void create()
{
	set("short", "�_��j�˪L-�p�|");
	set("long", @LONG

�A���e�X�{�F�@���������p�D���q���˪L���`�B�A�L���w�w���j�ӡA�}
�U����a�����ܦ��]�\�h�H���L�ӽ񥭪��d�a�A�d�a�W�٦��\�h�]�\��ӱ�
���ܶ����𸭡A�C���@�B���|ť��P�\���i���ӥͪ��F�F�n�A���K�F�@����
�ơC

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
set("objects", ([
__DIR__"npc/rabbit":2,
]));

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"sn19",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
