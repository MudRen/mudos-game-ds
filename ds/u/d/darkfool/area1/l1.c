// Room: /u/d/darkfool/area1/l1.c

inherit ROOM;

void create()
{
	set("short", "��D-���Ϯ��]");
	set("long", @LONG
�o����D�q����W���Ϯ��]�A�]�N�O�A���n������L�h�ݨ쪺��
�l���I�ǥժ��ؿv���A�Ө�ëD�t���ΡA�ӬO�H�@�������j�z�۪���
��ئ��A�����өM����f���۬W�@�ˬO�ݩ�j���@�����C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"32",
  "south" : __DIR__"l2",
]));

	setup();
	replace_program(ROOM);
}
