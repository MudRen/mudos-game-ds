// Room: /u/l/lestia/area/sn15.c

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
  "east" : __DIR__"sn16",
  "west" : __DIR__"sn14",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
