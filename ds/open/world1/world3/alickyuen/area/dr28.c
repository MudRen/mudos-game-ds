// Room: /u/a/alickyuen/area/dr28.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ICorridor");
	set("long", @LONG
�o�̪��񪺩ж����O�ѵ���͡B�@�h�u�@����𮧤@�U�A����|��
�@�ǧɡA���L�̦b�c�����u�@���p�Τ@�|�C�٦��N�O�@�Ǯ������]�ơA�p
�q���B�����ȵ��A�O�A�뤣�o�i�h�p��@�|�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"dr29",
  "north" : __DIR__"dr27",
  "enter" : __DIR__"dr31",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
