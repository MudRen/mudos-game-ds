inherit ROOM;

void create()
{
	set("short", "��}��");
	set("long", @LONG
�G���i�J��}���A�o�{�o�̪��Ŷ����j�󤧫e���Q���C�o�̭��i
�H���O�@���p��Ϊ��j�p�F�A�ӥB�ݬݩP��A�n���O�S�a�M�X�Ӫ���
���C�b�����٦��@�����ýs������l�A�ݨӥi�H�b���W���C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"tree",
  "up" : __DIR__"tree2f",
]));

	setup();
	replace_program(ROOM);
}
