// Room: /u/a/alickyuen/area/dr15.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ICorridor");
	set("long", @LONG
�o�̤H�h��t�I�A�]�����L�ӡA�C�@�ӤH�]���۫ܦh�F��ǳƫe���n
�䪺�f�Хh����L�̪��ˤ͡A��Ӳ{�b��n�O���f�ɶ��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dr16",
  "north" : __DIR__"dr12",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
