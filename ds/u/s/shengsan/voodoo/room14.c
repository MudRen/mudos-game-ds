
inherit ROOM;

void create()
{
	set("short", "�Ŭr�мp��");
	set("long", @LONG
�@�}�@�@�������ֳt���V�A����ӨӡA�o�̬O�Ŭr�Ъ��p�СA���ܦh
���p��ά����i�f�������N�b�A���e�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"room13",
	    "north" : __DIR__"room15",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
