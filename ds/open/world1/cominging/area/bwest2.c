inherit ROOM;
void create()
{
	set("short", "�B�F����j��");
	set("long",@LONG
�o�O�@���j�󪺰_�Y�A���G�ܺ������ˤl�A�����_�ӫo���|�p�A�Q
���������A�o����O�Ѥg�[���Y�Ҳզ��A�ҥH�A�����O�|�Pı�}���|��
�@�I�h�A�ӷ������g�L�ɴN�|�����l�d����Y���n���X�{�A�F��O��
�s���A�Ӧ���h�O����j���C
LONG
	);
	set("exits", ([
  "east" : __DIR__"bwest1.c",
  "west" : __DIR__"bwest3.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
