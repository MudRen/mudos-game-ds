// Room15.c

inherit ROOM;

void create()
{
	set("short","���Ѥ���");
	set("long", @LONG
�o�ж��O���D�M���ѭ̥𮧤��B�A�������\��ۤ@�G�i�O�A����
�̳��i�����ưȤ��ΡC�Ӧ��B�]���ۤ@��Ѻ����C���b�a�W�C

LONG
	);
	set("objects",([
__DIR__"item/greensword2" :1,
__DIR__"item/heaven_box" :1,
]));
	set("exits", ([
	]));
	set("light",1);
	set("no_kill",1);
set("no_goto",1);
	setup();
	set("stroom",1);
	call_other( "/obj/board/sky_room05_b", "???" );
}
