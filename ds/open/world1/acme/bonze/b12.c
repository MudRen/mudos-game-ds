// Room: /open/world1/acme/bonze/b12.c

inherit ROOM;

void create()
{
	set("short", "�ⶳ�x");
	set("long", @LONG
�A���Y�@��A�W�����@����СA�W���g�ۡu�ⶳ�x�v�T�Ӥj�r�A
�����s�D�A�a�l���O�A�x���e���Ⱖ�۷�l�A�@���@�k�ۦb�x�|����
�ǡA���ͭ��A�O�H��ӫo�B�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"b13",
  "southwest" : __DIR__"b11",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
