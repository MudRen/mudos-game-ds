// Room: /u/f/fanny/area/forest/forest5.c

inherit ROOM;

void create()
{
	set("short", "�Q��L");
	set("long", @LONG
���ۤs�|���L�ӡA���@�Ѳ��W�����O�]�����W�j�A���_�Ǫ��O�A
�±�����o�������H�F�A���k���䪺���]���V�ӶV���j���Pı�A��
�G����Ҭݨ쪺���٤j�F�\�h�C�o���ʰѤѥ���A���n������A
�S�T�Q�ӤH�����ٵL�k����C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"forest6",
  "north" : __DIR__"forest2.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
