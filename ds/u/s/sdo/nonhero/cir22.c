inherit ROOM;

void create()
{
	set("short", "�L�۪k��");
	set("long", @LONG
�o�̤@�䪺��W�g�ۤj�j���y�L�z�r�A�ӥt�@�䪺��W�g�ۡG�y
�Ĥ���Q�G�@�C�@���߱d�֡G�@�ڨӥ@�o�д��ɡA�Y�Ѧ������f�G��
�A�L�ϵL�k�A�L��L�ġA�L�˵L�a�A�h�a�h�W�A�ڤ��W���@�g��աA
���f�x���A���ߦw�֡F�a�ݸ��A�x���ר��A�D���ұo�L�W�д��C�z 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"west" : __DIR__"cir21",
  		"northeast" : __DIR__"cir19",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
