// /d/quanzhen/shulin1.c ��L
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��L");
        set("long", @LONG
�o���׫n�s�����@�j����L�A�ͱo�ᬰ�Z�K�C���b�䶡�A�uť
�o�}�U�F�F�������n�A�|�P�����t�t���A���ɴX�D�����L�@�K���K
�Y�A��g�ӤU�C�������B�X�n�~�q�n�A��K�F�@�������P�C���_�M��
�n�U���@���p�|�C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "north"      : __DIR__"baoziyan",
                "southdown"  : __DIR__"shanlu9",
        ]));

	set("coor/x", -3150);
	set("coor/y", 50);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}
