inherit ROOM;

void create()
{
	set("short", "�L�۪k��");
	set("long", @LONG
�o�̤@�䪺��W�g�ۤj�j���y�H�z�r�A�ӥt�@�䪺��W�g�ۡG�y
�Ĥ���Q�G�@���@�٦�M�R�G�@�ڨӥ@�o�д��ɡA�Y���L�q�L�䦳��
�A��ڪk���צ���A�@���ҥO�o���ʧ١A��T�E�١F�]�����ǡA�D
�ڦW�w�A�ٱo�M�R�A���Z�c��C�z 
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"south" : __DIR__"cir19",
  		"north" : __DIR__"cir9",
  		"east" : __DIR__"cir14",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
