// xiaowu2.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�o���O�p�s�k�޾i�V�m�ɸ������ΡA�Ψ��W���۫ܦh�Ӥ����Ϊ���
�_�A�٥��i���A�N�D�o��@�}���e�������C
LONG	);
	set("exits", ([
		"west"  : __DIR__"mudao12",
		"south" : __DIR__"mudao13",
	]));
	set("objects", ([
		__DIR__"obj/fengjiang" : 3,
		__DIR__"obj/fengmi" : 1,
	]));


	setup();
	replace_program(ROOM);
}
