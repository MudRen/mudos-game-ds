// Room: /u/a/aring/tomb/7.c

inherit ROOM;

void create()
{
	set("short", "�j�Ӷ�Фp��L");
	set("long", @LONG
�o�̬O�Ӷ�̪��p��L�A��L���j���ۿ@�@������A��K�W�u��
�Q�~�Ϯ��A�Pı�_�Ӧ���I�I�a�C
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"9.c",
  "northwest" : __DIR__"5.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
