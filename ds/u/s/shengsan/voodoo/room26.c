
inherit ROOM;

void create()
{
	set("short", "�e�U");
	set("long", @LONG
�b�A�譱����W���\�h�ʪ��Ω��μХ��A�o�ǼХ������@�Ӧ@�q���S
�ʡA���N�O���۷��r�ʡA�٦n�e�̳��w�g���F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room25",
	    "south": __DIR__"room27",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
