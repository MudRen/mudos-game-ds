// Room: /u/k/king/area/r37.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m�C�P�L");
	set("long", @LONG
�ڻ��o�̬O�Q�j���⤧�@�������̪���B�A�o���B���O���A�n��
�O�@�B�˪L�A�ݰ_�ӫD�`�����ΪA�A�`��S�q�|���K���ܡA�٬O�ְk��
�a�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r38",
  "north" : __DIR__"r32",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/hunter" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
