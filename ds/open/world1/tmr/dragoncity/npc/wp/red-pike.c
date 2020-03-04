#include <weapon.h>
#include <ansi.h>
inherit SSERVER;
inherit FORK;
inherit F_UNIQUE;

void create()
{
        set_name( HIR "�V�G���j" NOR,({"red pike", "pike"}) );
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
                set("limit_skill", 80);
        }
        set("replica_ob",__DIR__"red-pike2");
        set("weapon_prop/shield",10);
        set("weapon_prop/armor",10);
        set("weapon_prop/bio", -1);
        set("weapon_prop/sou", 1);
        set("weapon_prop/int", 1);
        set("weapon_prop/str", 1);
        init_fork(65);
        setup();        
}

