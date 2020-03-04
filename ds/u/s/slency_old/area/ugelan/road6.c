// Room: /u/s/slency/area/ugelan/road6.c

inherit ROOM;

void create()
{
	set("short", "[1;33m�վB���j�D[2;37;0m");
	set("long", @LONG
�o�̬O�վB�����ۦW���վB�����j�D�A���W�������P�H�sŨ���X��
�B���Ұꪺ���j�P�I�f�A�q�C�Ӧ�H�T�������A�A�i�H�P���컴�P�P
�ΪA���Pı�A�@���e���e���ϬM�۬Ӯc���˼v�A�h�����@�y����!!
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road5",
  "east" : __DIR__"road4",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
