inherit ROOM;

void create()
{
	set("short", "�L�۪k��");
	set("long", @LONG
�o�̤@�䪺��W�g�ۤj�j���y�ۡz�r�A�ӥt�@�䪺��W�g�ۡG�y
�Ĥ���Q�G�@���@�Ѯڧ����G�@�ڨӥ@�o�д��ɡA�Y�Ѧ����䨭�U�H
�A�Ѯڤ���A�୮�x�M�A��Ť�ڰסA���٭Iܼ�A�������g�A�غدf�W
�F�D�ڦW�w�A�@���ұo�ݥ��\�z�A�Ѯڧ���A�L�ѯe�W�C�z���䦳�@
�������A�̭��n�����@�L�J���C 
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
    		"west" : __DIR__"cir18",
  		"north" : __DIR__"cir13",
  		"southwest" : __DIR__"cir22",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
