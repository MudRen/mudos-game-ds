// Room: /u/s/suez/tsing-yu/map_8_7.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
    �o�̪��۪O���W�g���F�d�g�A�X�Ӭ��²�����p�ĥ��b�@�Ǫ�����^
���A�@��񽮻\�Ѫ��Ѻ_���R�R�����X�F�ʧ����K�֡A��L�F�j�Ѫ��j��
������j��W�ӡA�ŬX���N�H�̾֩�A�����ߪ��h�γ��H�۾�U���L���j
���A�X�ӦѤH�a�ۤ@�����A�N�b�o���\�F�ӴѮ�A�@�l�@�l���U�ۤ�����
�ɤ~�|�U�����ѡA�ѽL�W�����_���I�A�b�ѧ����h�H��A�ѤU���u������
�ɶ��᪺���D�M�Ƹ��b�Ѯ�W���_�𸭦Ӥw�C


LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 6 */
  "north" : __DIR__"map_7_7",
  "northwest" : __DIR__"map_7_6",
  "southeast" : __DIR__"map_9_8",
  "west" : __DIR__"map_8_6",
]));

	setup();
	replace_program(ROOM);
}
