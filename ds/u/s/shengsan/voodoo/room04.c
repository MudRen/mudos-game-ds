inherit ROOM;

void create()
{
	set("short", "�˪L�B�D");
	set("long", @LONG
���F�˸��n���~�A�A��ť�촵�����n���A�n���O�L�����D���A�G��F
�A�A���ѦۥD������ĵı�ߡA�H���I�H�ɬ�Ӫ����p�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "east" : __DIR__"room03",
            "west" : __DIR__"room05",
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);
	setup();
	replace_program(ROOM);
}
