// Room: /u/a/acme/area/pathway6.c

inherit ROOM;

void create()
{
	set("short", "�ϸz�p�|");
	set("long", @LONG
�o�̬O�@���p�|�A���_��i�ݨ��@���p�ΡA�p�|�G�ǺɬO����A�p
�|�������i���@����񩹥_�����A���n���@���p���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"h",
  "south" : __DIR__"pathway5",
]));
	set("no_clean_up", 0);
      set("outdoors","land");

	setup();
	replace_program(ROOM);
}
