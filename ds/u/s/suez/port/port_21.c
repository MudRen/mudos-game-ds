#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","�שԤj�D");
        set("long",@LONG
�@���������j���q�o�̩��F��V�����X�h�A�o�̴N�O�j�ӤH�שԩҫ�
�y���שԤj�D�C�]���o�������س]�A�f�����B����K�F�A�������]�P�i
�F�ĺ��Ĵ��䥻�����ӷ~�o�i�C�U�ӷU�h�H�g�ѳo���j�D�Ө��ĺ��Ĵ��A
�Ӧb�o�̫n�誺�u�Z�^���q�v�Ȫ��]�����o�ǤH�𮧾n�������n�a�I�C
LONG 
);
        set("exits",([
            "west":__DIR__"port_20",
            "south":__DIR__"port_24",
            "east":__DIR__"port_22"
                ]));
        set("world","world1");
        set("outdoor","land");

        setup();

}
int valid_leave(object me, string dir)
{
        if( (dir=="east"||dir=="south") && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}


