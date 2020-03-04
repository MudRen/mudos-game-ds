// Room: /u/l/lestia/area/sn16.c

inherit ROOM;

void create()
{
	set("short", "�_��j�˪L-�p�|");
	set("long", @LONG

�@�ιΪ������V�A�ﭱ�ӨӡA�A�ϩ������b�g�������A�C�Y���U�ݤ���
�ۤv���}�A���Y�V�W�ݤ���ѪŤW���ն��A�A���G�w�g�M�~�����@�ɲ����F
�A�u�I�g�b�o��������������A�����ұ����è��ü��A�Q���X�o�����A�`
�Ȫ��a��C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"sn17",
  "west" : __DIR__"sn15",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
