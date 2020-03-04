// Room: /u/t/tmr/future/area/digging_street4.c

inherit ROOM;

void create()
{
	set("short", "��v�Ϥp��");
	set("long", @LONG
�e���N�O��v�Ϫ��J�f�A���M�i�h�S������ư��A���L���i�H���O�o
�̰ߤ@�ȱo�������a��C�ӧA�q�o�̨��W�h�A�N�i�h��s����a�y�D����
�K�������A�^��D���h�C
LONG
	);
        set("outdoors","desert");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"digging_street3.c",
  "north" : __DIR__"district1",
  "eastup" : __DIR__"train_station1",
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
