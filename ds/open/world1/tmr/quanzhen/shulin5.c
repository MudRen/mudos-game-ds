// /d/quanzhen/shulin5.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��L");
        set("long", @LONG
�o���׫n�s�����@�j����L�A�ͪ��ᬰ�Z�K�C���b�䶡�A�uť
�o�}�U�F�F�������n�A�|�P�����t�t���A���ɴX�D�����L�@�K���K
�Y�A��g�ӤU�C�������B�X�n�~�q�n�A��K�F�@�������P�C���_�B�n
�U���@���p�|�C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "south"     : __DIR__"shulin4",
                "northdown" : __DIR__"shulin6",
        ]));
	set("coor/x", -3190);
	set("coor/y", 150);
	set("coor/z", 110);
	setup();
        replace_program(ROOM);
}
