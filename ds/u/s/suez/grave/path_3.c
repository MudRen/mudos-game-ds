// Room: /u/s/suez/grave/path_3.c

inherit ROOM;

void create()
{
	set("short", "�y�s�p�D");
	set("long", @LONG
�D��ŧŧ�A�ͻﳾ�s������աA�s�D���M����A����Ǫ��s���M�R�A
���H�X�G�ѰO�s�D������C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"path_4",
  "eastup" : __DIR__"path_2",
]));
        set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
