inherit ROOM;
void create()
{
	set("short", "´����");
	set("long",@LONG
�o�̬O�@�a´�����A�o�a´�������D�H�ܦ~���Ať���j���G�Q�ӷ�
���k�A���L�����o��H���n�A�O�H���T¼�_�j������g�@�f�A�b�Τ���
���c���w�H�ΦU�ؽ�ƪ��u�A�F��O�쩹�_��C
LONG
	);
	set("exits", ([
  "east" : __DIR__"bnorth4.c",
]));
	set("objects",([
  __DIR__"npc/spinner.c":1,
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}