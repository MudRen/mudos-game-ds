inherit ROOM;
void create()
{
	set("short", "������");
	set("long",@LONG
�o�̬O�����U�A�b�o�̦��@�ǨǪ��ͪ��A���O�C��@�����A���b�V
�A�ʥʤj�s�A���L�L��A�Ө��S������ˮ`�O�i���A�Ӧb�n��O�����A
�q���������y�y�L�ӡC
LONG
	);
	set("exits", ([
  "south" : __DIR__"well.c",
]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}