#include <ansi.h>
#include <path.h>

inherit ROOM;

void create()
{
 set("short", "���ЦQ�������B");
 set("long", @LONG

(����CCKK,RICHAN���Ѹ�Ƥ�)

LONG
        );
        set("outdoors","land");
        set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "south" : "/open/world1/tmr/bagi/rift",
 ]));
 set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="south" && !objectp(present("ming plate",me)) && me->query("club/name")!="����" )
{
        return notify_fail("�A���O���Ъ������A����i�J�o�M�ݥL�̪��a��C\n");
        return ::valid_leave(me, dir);
}
        if( dir=="south" && me->query_temp("killer") )
{
        return notify_fail("�ѤW�ǨӤ@�ӫիժ��n��: $N, �]���A�����F�H�ҥH�Ȯɤ���i�J�Ф��C\n");
        return ::valid_leave(me, dir);
}
        if( dir=="south" && me->query_temp("invader") )
{
        return notify_fail("�ѤW�ǨӤ@�ӫիժ��n��: $N, �]���A�������L�d���a, �ҥH�Ȯɤ���i�J�Ф��C\n");
        return ::valid_leave(me, dir);
}
}

