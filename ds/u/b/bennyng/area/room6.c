// Room: /u/b/bennyng/area/room6.c

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
  "westdown" : __DIR__"room7",
  "west" : __DIR__"room5",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
