// Room: /open/world1/tmr/north_bar/shop.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���E");
	set("long", @LONG
�o�̬O�@����Q�A�A�i�H�ݨ���f���ⰼ�ߵ۶��˵P�A�W�D�g��
�y��������A����L�ۡz�K�Ӫ����j�r. 
LONG
	);
	set("no_clean_up", 0);
      set("objects", ([ __DIR__"npc/hu-mai":1, ]));
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"town18",
]));
	set("current_light", 1);
	set("light", 1);
	set("room_type", "shop");

	setup();
	replace_program(ROOM);
}
