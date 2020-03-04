// Room: /open/world1/tmr/north_forest/sn20.c

inherit ROOM;

void create()
{
	set("short", "�_��j�˪L-�J�f");
	set("long", @LONG
�A���e�X�{�F�@���������p�D���q���˪L���`�B�A�L���w�w���j�ӡA�}
�U����a�����ܦ��]�\�h�H���L�ӽ񥭪��d�a�A�d�a�W�٦��\�h�]�\��ӱ�
���ܶ����𸭡A�C���@�B���|ť��P�\���i���ӥͪ��F�F�n�A���K�F�@����
�ơC
LONG
	);
	set("current_light", 4);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/rabbit" : 2,
]));
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/open/world1/faceoff/sky/ten18",
  "west" : __DIR__"sn19",
]));

	setup();
	replace_program(ROOM);
}
