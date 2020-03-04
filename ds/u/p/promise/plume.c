#include <ansi2.h>
#include <weapon.h>

inherit ITEM;

void create()
{
        set_name(HIR"鳳凰之羽"NOR, ({ "plume of phoenix", "plume" }) );
        set_weight(1000);
        set("long", @long
這一根是傳說中的古代生物鳳凰身上的羽毛，具有不可思議
之能力，傳說用這羽毛制成的東西都是堅硬無比。
long);
        set("unit" , "根");
        set("value", 1);
        set("no_repair", 1);

        setup();
}

void init()
{
        add_action("do_get", "get");
        return;
}

int do_get(string arg)
{
        if( arg=="plume")
        {
                if( !this_player()->query_temp("quest/phoenix") ) 
                {
                        write("有種神奇力量令你拿不起這個東西。\n");
                        return 1;
                }
        }
}

