inherit ROOM;

void create()
{
	set("short", "�L�۪k��");
	set("long", @LONG
�o�̤@�䪺��W�g�ۤj�j���y�ڡz�r�A�ӥt�@�䪺��W�g�ۡG�y
�Ĥ���Q�G�@�G�@�}��Ʒ~�G�@�ڨӥ@�o�д��ɡA���p�[���A���~��
���A�b�L��©�A�����s�j�A�\�w���ޡA�������Y�A�L����F�խ߲�
�͡A�x�X�}��A�H�N�ҽ�A�@�ѨƷ~�C�z
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"west" : __DIR__"cir2",
  		"south" : __DIR__"cir7",
  		"east" : __DIR__"cir4",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
