// /d/quanzhen/shanlu6.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�s���p�|");
        set("long", @LONG
�o�O�@�����׫n�s�}�A�A���H�����p�|�C�|�P�j��ѤѡA��L
�a�A�A�M�a�s��A�K�Y�ڳ��۩M�����C����M�F�n�i�q���s�L�`�B�C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southeast" : __DIR__"shanlu5",
                "west"      : __DIR__"shanlu7",
        ]));

	set("coor/x", -3150);
	set("coor/y", 10);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
