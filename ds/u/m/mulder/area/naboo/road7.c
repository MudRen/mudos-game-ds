inherit ROOM;

void create()
{
	set("short", "Naboo����D");
	set("long", @LONG
�Ať��o�̶ǥX�@�}�}�X�M���q�n�A�A�J�Ӥ@�椧�U�A�oı
���@��~�����q�k���b�o�̪�t�C�A���T����o����A�d�߲�ť
�o�����R�q�n�C���n�i�H�q���s�a�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road8",
  "west" : __DIR__"middle",
  "south" : __DIR__"bar",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
