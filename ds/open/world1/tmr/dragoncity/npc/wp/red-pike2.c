#include <weapon.h>
#include <ansi.h>
inherit SSERVER;
inherit FORK;

void create()
{
        set_name( "�V�G���j" ,({"red pike", "pike"}) );
        set("long",@LONG
�R��j�k�O�F�Y�������W���ޡA�ӤV�G���j�h�O�L���M�ݪZ���C
LONG
        );
        set_weight(8000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("value",16000);
                set("volume", 2);
                 set("material", "gold");
                set("limit_level", 30);
        }
        set("replica_ob",__DIR__"red-pike2");
        set("weapon_prop/shield",5);
        set("weapon_prop/armor",5);
        set("weapon_prop/int", 1);
        set("weapon_prop/str", 1);
        init_fork(55);
        setup();        
}

