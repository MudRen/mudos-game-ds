// daxiaochang.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�j�ճ�");
        set("long", @LONG
�o�O�@�Ӧ��׫n�s�s�y����W�A�|�P�s�s����C�s�}�U���@�y
�j���C�C�~þ��A���u���K�󦹦a�|��j�աA�H�ҹ���U�̤l�b�o�@
�~�����i�ҡC���n�O�@���T�򪺤s�D�C����O�@���q���p�����s���C
���_��K�O�����c�C�u�����B�Q�l�l�D�[�Φt�������������B�s���C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"     : __DIR__"shijie1",
                "westup"      : __DIR__"shanlu13",
                "southdown"   : __DIR__"shanlu12",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/pi": 1,
        ]));

	set("coor/x", -3170);
	set("coor/y", 110);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}
