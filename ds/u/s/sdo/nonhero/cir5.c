inherit ROOM;

void create()
{
	set("short", "�L�۪k��");
	set("long", @LONG
�o�̤@�䪺��W�g�ۤj�j���y�ۡz�r�A�ӥt�@�䪺��W�g�ۡG�y
�Ĥ���Q�G�@�Q�G�@�o�����G�@�ڨӥ@�o�д��ɡA�Y�Ѧ����h�L��
���A�A�δH���A�ީ]�G�o�F�Y�D�ڦW�A�M�������A�p��Ҧn�A�Y�o��
�ؤW����A�A��o�@���_���Y��A������A���ֲ�ɫ�H�C�z�F�䦳
�@�������A�̭��n�����@�L�J���C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"south" : __DIR__"cir11",
  		"northeast" : __DIR__"cir2",
  		"east" : __DIR__"cir6",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
