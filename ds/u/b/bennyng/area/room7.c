// Room: /u/b/bennyng/area/room7.c

inherit ROOM;

void create()
{
	set("short", "�H�۸�");
	set("long", @LONG
�o�̬O�����c�M�ЬӤj������ɳB�A��ǳ��غ������A�o�̥i�H�ݨ�
���媺�����D
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"room8",
  "eastup" : __DIR__"room6",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
