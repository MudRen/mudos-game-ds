// Room: /open/world3/tmr/hunter_forest/forest1.c

inherit ROOM;

void create()
{
	set("short", "���i���˪L�J�f");
	set("long", @LONG
�A�����ۥ��i���˪L���J�f�A���_�@�K�`�񪺤@�y�˪L�A�N�O���i��
�˪L�C�o�y�˪L���y�H���|�������A�H�O�����㪺�۵M�ͺA�ӻD�W�A�˪L
�`�������W���ʡB�Ӫ��A�ثe�˪L���u�}��@�p�ϡA�ѧ@�y�H���窺����
�A��l�a�謰�y�H���|�U�O�ʳ��A�קK�~�ɥ��Z�C
LONG
	);
	set("world", "future");
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/open/world3/tmr/basic/digging_road6",
  "north" : __DIR__"forest2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
