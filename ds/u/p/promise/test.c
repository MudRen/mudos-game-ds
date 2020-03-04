#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"《防具》"HIB"加強捲軸"NOR, ({ "equip scroll" , "scroll"}) );
        set_weight(250);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",  
"這個藍色的捲軸上面寫滿了密密麻麻的文字，這些文字似乎不屬\n"
"於這個空間，看得你是滿頭的霧水，看來只好問問神了•\n"+
HIC"(help scroll)\n"NOR);
                set("unit", "張");
                set("value", 0);
        }
        setup();
}

void init()
{ 
        add_action("do_castwp", "castwp"); 
        add_action("do_casteq", "casteq"); 
}

int do_castwp(string arg)
{
        object me = this_player(), ob;
        int add  = 1+random(2); 
        if( !arg ) return notify_fail("castwp <物品id>\n");
        if( !objectp( ob = present( arg, me) ) ) 
                return notify_fail("你身上沒這個物品。\n");
        if( !ob->query("skill_type") )
                return notify_fail("只能使用在武器上面。\n");
        if( ob->query_temp("lv_up") )
                return notify_fail("這個武器已經不能再升級了。\n");
        if( ob->query("equipped") )
                return notify_fail("請先解除裝備。\n"); 
         ob->set_temp("lv_up",1);
         ob->add("weapon_prop/bar", add); 
ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了獸性(BAR) "+add+" 點了•\n");
        destruct(this_object());
    return 1;
}
int do_casteq(string arg)
{
        object me = this_player(), ob;
        int add = 1+random(2); 
        if( !arg ) return notify_fail("casteq <物品id>\n");
        if( !objectp( ob = present( arg, me) ) ) 
                return notify_fail("你身上沒這個物品。\n");
        if( !ob->query("armor_type") )
                return notify_fail("只能使用在防具上面。\n");
        if( ob->query_temp("lv_up") )
                return notify_fail("這個防具已經不能再升級了。\n");
        if( ob->query("equipped") )
                return notify_fail("請先解除裝備。\n");
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/bar", add); 
ob->add("long","這"+ob->query("unit")+ob->query("name")+"已經增加了獸性(BAR) "+add+" 點了•\n");
    destruct(this_object());
        return 1;
}

