
inherit ROOM;

void create()
{
	set("short", "�e�U");
	set("long", @LONG
�A�ݨ��l�Ȥl���ƦC����A���W���\�h�Х��A�J�Ӥ@�ݤ~���D���O
���r�ʪ��ʪ��Ω��ΡC�a�W�Q���Ƥj���⪺�a��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room22",
	    "north": __DIR__"room24",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
