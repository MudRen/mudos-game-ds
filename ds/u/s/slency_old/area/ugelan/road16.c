// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "�C�۵�D");
	set("long", @LONG
�@���H�ӤH������D�A���񪺩Ъ٤j�h����򳬡A���a�èS������
�ө��A�����W���۩��㪺�����A�ݨӬO�ө��W�c�������ҳy�����A���_
�����B�K���@���e�`�F�A���n�O�@���j��C
LONG);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road15",
  "south" : __DIR__"road7",
]));
 	set("outdoors", "land");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
