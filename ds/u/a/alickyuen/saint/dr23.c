// Room: /u/a/alickyuen/area/dr23.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ICorridor");
	set("long", @LONG
�o�̤H�ӤH���A���O�g�Ѥj��e�f�H�h���g�ǡA�ݨ�f�H���W����
���A�A�n�����I�P���L�̡A�礣�Q�L�̦��h�C�o�̨ө����k�k�@�h���O�D
�`�~�����A�O�즳�ܦh�֨k�֤k�ݵۥL�̤u�@�A���j�������ݵۡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dr24",
  "east" : __DIR__"dr4",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
