// mishi.c �K��
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�K��");
        set("long", @LONG
�o�̬O���u�Ч̤l���F���F����׫ت��K�ǡA�o�̪����u�D�`
���t�A�]�\�w�g���B�a�U�F�C
LONG
        );
        set("exits", ([
                "up" : __DIR__"diziju",
                "eastup" : "/d/city/shilijie4",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2730);
	set("coor/y", 100);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}