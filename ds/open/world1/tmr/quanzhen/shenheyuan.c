// shenheyuan.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "���ݭ�");
        set("long", @LONG
���B���׫n�s�������A�ؤs����C�񲴱�h�A�u���@���Z���L
�����j����A���b�s�s�����C�ǻ��Ӵ¥��~�A���l���v�L����𥴪�
�w�ɡA³��u�ʡA�b���򯫥ݦѺ~���U�A�o�̸U�ءA�]���R�W������
��C���F�n�M�_�W�U�O�@����L�C���n�O�@�B���C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "west"      : __DIR__"foyezhang",
                "north"     : __DIR__"shulin3",
                "southeast" : __DIR__"shulin2",
        ]));
        set("objects", ([
                "/d/hanzhong/npc/seller": 1,
        ]));

	set("coor/x", -3170);
	set("coor/y", 70);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}
