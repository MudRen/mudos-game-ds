// Room: /open/world3/alickyuen/area/dst17.c

inherit ROOM;

void create()
{
	set("short", "[1;36mCircle tunnel�ISaint[2;37;0m");
	set("long", @LONG
�A�����ۤ@���s��saint ���M�q�Ϫ���H�q�D�A���n�����i�q���¥@
�ɱ��q�ϡA���_�����B�N�O�����F�A�ɬO�������H��C�o���q�D�e�B�b�@
��ާΪ����@�������A�����a�j���F�q�Ϥ���©���D���Ů�C
LONG
	);
	set("world", "future");
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/world3/tmr/basic/district1",
  "enter" : __DIR__"gate1.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
