#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"第一特獎獎卷"NOR,({"no.1 ticket","ticket"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "張");
                set("long",
               HIG"第一特獎獎卷，可以Save留著等"HIR"Promise"HIG"來給你禮物。\n"NOR);
             }
        set_weight(100);     
        set("no_give",1);
        set("no_drop",1);
        set("no_auc",1);
        set("no_sell",1);
        
        setup();
} 
int query_autoload() { return 1; }

