// Room: /d/xiangyang/guofushufang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ѩ�");
	set("long", @LONG
�o�O���t���ѩСC�k��O�Ѭ[�A�W�����C�۹D�a�M���a��
�@�Ǩ��y�A�o�S���@���P�Z�Ǧ������ѡC����a�����a���\��
�@�i���A�W����۵����ȵx�A��W��۴X���ѡA�\��o���
�����A�g���o�@�Ф��V�A�ո̨�B�Q�����o�@�Ф��V�A�����X
�b�A�i�H�ݨ�~���P�˱��M�A�ɦ��L���J��A�����W�ٿU��
�@�l�ȭ��A�r�r�����𻴻���A�ϤH�U���ɮ��A�߱�������
�R�U�ӡC
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"guofuhuayuan",
	]));
	set("coor/x", -520);
	set("coor/y", -450);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}