// Room: /u/s/suez/tsing-yu/map_8_5.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
    �@�Ӥp�p���x�l�A�X�Ӧ~�����Ĥl�A�b�o�̦ۼu�۰۪��t�ۤ����W��
���C�S�����۪��r���n�A�]�S�����R���A�ˡA�ѯ��M�d�g�O�L���y�W����
�A�A�a�`�����S�Y�ˬ�O�L�̤�W���D��A�j�H�̦h�b���Ӥ��������L�A
�u���~���󻴪��p�ĩM�@���a�ۤp���������O���̪��[���A�b�o�s�����@
���A�L�̤��M���x�ۦ����A�b�o�R�x�W�ԭz�ۥL�̪��ܻy�A���׬O�_���H
�Y��A���H���d�C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 6 */
  "southwest" : __DIR__"map_9_4",
  "north" : __DIR__"map_7_5",
  "east" : __DIR__"map_8_6",
  "northeast" : __DIR__"map_7_6",
]));

	setup();
	replace_program(ROOM);
}
