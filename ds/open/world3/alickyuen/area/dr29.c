// Room: /u/a/alickyuen/area/dr29.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ICorridor");
	set("long", @LONG
�o�̬O���Y�����Y�A�Ӹ̭��N�O��|�̰��v�O�̡Са|�����ж��A��
����ͳ��n�i�h���|�������աK�K�өҦ��f�H�X�|���n���|�������A��
�Lť�D�L�u���i�ȱo�ܡA���u���b�Q�׵ۥL���@�|�@�ʡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dr28",
  "enter" : __DIR__"dr32",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
