inherit ROOM;

void create()
{
	set("short", "�}�]���q�D");
	set("long", @LONG
�o�̪��a�դS�k�󥭩Z�A�ӥB�ܩ��㪺�e���������G�������A�]
���b�o�̥i�H�ݨ����u�Ӧb����W�@�b�G�@�b�t�����p�C�ӥB�a�U�e
���ҳy�������y�n�ܪ����I�T�A�ٱa���I�^���C�ݨӡA�e���O�@�ӻ�
�j���Ŷ��C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"gcave9",
  "east" : __DIR__"gcave7",
]));

	setup();
	replace_program(ROOM);
}
