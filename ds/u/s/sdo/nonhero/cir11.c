inherit ROOM;

void create()
{
	set("short", "�L�۪k��");
	set("long", @LONG
�o�̤@�䪺��W�g�ۤj�j���y�ت̡z�G�r�A�ӥt�@�䪺��W�g��
�G�y�Ĥ���Q�G�@�Q�@�@�o�������G�@�ڨӥ@�o�����ɡA�Y�Ѧ����A
�ȴ��Ҵo�A���D���G�A�y�Ѵc�~�F�o�D�ڦW�A�M�������A�ڷ���H�W
�������A�����䨭�A��H�k���A�����w�֦ӫإߤ��C�z 
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"west" : __DIR__"cir10",
  		"south" : __DIR__"cir15",
  		"north" : __DIR__"cir5",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
