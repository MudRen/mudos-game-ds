#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��O�j�|");
	set("long", @long
�o�̥��O�@�~�@�ת�����`����O�j�|���a�A�o�̤H�s�H���A��
���o�ܡC�A���Y�W���O�@��來�m�}�A����O�A�������񦳶��A�ڦ�
�h�ӳзs�A�����ɦ��A���o����y�F�@�ӫܦn����^�C
long);
	set("exits", ([
		"east" : __DIR__"en1",
		"west" : __DIR__"en3",
	]));
	set("objects", ([
		__DIR__"obj/rules" : 1,
	]));
	set("light", 1);
	set("no_recall", 1);

	setup();
}
