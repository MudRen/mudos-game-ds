// Room: /d/xiangyang/juyimale.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�k�ȩ�");
	set("long", @LONG
�o�O����䪺�[�СA�]�����`���ۡA���u�ܩ��t�C�и̧O
�L�L���A�u�������۴X�i���B�o�εΪA�A���j�ɡA�ݵ۴N��
�H�Q��ı�C
LONG );
	set("sleep_room", "1");
	set("no_clean_up", 0);

	set("exits", ([
		"east" : __DIR__"juyihuayuan",
	]));
	set("coor/x", -531);
	set("coor/y", -503);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}