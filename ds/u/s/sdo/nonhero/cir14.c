inherit ROOM;

void create()
{
	set("short", "�}���j");
	set("long", @LONG
�@���i�o�̡A�N�ݨ�F�k���䦳�@�ڥ۬W�A�W����۴X�Ӥj�r�G
�y�[�ۦb���}���j  ť�p�N�W��U�~�z�C����W�l�᭱�A�ݨ��F�@��
����y�A���n�i�H�e�Ǥ@�ӤH�L�L���W�h�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"west" : __DIR__"cir13",
	]));
	set("current_light", 3);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
