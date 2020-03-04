// Room: /open/world1/whoami/birdarea/bird19.c

inherit ROOM;

void create()
{
	set("short", "[1;36m�ѱ���[0m����");
	set("long", @LONG
�o�̬O�ѱ��Ъ�����, �A���U�F�|�P, �o�{���|�ڥΤj�z��
�����ѱ��۬W, �a�O�M�Ѫ�O�]�O�j�z�۰���, �b�j�U��������
�@�i�۴�, �W�����ۤ@�ӤH, �A�Q�g�������r���H���ӴN�O�L
�F�C
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fon" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"bird19n",
  "west" : __DIR__"bird18",
]));
	set("valid_startroom", 1);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("light", 1);

	setup();
	replace_program(ROOM);
}
