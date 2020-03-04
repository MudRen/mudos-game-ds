// Room: /open/world1/tmr/dragoncity/shop.c

inherit ROOM;

void create()
{
	set("short", "���E");
	set("long", @LONG
�o�̬O�Y�s�������@����Q�A�A�i�H�ݨ�b���f���ⰼ�A
�g�ۡy��������A����L�ۡz�K�Ӫ����j�r�C
LONG
	);
	set("no_clean_up", 0);
      set("objects", ([ __DIR__"npc/hu-mai" :1,]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"northroad1e",
]));
	set("current_light", 1);
	set("light", 1);
	set("room_type", "shop");

	setup();
	replace_program(ROOM);
}
