// Room: /u/m/mulder/area/road5.c

inherit ROOM;

void create()
{
	set("short", "�s���o��-��D");
	set("long", @LONG
�o�O�s���o�ө��󪺨䤤�@�����D�A�i�b�o����R�A�Q�R
���F��D�_��O�@���Ȧ�A�ӫn��O�@���Z�����D�@
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road3",
"north" : __DIR__"bank",
"south" : __DIR__"weaponshop",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
