inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�A�@���i�o�����СA�N�o�{�o�����и�O�����ܤj�����P�A���N
�O����|�P���O���d�A���d�W���������O�ѥ��A�ƶq���h�A²���i�H
�B���p����Ū���]�C�������@�i�j��l�A��l�W���\�h�Q���}���ѹs
�ê��u�b���A�i���D�H�D�`���ԩ�\Ū�C�A�S�J�Ӫ��ݬݤF���d�W��
�ѡA�o�{�������@�몺�q�λy���A�٦����]�k�y���g�����}���]�k��
�M�X���A�ڥ��ݤ����o��r�g�������y�C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  		"west" : __DIR__"burg2",
	]));
	set("objects",([
		__DIR__"npc/jialermi.c":1,
	]));

	setup();
	replace_program(ROOM);
}
