
inherit ROOM;

void create()
{
	set("short", "�谼���Y�ਤ");
	set("long", @LONG
�A�ݨ쨫�Y�ਤ���a���\��ۤ@�ӬJ�j�S������~�A��~�W�m�V����
���D�`�����R�C��W���᪺�y���]�O��S��A���~�������y�g���~���W
�A�Ϯg�Xģ�������~�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room16",
	    "north": __DIR__"room18",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
