// Room: /open/world1/acme/bonze/b8.c

inherit ROOM;

void create()
{
	set("short", "�W�s�p��");
	set("long", @LONG
��v�l�l�A����A�����~�q�A���H�ܬ��Y�D�A
    �H�����šA���٨방�A������D�A���Ө�H�N�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"b9",
  "west" : __DIR__"b7",
]));
        set("outdoors","land");

	setup();
	replace_program(ROOM);
}
