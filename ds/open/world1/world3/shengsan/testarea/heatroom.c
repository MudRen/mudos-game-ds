// heatroom.c

inherit ROOM;

void create()
{
	set("short", "���Ӫ��@��(���s)");
	set("long",@LONG
�o�̬O���Ū��Ѵ��եΪ��ж��A�w����[�C�A�i�H more here  �H�[��
�o�өж����g�k�C�w��A�[�J�ڤۤC�쪺��C�A�A�������A�A�b�A�ɱ��g�@
���P�ɡA�Ʊ�A�����u�o�̪������W�w�I���A  ���ּ֧֡C
LONG
	);
	set("exits", ([
		"east" : __DIR__"room0",
		"west" : __DIR__"desertroom",
	]) );

	set("outdoors","heat");
	setup();
	replace_program(ROOM);
}