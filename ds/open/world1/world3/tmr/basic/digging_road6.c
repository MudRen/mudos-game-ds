// Room: /open/world3/tmr/basic/digging_road6.c

inherit ROOM;

void create()
{
	set("short", "�o���K��");
	set("long", @LONG
�A�����ۤ@���o���K���W�A�A���ɥi�ݨ줣���q�u��۫������ѡB
�K���^�q�ϡA�]�i�ݨ�I�t���K�S�B�Q�r�굥�u�㶶���K�����訫�V�q��
�C�w�o���K���Ǫ����F����A���o�a�ӤF�@����N�C
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "����" : "�Ʈ�������������W������C
",
]));
	set("world", "future");
	set("outdoors", "desert");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"digging_road7",
  "east" : __DIR__"digging_road5",
  "northwest" : "/open/world3/tmr/hunter_forest/forest1",
  "north" : "/open/world3/super-light-area/1.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
