inherit ROOM;
void create()
{
	set("short", "�B�F����j��");
	set("long",@LONG
�o�O�B�F��������j���Y�A�b��W���\�h�p�Ĥl�b�Q�רƱ��A�A��
��ť�줰�򤫩��B�������a�������A���G�ܷQ�n���ˤl�A�b�F��O�B�F
���������s���A�Ӧb���h�O����j���e�i�����A�o�̪����񦳤@�Ǫ�
���E�A�n���ͷN�٤����C
LONG
	);
	set("exits", ([
  "east" : __DIR__"bwest.c",
  "west" : __DIR__"bwest2.c",
  "north" : __DIR__"herbshop.c",
]));
	set("objects",([
  __DIR__"npc/child1.c":1,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
