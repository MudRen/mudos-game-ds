// Room: /d/shaolin/muwu.c

inherit ROOM;

void create()
{
	set("short", "�p���");
	set("long", @LONG
�o�O�@��²�����p��ΡA�Τ��a���ۤ@�i��O�ɡA�����O
�@�i���A��W��۵����ȵx�M�L���ֶ��A�@�ݥD�H�N�O�@��Ū
�ѤH�A�Υ~�O�@���A�񪺦˪L�C
LONG
	);
	set("no_clean_up", 0);

	set("exits",([
	"east" : __DIR__"zhulin/exit",
]));

	setup();
	replace_program(ROOM);
}
