#include <ansi.h>
#include <net/daemons.h>
inherit ITEM;

void create()
{

        set_name(HIC"DNS MASTER�u��"NOR,({"dns master tool","master","dns","tool
"}));
        setup();

}

void init()
{
        add_action("do_monitor","monitor");
}

int do_monitor(string arg)
{
        object me = this_player();

        if( arg == "on" )
                DNS_MASTER->set_monitor(me);
        if( arg == "off" )
                DNS_MASTER->set_monitor(0);

        return 1;
}

