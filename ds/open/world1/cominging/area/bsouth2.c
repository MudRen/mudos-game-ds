inherit ROOM;
void create()
{
	set("short", "�B�F���n�j��");
	set("long",@LONG
�o��O�n�j�󪺤������x���ϡA�b�o���񦳳\�h�H�۩M�\�h�ʪ���
�ƪn���A�O�H���T�Q�n�������}�o�̡A�b�j�󪺮��䦳�@�a�ު١A���
�j���N�O�q���ǥX�Ӫ��a�A�b�_��O�B�F���n�j�󪺥_��A���\�h���a
�Ӧb���n�@�I�N�O�n�j�󪺫n�䳡���C
LONG
	);
	set("exits", ([
  "north" : __DIR__"bsouth1.c",
  "south" : __DIR__"bsouth3.c",
]));
	set("objects",([
  __DIR__"npc/traveller.c": 2,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
