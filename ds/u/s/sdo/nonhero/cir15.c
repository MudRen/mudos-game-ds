inherit ROOM;

void create()
{
	set("short", "�L�۪k��");
	set("long", @LONG
�o�̤@�䪺��W�g�ۤj�j���y�L�z�r�A�ӥt�@�䪺��W�g�ۡG�y
�Ĥ���Q�G�@�Q�@�D���Ѳ�G�@�ڨӥ@�o�д��ɡA�Y�Ѧ����A���k��
���A÷���@�ءAô���c���A�η�D���A�ξl�L�q�a����d�A�d�T�ιG
�A���ߨ��W�F�Y�D�ڦW�A�H�ںּw�¯��O�G�A�ұo�Ѳ�@���~�W�C�z
�F�䦳�@�������A�̭��n�����@�L�J���C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"north" : __DIR__"cir11",
  		"southeast" : __DIR__"cir20",
  		"east" : __DIR__"cir16",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
