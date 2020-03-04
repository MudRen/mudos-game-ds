// Room: /u/k/king/area/r11.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[1;37m-[1;35m����[2;37;0m");
	set("long", @LONG
�i�w�֮c�j�������c�֤ߡA���k�O��Ӱ����A�U���@�����G�Q�V����
�Y�D�۳s�A��զp���䭸�X�����l�A��ӰƷ��A�H�i�����l���j�H�Ρi�k
���l���j���W�A�c�e�@���`�s�A�޶i�¤Ѵ򪺤����A�����ѵM���̻١C
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "south" : __DIR__"r18",
  "west" : __DIR__"r15",
  "north" : __DIR__"r12.c",
  "down" : __DIR__"r10.c",
  "east" : __DIR__"r14",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard7" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
