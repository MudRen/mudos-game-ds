// /d/quanzhen/baoziyan.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��l��");
        set("long", @LONG
�@���L�ӡA�s���O�V�ӶV�I�C�u�����r�r���s���A���ǺɬO�ǥۡA
�ӥk�h�O�U�V�`�W�A���������C�e�褣���B���@�����ۡA�K�O���W��
��l���C�A�ݴX���Aı�����ͱo�ƬO�_�ǡA�N�p�@�Ӱ��H��ۭӫĤl
��A�Ӥߨ��@�C���n�M��U�O�@���K�L�C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "west"      : __DIR__"shulin2",
                "south"     : __DIR__"shulin1",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/chen": 1,
        ]));

	set("coor/x", -3150);
	set("coor/y", 60);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}
