inherit ROOM;

void create()
{
	set("short", "�}�]���e��");
	set("long", @LONG
�o�̬۸���}�f���G�e��F�I�A���L�j���O�]��������̭����a
��F�A�ҥH�Pı�î�}�l�K���A�Ů𤤨��ѿ@�B�����D�]�ܪ��V�ӶV
����C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  		"northeast" : __DIR__"gcave6",
  		"south" : __DIR__"gcave2",
	]));

	setup();
	replace_program(ROOM);
}
