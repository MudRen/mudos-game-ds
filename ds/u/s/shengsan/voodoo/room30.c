
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�o�̬O�Ŭr�Ъ���|�����A�A�ݨ즳�\�h������ئb�o�̡A��
���B�e�����R�b�䤤�A�J�Ӥ@�ݡA�A�~�o�{�o�Ǫ�󳣬O�A���`�S���L��
�A���D�o�ǴӪ������r�ܡH
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room31",
	    "west" : __DIR__"room21",
	    "north": __DIR__"room32",
            ]));

	set("objects", ([ /* sizeof() == 2 */
            __DIR__"mob/student" : 3,
	    __DIR__"mob/believer": 2,
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
