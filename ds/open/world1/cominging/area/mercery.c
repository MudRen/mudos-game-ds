inherit ROOM;
void create()
{
	set("short", "����");
	set("long",@LONG
�o�̬O�B�F�����̤j���c�����A���U���U�˪����A�ݤF�O�H���Ἲ
�áA�b�~�䦳�ܦh�b�D�塞�ƪ����H�A�]���\�h�s���������n���A�]��
�\�h�q���e�g�L�A�ӳQ�o�̪��F��ҧl�ު��H�A�o�̪����Ѯt�����A��
�n�]���a���A�q�´֨줣´�������C
LONG
	);
	set("exits", ([
  "west" : __DIR__"bnorth4.c",
]));
	set("objects", ([
  __DIR__"npc/mercer": 1,
]));
	set("no_clean_up", 0);
	set("light", 1);
	setup();
	replace_program(ROOM);
}