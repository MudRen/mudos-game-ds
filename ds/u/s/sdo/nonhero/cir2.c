inherit ROOM;

void create()
{
	set("short", "�L�۪k��");
	set("long", @LONG
�o�̤@�䪺��W�g�ۤj�j���y�L�z�r�A�ӥt�@�䪺��W�g�ۡG�y
�Ĥ���Q�G�@�@�@�ͦ򥭵��G�@�ڨӥ@�o�����hù�T�д��ɡA�ۨ���
���A�K�M��ģ�L�q�L�ƥ@�ɡA�H�T�Q�G�j�V�ҬۡA�K�Q�H�Φn�A���Y
�䨭�F�O�@�������A�p�ڵL���C�z
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"southwest" : __DIR__"cir5",
  		"east" : __DIR__"cir3",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
