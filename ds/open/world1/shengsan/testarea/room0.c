// landroom.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "�j�N���@��(�Ǥ�)");
	set("long",@LONG
�o�̬O���Ū��Ѵ��եΪ��ж��A�w����[�C�A�i�H more here  �H�[��
�o�өж����g�k�C�w��A�[�J�ڤۤC�쪺��C�A�A�������A�A�b�A�ɱ��g�@
���P�ɡA�Ʊ�A�����u�o�̪������W�w�I���A  ���ּ֧֡C
LONG
	);
	set("exits", ([
		"west"    : __DIR__"heatroom",
		"east"	  : __DIR__"universe",
	]) );

	setup();
	replace_program(ROOM);
}