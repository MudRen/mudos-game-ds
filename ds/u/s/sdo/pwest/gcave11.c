inherit ROOM;

void create()
{
	set("short", "�}�]��");
	set("long", @LONG
�A����o�̡A���Mı�o�򰩮��M�C�]���a�W���M���õۤ@�a����
���A�����٦�����M�a���b�[�l�W����l�C�ӯu���O�H�`�Ȫ��O�A�a
�W�������հ��̳��M���H�����Y���I
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  		"southeast" : __DIR__"gcave13",
  		"east" : __DIR__"gcave10",
  		"northeast" : __DIR__"gcave9",
	]));

	setup();
	replace_program(ROOM);
}
