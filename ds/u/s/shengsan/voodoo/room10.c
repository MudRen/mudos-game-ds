
inherit ROOM;

void create()
{
	set("short", "�Ŭr�Х���");
	set("long", @LONG
���د������Pı�V�Aŧ�ӡA�޲�����^�R���b��өж��̡C�A�ݨ쥪
�k�U�@�����Y�A�ӫe��O�Ŭr�Ф����e�U�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room11",
	    "west" : __DIR__"room16",
	    "north": __DIR__"room22",
	    "down" : __DIR__"room09",
            ]));

	set("objects", ([ /* sizeof() == 1 */
            __DIR__"mob/student" : 3,
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
