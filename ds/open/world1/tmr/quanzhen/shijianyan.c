// shijianyan.c �ռC��
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�ռC��");
        set("long", @LONG
�۶��ǥߵۤ@���j���ۡA�W��������骺�ɬO��ˡC�o���j��
�۫K�O���u�Ъ��ռC���A�ѤU���^���Ө�o�̡A��ۥ����̽m�C��
�b���ۤW���岪�A�L���µM�_�q�C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northdown" : __DIR__"shijie4",
                "southup" : __DIR__"shijie8",
                "east" : __DIR__"jiaobei",
        ]));
        set("objects",([
                CLASS_D("quanzhen")+"/yin" : 1,
                __DIR__"npc/daotong" : 2,
        ]));

	set("coor/x", -3150);
	set("coor/y", 110);
	set("coor/z", 160);
	setup();
        replace_program(ROOM);
}