
inherit ROOM;

void create()
{
	set("short", "���Y");
	set("long", @LONG
�o�O�q���Ŭr�боª����Y�A���ɨӳo�����O�ӽ������F
���A�o�����Y��ǺؤF�ǩ_�_�ǩǪ��Ӫ��A�]���B���B�B���γ��A
����γ�����W�J�u���ΡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room34",
	    "west" : __DIR__"room37",
	    "north": __DIR__"room38",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
