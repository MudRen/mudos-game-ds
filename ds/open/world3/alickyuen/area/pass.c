//updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST�CBuilding�IEnterance[2;37;0m");
	set("long", @LONG
�o�̬O�@�ӳq���Ҫ��ӽЯ��A��o�̥i�H���@�Ǧ��ݭn���H�h�ֱ���
�Ш�q�������}�o�Ӱ�a�C����A�Q�ӽЧ󰪯Ū��q���ҥh��L�P�y�ɡA
�A�N�ݭn��t�z�H���J�ҨưȳB�̿�z����A�]���o�̤����Ѫ��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dst14",
]));
set("objects", ([
__DIR__"npc/passport.c" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
