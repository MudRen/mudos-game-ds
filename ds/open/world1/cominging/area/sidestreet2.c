inherit ROOM;
void create()
{
	set("short", "����");
	set("long",@LONG
�o���٬O������ť�o����䪺���@��H�a�b�n�x�A�A�ϩ��ݨ즳�\
�h���H�]�F�X�Ӭ����A���L�ѩ���O���۪��A�ҥH���ݤ��줰��F�F�A
����O�����ਤ�A�ө��F��h�O���B�F�����n�䪺��D�W�A�Aı�o�o
�̪���D�W���@�Iż�C
LONG
	);
	set("exits", ([
  "west" : __DIR__"sidestreet1.c",
  "east" : __DIR__"sidestreet3.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
