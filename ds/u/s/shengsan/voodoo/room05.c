inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�o�̬O�@�Ӭ۷�j���s���A�s�����|�P�٬O�˪L�����ۡA���O�o��
�i�Hť�즳�H�b�m�ߪZ�����n���A���n����թM���l�A���A������L�̦�
�һ����C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	    "east" : __DIR__"room04",
            "west" : __DIR__"room07",
	    "north": __DIR__"room06",
            ]));

        set("objects", ([ /* sizeof() == 1 */
            __DIR__"mob/snake" : 2,
            ]));
	set("no_clean_up", 0);
	set("outdoors",1);
	setup();
	replace_program(ROOM);
}
