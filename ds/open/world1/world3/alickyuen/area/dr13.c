// Room: /u/a/alickyuen/area/dr13.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ICorridor");
	set("long", @LONG
�A���L�F�w�A�g�L�o�����Y�A�ǳƨ��V�n�������E���h�ݯf�A�өM�A
�P�檺�f�H�y�ⳣ�ܮt�A�ӧA��[�ָ}�B�A�K�o�ۤv�n���@�q�ɶ��A�~��
�ݨ���͡C�A��ݨ줣�֦~�����k�f�H�}�ߪ��ѫn�����L�ӡA���D������
�n�ơH
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dr14",
  "north" : __DIR__"dr11",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
