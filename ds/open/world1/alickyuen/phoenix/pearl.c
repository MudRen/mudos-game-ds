#include <ansi.h>

inherit ITEM;
void create()
{
        set_name(HIY"★夜明珠★"NOR, ({ "star pearl", "pearl" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是一顆天黃色的小珠子，上面有一個『★』的圖案，在晚上的時侯會發出閃光。\n");
                set("unit", "顆");
                set("value",100);
                set("check", 0);
                set("no_sac", 1);
        }
                set("phoenix", 1);
        setup();
}

void init()
{
        object me;
        me = environment(this_object());
        if( !me ) return;
        if( !userp(me) ) {
                add_action("do_get", "get");
                return;
        }
        if(!query_light()) start_light(1);

}
int do_get(string arg)
{
        if( arg!="pearl") return 0;
        if( this_player()->query_temp("quest/phoenix") )  return 0;
        write("有種神奇力量令你拿不起這個東西。\n");
        return 1;
}

void gone(object obj)
{
        if( !obj ) obj = this_object();
        if( environment(obj) )
                if( userp(environment(obj)) ) return;
        message_vision("$N在一瞬間變成灰燼了 ....\n\n", obj);
        destruct(obj);
        return;
}

