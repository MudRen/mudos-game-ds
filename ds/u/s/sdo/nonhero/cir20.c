inherit ROOM;

void create()
{
	set("short", "�L�۪k��");
	set("long", @LONG
�o�̤@�䪺��W�g�ۤj�j���y�ۡz�r�A�ӥt�@�䪺��W�g�ۡG�y
�Ĥ���Q�G�@�E�@�^���k���G�@�ڨӥ@�o�д��ɡA�O�Ѧ����X�]����
�A�Ѳ�@���~���񿣡F�Y�Z�غشc���Y�L�A�Ҭ�����m�󥿨��A���O
�ײ߽ѵ��Ħ�A�t�ҵL�W�����д��C�z 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"northwest" : __DIR__"cir15",
  		"east" : __DIR__"cir21",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
