// Room: /u/l/lestia/area/sn11.c

inherit ROOM;

void create()
{
	set("short", "�_��j�˪L");
	set("long", @LONG
�@�����𸭦b�A�Y�W���R�ۡA�ǳ\�������ǵ۸��P�������_�ج�g�L��
�A�ϱo�a�W�¦⪺�𽮯B�{���I�I���ɡA�F�۩v�K�O���é�o���s�j���˪L
�����A�\�h���߾ǲߤ۳N���H�̡A���Q�����J�F�۩v�C
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sn10",
  "south" : __DIR__"sn12",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
