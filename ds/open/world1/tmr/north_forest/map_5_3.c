// Room: /u/l/lestia/area/map_5_3.c

inherit ROOM;

void create()
{
	set("short", "�F�۩v����-�[��");
	set("long", @LONG
�o�̬O�F�۱бM���Ψө۫ݶQ�����[�СA�̭����\�]�ն���U�A����M
�o�O���M�����H�]�p���A���H�@���i�h�N�i�H�P��@�ѷŷx���Pı�A���Ҧ�
�Ө�o�̪��Q������P���컫�ܦp�k���ݹJ�A��W���۳\�\�h�h�X�ۦW�a��
�⪺�ֵ��峹�M�e�@�C
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"map_5_2",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
