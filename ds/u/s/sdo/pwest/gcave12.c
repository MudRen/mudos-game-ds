inherit ROOM;

void create()
{
	set("short", "�}�]��");
	set("long", @LONG
�o�̪�����M�a�W�A�Q���R��L�������b�����٨Ӫ�����A��
�ӳo�Ӭ}�]�H�e�G�M�O�a�U�e�D���@�����A�u�O�{�b�e������j���h
���U���h�F�a�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"gcave13",
  "northwest" : __DIR__"gcave9",
  "west" : __DIR__"gcave10",
]));

	setup();
	replace_program(ROOM);
}
