// /d/quanzhen/shulin4.c
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
                "southup"   : __DIR__"shandao2",
                "north"     : __DIR__"shulin5",
        ]));
        set("objects", ([
                "/d/wudang/npc/bee" : 1,
        ]));
	set("coor/x", -3190);
	set("coor/y", 140);
	set("coor/z", 110);
	setup();
        replace_program(ROOM);
}
