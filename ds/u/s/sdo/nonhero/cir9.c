inherit ROOM;

void create()
{
	set("short", "�L�۪k��");
	set("long", @LONG
�o�̤@�䪺��W�g�ۤj�j���y�L�z�r�A�ӥt�@�䪺��W�g�ۡG�y
�Ĥ���Q�G�@�|�@�w�ߤj���G�@�ڨӥ@�o�д��ɡA�Y�Ѧ����樸�D��
�A�x�O�w����ĹD���F�Y���n�D�Wı���̡A�ҥH�j���Ӧw�ߤ��C�z��
�䦳�@�������A�̭��n�����@�L�J���C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"northwest" : __DIR__"cir4",
  		"west" : __DIR__"cir8",
  		"south" : __DIR__"cir13",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
