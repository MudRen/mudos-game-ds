// Room: /open/world1/whoami/birdarea/bird19n.c

inherit ROOM;

void create()
{
	set("short", "[1;36m�ѱ���[0m����");
	set("long", @LONG
�o�̬O�ѱ��Ъ�����A�A���U�F�|�P�A�o�{���|�ڥΤj�z��
�����ѱ��۬W�A�a�O�M�Ѫ�O�]�O�j�z�۰����A�o���󤤪��a�W
�\���F�U���U�˪��į�A�٦��@�a���į������ѡC�@�@���į�
���R���㶡����C
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fon2" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"bird19",
]));
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	set("light", 1);
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
