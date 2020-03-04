// Room: /u/k/king/area/r15.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[1;37m-[1;35m����[2;37;0m");
	set("long", @LONG
�o�̬O�������Ʈc�A�b��ɤ]�N�O�ҿת���c�A�o�̬O��Z�ʩx�W��
�ɡA�ΨӫݩR���B�A�o�̦�����O�������^�ت��A�W�Y���F�\�h��O���A
�b��W�g�F�|�Ӥj�r�u���v�u���v�u��v�uĳ�v�A���r���p�f�A��㭱��
�����|�j�����A�ݨӦ��G�O���F�Ϥ��o�Ǥ�O�����\�ΡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"r11",
  "northwest" : __DIR__"r16",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard6" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
