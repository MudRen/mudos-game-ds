// /d/quanzhen/shanlu7.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�s���p�|");
        set("long", @LONG
�o�O�@�����׫n�s�}�A�A���H�����p�|�C�|�P�j��ѤѡA��L
�a�A�A�M�a�s��A�K�Y�ڳ��۩M�����C���n�i�ݨ�@���p�e�C���F
�i�q���s�L�`�B�C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "east"  : __DIR__"shanlu6",
                "south" : __DIR__"xiaohebian",
        ]));

	set("coor/x", -3160);
	set("coor/y", 10);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
