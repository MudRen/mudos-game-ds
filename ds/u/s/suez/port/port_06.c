#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","���ߵ�");
        set("long",@LONG
�q�ĺ��Ĵ��䩹�_���o�Ӧa��A���X������𬣪��Фl�A�O�ĺ��Ĵ�
�H�̭�������a��̩~���a��A�]�]���o�줤�ߵ󪺦W�١A���M��ڤW
�o�̦���ĺ��Ĵ����̥_��C�F��h�O�ĺ��Ĵ��W�q�W����F���ߡC
LONG 
);
        set("exits",([
            "east":__DIR__"port_09",
            "west":__DIR__"port_03",
            "south":__DIR__"port_07",
                ]));
        set("objects",([
             __DIR__"npc/business_wm":1,
            __DIR__"npc/business_mn":1,
                ]));

        set("world","world1");
        set("outdoor","land");

        setup();

}
int valid_leave(object me, string dir)
{
       if( (dir=="west" || dir=="east" )&& !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}


