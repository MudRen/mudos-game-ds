// Room: /u/k/king/area/r18.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[1;37m-[1;35m����[2;37;0m");
	set("long", @LONG
�b�o�M���������۬۷�h���p�D�A�ݥh�u���@�����O�@�ӼҤl�L�X��
����L�A�u���ӳ������f�B�����j���۸O�v�������h�A���T�O�H�ߵJ�A
�b�o�̱N�n�g���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"r19",
  "north" : __DIR__"r11",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mman" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
