
inherit ROOM;

void create()
{
	set("short", "�F�����Y");
	set("long", @LONG
�A�ݨ��Ǫ��������W�����t����ơA�u�ۨ��Y���ⰼ�A�C�j�@
�q�Z���N���@�Ӭ֮��ۡA�b�o�i�X���H�ä��|�ܦh�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room12",
	    "west" : __DIR__"room10",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
