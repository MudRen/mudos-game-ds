// Room: /open/world1/tmr/dragoncity/house4w.c

inherit ROOM;

void create()
{
	set("short", "�֫ө��Юѩ�");
	set("long", @LONG
�o�O�F�򪺮ѩСC�k��O�Ѭ[�A�W�����C�۹D�a�M���a���@�Ǩ��y�A
�o�S���@���P�Z�Ǧ������ѡC����a�����a���\�ۤ@�i���A�W����۵�
���ȵx�A��W��۴X���ѡA�\��o�������A�g���o�@�Ф��V�A�ո̨�B
�Q�����o�@�Ф��V�A�����X�b�A�i�H�ݨ�~���P�˱��M�A�ɦ��L���J��A
�����W�ٿU�ۤ@�l�ȭ��A�r�r�����𻴻���A�ϤH�U���ɮ��A�߱���
�����R�U�ӡC
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"house4",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
