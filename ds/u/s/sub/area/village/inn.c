// Room: /u/s/sub/area/village/inn.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�o�̬O���ѱC�C���a�̡A�Τ������]�۷�����²��A�i�H�ݥX�o�O
�@��۷��~�����H�C�p�G�֤F�Ϊ̨{�l�j�F�i�H�ӳo���T���ѱC�C�|
�ܼ��ߪ��۫ݧA���C���L�ѤU�S���զY�����\�A��M�n���o�@�ǨǪ�����
��@�O��§�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"vi04",
]));
	set("current_light", 4);
	set("world", "undefine");
	set("light", "1");
	set("room_type", "food");
	set("valid_startroom", "1");
    set("objects", ([
    __DIR__"npc/village_waiter_5" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
