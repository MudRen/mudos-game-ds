// juyan.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�ѹᩥ");
        set("long", @LONG
�@���L�ӡA�s���O�V�ӶV�I�C�u���@���j���۾צb�����A�۪ž�
�{�A�{���@�ӦѰ��s�y�����A���Ϊ����˥i�ơA�O�H��ӥͬȡC����
�C�Ȧb���n���[�ݡA���n�O�@���Z�K���P�L�C���_�W�O�@���~�k���s
���C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"    : __DIR__"shanlu12",
                "southdown"  : __DIR__"shulin3",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/ji": 1,
        ]));

	set("coor/x", -3170);
	set("coor/y", 90);
	set("coor/z", 100);
	setup();
        replace_program(ROOM);
}
