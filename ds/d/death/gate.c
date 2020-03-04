// gate.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW "������" NOR);
	set("long", 
		"�o�̴N�O�ۦW�������J�f�u�������v�M�b�A���e���ߵۤ@�y���j��\n"
		"�¦⫰�ӡM�\\�h�`������ڳڦa�C���e�i�M�]���@�i�������N�L�k�A\n"
		"�^�����F�C\n");
	set("exits", ([
		"north" : "/d/death/gateway",
	]) );
	set("objects", ([
		__DIR__"npc/wgargoyle":1
	]) );
	setup();
	replace_program(ROOM);
}
