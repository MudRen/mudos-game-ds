// Room: /u/t/truewind/Minetown/area/sewer1.c

inherit ROOM;

void create()
{
	set("short", "�U���D");
	set("long", @LONG
�A�Ө�@�ӳ��t���㪺�U���D�A�Ů�̦��@�ػ����X�Ӫ����D�A
���A�ܷQ���W���}�C���������ѹ��]�Ӷ]�h�A�A�s�y�U�ӥJ�Ӫ���
�F�@�U�A�`�N��o�̪��ͪ����G�������I�_��...??
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"machinefield5",
]));
	set("current_light", 0);

	setup();
}
