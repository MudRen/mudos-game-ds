inherit ROOM;

void create()
{
	set("short", "���Ū���F��");
	set("long", @LONG
���b�o�̡A�A�Pı��F�@�ѯ��t�Ӳ��Y����^�b�o������¶�ۡA
�o�ѷPı�N�O�A�b�˪L�����Pı�쪺���ѯ����O�q�A���O�o�̱j�h�F
�A�ݨӤO�q�����Y�N�b�o�ʯ���̡C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  		"up" : __DIR__"tree3f",
  		"down" : __DIR__"tree1f",
	]));

	setup();
	replace_program(ROOM);
}
