// /d/quanzhen/shanlu1.c �s��
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�s��");
        set("long", @LONG
�@���s���s�s�����a�q�V�s�W�C�_�����s�W�n�����@���f��L�A
��L�������S�X�F�l���@���A�n���N�O�W�s�����C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northeast" : __DIR__"shanlu2",
                "southeast" : __DIR__"shanlu3",
                "westdown"  : "/d/hanzhong/shanlu",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3150);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
