// laojundian.c �ѧg��
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ѧg��");
        set("long", @LONG
�o�̬O�ѩ^�ӤW�ѧg���j���C����������ۦѧg���칳�A�ѧg�M
�b�C���W�A���{���ӥh�C��Ƕ�ۨ�ӵ��l�A���ݮݦp�͡C�������a
���O�H�C�j�@�������Q���A�����o�@�Ф��V�C
LONG
        );
        set("exits", ([
                "east" : __DIR__"houtang1",
                "south" : __DIR__"tongtiandian",
                "north" : __DIR__"yuanshidian",
                "west" : __DIR__"datang3",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/qiu" : 1,
        ]));
	set("coor/x", -2770);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
}

int valid_leave(object me, string dir)
{
        mapping fam;

        if (dir == "east" )
        {
                if(!(fam = me->query("family")) || fam["family_name"] != "���u��") {
                        if(present("qiu chuji", environment(me)) && living(present("qiu chuji", environment(me))))
                        {
                                return notify_fail(
"�C�B���ܹD�G�᭱�O���Э��a�A�o��" + RANK_D->query_respect(me) + "�Ф�B�C\n");
                        }
                        else
                                return ::valid_leave(me, dir);
                }
                else
                        return ::valid_leave(me, dir);
        }
        else
                return ::valid_leave(me, dir);

}