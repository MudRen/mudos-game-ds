inherit ROOM;

void create()
{
	set("short", "�L�۪k��");
	set("long", @LONG
�o�̤@�䪺��W�g�ۤj�j���y�ۡz�r�A�ӥt�@�䪺��W�g�ۡG�y
�Ĥ���Q�G�@�T�@��͵L�ɡG�@�ڨӥ@�o�д��ɡA�H�L�q�L�䴼�z��
�K�A�O�Ѳ��ͬұo�L�ɩҨ��Ϊ��A���O���ͦ��ҥF�֡C�z
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"west" : __DIR__"cir3",
  		"southeast" : __DIR__"cir9",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
