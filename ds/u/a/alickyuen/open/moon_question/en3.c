#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��O�j�|");
	set("long", @long
�o�̥��O�@�~�@�ת�����`����O�j�|���a�A�o�̤H�s�H���A��
���o�ܡC�A���Y�W���O�@��來�m�}�A����O�A�������񦳶��A�ڦ�
�h�ӳзs�A�����ɦ��A���o����y�F�@�ӫܦn����^�C
��F������: ferrero,drjr,andygi,hcc,been,monk,abaw,ericsson
long);
	set("exits", ([
		"east" : __DIR__"en2",
		"west" : __DIR__"room",
	]));
	set("objects", ([
//                "/obj/board/record" : 1,
	]));
	set("light", 1);
	set("no_recall", 1);

	setup();
}
