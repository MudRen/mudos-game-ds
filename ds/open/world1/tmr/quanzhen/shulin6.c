// /d/quanzhen/shulin6.c
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
                "southup"   : __DIR__"shulin5",
                "northdown" : __DIR__"shandao3",
        ]));
        set("objects", ([
                "/d/wudang/npc/monkey" : 1,
        ]));
	set("coor/x", -3190);
	set("coor/y", 160);
	set("coor/z", 100);
	setup();
        replace_program(ROOM);
}
