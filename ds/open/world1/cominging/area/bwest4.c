inherit ROOM;
void create()
{
	set("short", "�B�F����j��");
	set("long",@LONG
�A�@����o�Pı�o�̫ܵL�᪺�ˤl�A����F�賣�S���A�����X�Ӱ�
���]�F�L�h�A�M�@�ǨǪ��H�̸g�L�A��o���ǵL��A���L�o�̫ܪ��m�A
�ܾA�X���@�Ǥj�������ʡA���~�Ӫ��\�h�j���ʳ��b�o�|��Ϊ̬O�b��
���s���C
LONG
	);
	set("exits", ([
  "east" : __DIR__"bwest3.c",
  "west" : __DIR__"bwest5.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
