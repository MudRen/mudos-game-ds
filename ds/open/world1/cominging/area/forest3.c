inherit ROOM;
void create()
{
	set("short", "�˪L�~��");
	set("long",@LONG
�A���������i�F�o���˪L�������p�ϰ�Pı��o�̪Ů𪺷s�A�A�b
��W���@�ǳD����¶�A���G�٦�����D���ˤl�A�b�A���}�U���@���H
�ͦb��F�W����ۣ�A���L�ݰ_���A�v�A�]�\�O�@�ؼ@�r�]���@�w�C
LONG
	);
	set("exits", ([
  "south" : __DIR__"forest4.c",
  "north" : __DIR__"forest2.c",
]));
	set("outdoors","forest");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
