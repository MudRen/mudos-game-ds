inherit ROOM;
void create()
{
	set("short", "�B�F���F�����e");
	set("long",@LONG
�o�̬O�B�F���F��j���e���s���A�e�@�Ӳy�Ϊ��b�꩷�A�b�o�঳
�@�Ǫ����޶��b���޳o���񪺦w���A�]���K�ݦ��L���ܥi�ê��H���A�q
�ߦb�A���e���O����������A�X�G���A���Q�������A��b�O�H�Q���z�O
�p��\�_���A����W�]���\�h���çL�b���ޡC
LONG
	);
	set("exits", ([
  "west" : __DIR__"beast4.c",
  "east" : __DIR__"bdoor1.c",
]));
	set("outdoors","land");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}