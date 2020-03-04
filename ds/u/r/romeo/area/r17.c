// Room: /u/k/king/area/r17.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[1;37m-[1;35m����[2;37;0m");
	set("long", @LONG
�ӳ����a���s�A���իF�O���A��H�´ˡA�̦a�զӫءA�I�a�s�^�D�c
�i���𷵡j�A��O�ӳ��y�l�ӫҡz�o�W���ӥѡC�ӳ��D�c���q�ѻڡA�q�X
��s�c���W�A�Ϭӳ��D�c�i���𷵡j������ӳ��a�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"r14",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard2" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
