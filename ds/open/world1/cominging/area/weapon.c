inherit ROOM;
void create()
{
	set("short", "�Z���E");
	set("long",@LONG
�A�Ө�F�@�Ӧ��I���H�������Pı���a��A�o�̬O�B�F�����@�a�Z
���E�A�M���s�y�Z���@�����Ψ�A�������\�h���K���K�K�A�]���\�h�b
�۩I�ȤH���c�l�A�L�̩��\�X�n�檺�Z�����G�ܦn���ˤl�A���L�����o
���I......�C
LONG
	);
	set("exits", ([
  "west" : __DIR__"boo-lin3.c",
]));
	set("objects", ([
  __DIR__"npc/smith": 1,
]));
	set("no_clean_up", 0);
	set("light", 1);
	setup();
	replace_program(ROOM);
}