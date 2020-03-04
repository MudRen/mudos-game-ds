inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�s�����|�P�����C�A���˪L�]��ۡA�s���a�O���ۧ����O�۷��n�C
�]�\�o�̴N�O�Ю{�`�`�ӽm�\���a��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "east" : __DIR__"room05",
            "north": __DIR__"room08",
            ]));

	set("objects", ([ /* sizeof() == 2 */
            __DIR__"mob/master" : 1,
	    __DIR__"mob/disciple" : 2,
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);

	setup();
	replace_program(ROOM);
}
