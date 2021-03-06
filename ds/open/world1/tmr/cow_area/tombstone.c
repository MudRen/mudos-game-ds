#include <ansi.h>
#include <path.h>

inherit ITEM;

#define COW_AREA_ENTER "/open/world1/tmr/cow_area/enter.c"

void create()
{
        set_name("林牧老碑",({"meadow tombstone","tombstone"}) );
        set_weight(200000);
        set("long",@LONG
這是一座老墓碑，用來祭拜所有死在牯林草原上的生物。你注意到
墓碑上有個畸形的凹痕，乍看之下，還以為是誰的腳印在上面呢。
你或許會想要試試放置(place)什麼東西上去。
LONG
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","座");
                set("no_get",1);
                set("no_sac",1);
                set("value", 20000);
        }
        setup();
}

void init()
{
        add_action("do_place", "place");
}

int do_place(string arg)
{
        object me, leg;
string item;
        me=this_player();
if(!arg || arg!="leg on tombstone")
return notify_fail("你想要放置(place)什麼到墓碑上？\n");
if( sscanf(arg, "%s on tombstone", item) != 1 )
return notify_fail("你想要放置(place)什麼到墓碑上？\n");

        if(!objectp(leg=present(item,me) ) )
                return notify_fail("你身上沒有這個東西。\n");
        
        if( leg->id("TRUMP_LEG") ) {
        message_vision(CYN "$N將$n"CYN"安置到墓碑上的凹痕，想不到大小剛好。\n" NOR, me, leg);
        message_vision(HIC "一陣閃光出現，$N在墓碑前消失不見了。\n" NOR, me);
        me->move(COW_AREA_ENTER);
        destruct(leg);        
        } else {
        message_vision(CYN "$N將$n"CYN"安置到墓碑上的凹痕，但怎麼塞都無法塞進去。\n" NOR, me, leg);
        }
        
        return 1;
}

