
inherit ROOM;

void create()
{
	set("short", "�谼���Y");
	set("long", @LONG
�o�O�F�����Y�A�A�ݨ�_�䦳�@�Ӧ�H���ж��A�ӪF��O�@�y���A
�p�G�����䪺���Y���h�i�H��Ŭr�Ъ��e�U�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room30",
	    "west" : __DIR__"room20",
	    "north": __DIR__"room29",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
