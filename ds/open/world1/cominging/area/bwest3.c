inherit ROOM;
void create()
{
	set("short", "�B�F����j��");
	set("long",@LONG
�o�̬O��j��A�A�@����F�o�̴N�Pı���������n�[�n�A��ӬO�n
��Ѥf�����Y�@��H�b�n�[�A�����쬰�����n���|�o�򪺤j�n�A�s�o��
��ť�o��A�b�F�_�䦳�@�a�ĩ��A�����ͷN�n�L�A�F��O�������s���A
�Ӧ���]�h�O����j���C
LONG
	);
	set("exits", ([
  "east" : __DIR__"bwest2.c",
  "west" : __DIR__"bwest4.c",
  "south" : __DIR__"sidestreet.c",
]));
	set("objects",([
  __DIR__"npc/woman" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
