inherit ROOM;

void create()
{
	set("short", "�p�٫e");
	set("long", @LONG
�o�̬O�@�Ӥp�٪��e���A�A�b�p�٫e�����Y�N�i�H�ݨ�p�٦��\�h
������A�j���O���}���A�p�٪��~���٦��@�ӫܪ�����ò�A���쨫�Y�~
�ݡA�ܭ@���j�B���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"flurry36.c",
  "eastdown" : __DIR__"flurry38.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
