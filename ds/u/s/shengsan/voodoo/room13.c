
inherit ROOM;

void create()
{
	set("short", "�F�����Y");
	set("long", @LONG
��ǬO����⪺����A�����q���W������M�g�i�ǷL�����~�A�Ӧb��
���Ǫ��֮��~��ģ���C�A�D��F�@�ǭ��Q�Q�������C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"room12",
	    "north" : __DIR__"room14",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
