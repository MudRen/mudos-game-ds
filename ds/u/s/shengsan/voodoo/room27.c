
inherit ROOM;

void create()
{
	set("short", "�e�U");
	set("long", @LONG
�a�W���a��O�j���⪺�A�a�b���䪺�O�������Ȥ��d�l�A�`�`�|��
�H�ӳo������z�A�A�ݨ�譱����W���\�h���r�μХ��A���Z���ߪ��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room22",
	    "north": __DIR__"room26",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
