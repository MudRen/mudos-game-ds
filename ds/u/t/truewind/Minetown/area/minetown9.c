// Room: /u/t/truewind/Minetown/area/minetown9.c

inherit ROOM;

void create()
{
	set("short", "�q����");
	set("long", @LONG
�o�O�@���p�p�����Ѥl�A�����ͪ��F�\�h�����C�ý��]�����F
�|�P������C�V�n�~�򨫬O�q���q������a���ߤ@�����C�q���̸g�`
��_���⭷�b�o�̴X�G�Pı����A���W�����R�y�L�W�Ū����h�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"minetown8",
  "south" : __DIR__"leaderroom",
]));

	setup();
	replace_program(ROOM);
}
