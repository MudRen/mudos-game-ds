#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","�ӷ~�j�D");
        set("long",@LONG
�q��ǩ��n�_������������H�ۮ����n�̵ۡA��b����D�O��ǰӮa
�C��V�O�����G�A���M���o�̧����O�ӷ~���@�ɡA���O�ѩ󤣷Q�Q�����u
�R�ȿ����u�]���A�Ӯa���ܧV�O�N�o�̾�z���ξA���[�A�]���T���e�ӶR
�檺�H�Pı�n�ܦh�C���L���ê��Ǹo�M��a�H���������M���Ӯa�Q���Y�h
�C
LONG 
);
        set("exits",([
            "north":__DIR__"port_23",
           // "south":__DIR__"port_34",
            "east":__DIR__"port_26"
                ]));

        set("world","world1");
        set("outdoor","land");

        setup();

}
int valid_leave(object me, string dir)
{
       if( dir=="east" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}

