inherit ROOM;

void create()
{
	set("short", "�}�]���e��");
	set("long", @LONG
�A�ݨ�e�褣���B�n�����L�z�����u�z�g�X�A���O�]����b�O��
�L�z�F�A�ҥH��b�O�S������ө����ĪG�C���L�J�M�����u�A���N�O
�N��o�Ӭ}�]�O���Y�ذ������z���ͪ��b�~���C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"gcave6",
  "south" : __DIR__"gcave3",
]));

	setup();
	replace_program(ROOM);
}
