// /d/quanzhen/shulin2.c ��L
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��L");
        set("long", @LONG
�o���׫n�s�����@�j����L�A�ͱo�ᬰ�Z�K�C���b�䶡�A�uť
�o�}�U�F�F�������n�A�|�P�����t�t���A���ɴX�D�����L�@�K���K
�Y�A��g�ӤU�C�������B�X�n�~�q�n�A��K�F�@�������P�C����_�M
���F�U���@���p�|�C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northwest"  : __DIR__"shenheyuan",
                "east"       : __DIR__"baoziyan",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/deer": 1,
        ]));
	set("coor/x", -3160);
	set("coor/y", 60);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}
