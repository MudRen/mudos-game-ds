// /d/quanzhen/shanlu5.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�s���p�|");
        set("long", @LONG
�o�O�@�����׫n�s�}�A�A���H�����p�|�C�|�P�j��ѤѡA��L
�a�A�A�M�a�s��A�K�Y�ڳ��۩M�����C���F�i�ݨ�@���D���C����_
�i�q���s�L�`�B�C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "east"      : __DIR__"shanlu4",
                "northwest" : __DIR__"shanlu6",
        ]));

	set("no_clean_up", 0);
	set("coor/x", -3140);
	set("coor/y", 0);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
