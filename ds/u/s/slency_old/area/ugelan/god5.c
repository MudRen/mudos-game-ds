// Room: /u/s/slency/area/ugelan/god5.c

inherit ROOM;

void create()
{
	set("short", "�Ӷ�");
	set("long", @LONG
�o�̬O�����˪L���Ӧa, ���ǼX�ӬƦܧ֨�˪L���Y�h�F, �o�̦�
�ǹӸO�Ǫ��d�g�Q���d��, �ݨӤ��[�e�~���H�ʹL, ���L�ݹӸO���~�N
, ���G�]���O�]����I�������Y....�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"god6",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
