inherit ROOM;
void create()
{
	set("short", "�M�����E");
	set("long",@LONG
�o�O�B�F�����@�a���Ӧ��W���p���E�A���L�b�o�̫o�³����p�A��
Ŧ�ѥ��A�u�n�A�Q�o�X�Ӫ����ĳ��R�o��A�b�n��O�B�F��������j��
�A�b�~�Y�٦��ǳ\���ȤH�e���o�̡A�E�̪����E�ѪO��������֥G�A�n
�������ܧּ֡A�j���O�]���ӶR���H��M�ܦh�A�]���G���ۤ@�������~
�T���ˤl�C
LONG
	);
	set("exits", ([
  "south" : __DIR__"bwest1.c",
]));
	set("objects",([
  __DIR__"npc/herbalist.c": 1,
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}