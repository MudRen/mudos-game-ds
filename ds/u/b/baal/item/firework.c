#include <ansi.h>
inherit ITEM;

void delay();

void create()
{
        set_name(HIR"�Ϥ�"NOR,({"firework","firework"}) );
        set("long","
�Ϥ��w����M��...^^\n"
        );
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        setup();                
}

void init()
{
       add_action("typefire","fire");
}

int typefire(string arg)
{
        object me;
        me=this_player();
        if( arg != "�Ϥ�" && arg != "firework" && arg != "work" ) return 0;
        message("world:world1:vision",
MAG"\n  ���䳱�I���n���q�o�c���`�B���Ǩ�:\n\n\t"RED"�֦���ת��H���̧r�I�ɱ����ﱵ�s�@������ӧa�I���O�O�ѤF�A"MAG"���F��"RED"�N����P�A�I�I\n\n"+NOR
        ,users());
        return 1;
}


