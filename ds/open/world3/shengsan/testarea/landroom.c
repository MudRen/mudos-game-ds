// landroom.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "���Ӫ��@��(����)");
	set("long",@LONG
�o�̬O���Ū��Ѵ��եΪ��ж��A�w����[�C�A�i�H more here  �H�[��
�o�өж����g�k�C�w��A�[�J�ڤۤC�쪺��C�A�A�������A�A�b�A�ɱ��g�@
���P�ɡA�Ʊ�A������u�o�̪������W�w�I���A  ���ּ֧֡C
LONG
	);
	set("exits", ([
		"east" : __DIR__"forestroom",
		"past" : SHENGSAN1+"testarea/landroom",
		"now"  : SHENGSAN2+"testarea/landroom",
	]) );

	set("outdoors","land");
	setup();
	replace_program(ROOM);
}