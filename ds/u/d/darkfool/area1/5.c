// Room: /u/d/darkfool/area1/5.c

inherit ROOM;

void create()
{
	set("short", "�q�u�Y�s�a");
	set("long", @LONG
�o�̬O�@���s�a�A����̶��v�ɳ����w��o�̳ܰs�ͤѡA���D��
�G�]�O�Ӧ��I�ǩ_�ʪ��H���A�p�G�A��L��t���ܩγ\�L�|���X�Ӻ�
�����G�Ƶ��Ať�]�����@�w�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"3",
]));

	setup();
	replace_program(ROOM);
}
