inherit ROOM;

void create()
{
	set("short", "�L�۪k��");
	set("long", @LONG
�o�̤@�䪺��W�g�ۤj�j���y���͡z�G�r�A�ӥt�@�䪺��W�g��
�G�y�Ĥ���Q�G�@�K�@��k���k�G�@�ڨӥ@�o�д��ɡA�Y���k�H���k
�ʴc���ҹG�o�A���͹����A�@�ˤk���F�D�ڦW�w�A�@���ұo��k���k
�A��V�ҬۡA�D���ұo�L�W�д��C�z 
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
    		"west" : __DIR__"cir20",
  		"north" : __DIR__"cir17",
  		"east" : __DIR__"cir22",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
