#include <ansi.h>
inherit ITEM;

void create()
{
        switch(random(2)){
        case 0:
        set_name(HIW"《防具》"HIB"加強捲軸"NOR, ({ "equip scroll" , "scroll"}) );
        set_temp("eq_scroll",1);
        break;
        default:        
        set_temp("wp_scroll",1);
        set_name(HIW"《武器》"HIB"加強捲軸"NOR, ({ "weapon scroll", "scroll" }) );
        break;
        }
        set_weight(250);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "有著莫名力量的捲軸。\n");
                set("unit", "張");
                set("value", 0);
        }
        setup();
}

void init()
{ 
   if ( query_temp("wp_scroll")){
        add_action("do_castwp", "castwp"); 
   } else {
        add_action("do_casteq", "casteq"); 
      }
}

int do_castwp(string arg)
{
        object me = this_player(), ob;
        int bar,addbar = 1+random(2);
        if( !arg ) return notify_fail("castwp <物品id>\n");
        if( !objectp( ob = present( arg, me) ) ) 
                return notify_fail("你身上沒這個物品。\n");
        if( !ob->query("skill_type") )
                return notify_fail("只能使用在武器上面。\n");
        if( ob->query_temp("weapon_prop/bar"))
                return notify_fail("這個武器已經不能再升級了。\n");
        if( ob->query("equipped") )
                return notify_fail("請先解除裝備。\n");
        ob->add_temp("weapon_prop/bar", addbar); 
        ob->init_weapon();
        ob->add("long","這個武器已經增加了BAR"+addbar+"點了");
        message_vision("$N身上的"+ob->query("name")+"閃出金黃色的光芒，在光芒退去後，"+ob->query("name")+"似乎變的更強了。\n", me);
        destruct(this_object());
        return 1;
} 
 
int do_casteq(string arg)
{
        object me = this_player(), ob;
        int bar,addbar = 1+random(2);
        if( !arg ) return notify_fail("casteq <物品id>\n");
        if( !objectp( ob = present( arg, me) ) ) 
                return notify_fail("你身上沒這個物品。\n");
        if( !ob->query("skill_type") )
                return notify_fail("只能使用在防具上面。\n");
        if( ob->query_temp("armor_prop/bar"))
                return notify_fail("這個防具已經不能再升級了。\n");
        if( ob->query("equipped") )
                return notify_fail("請先解除裝備。\n");
        ob->add_temp("armor_prop/bar", addbar); 
//      ob->init_weapon();
        ob->add("long","這個防具已經增加了BAR"+addbar+"點了");
        message_vision("$N身上的"+ob->query("name")+"閃出金黃色的光芒，在光芒退去後，"+ob->query("name")+"似乎變的更強了。\n", me);
        destruct(this_object());
        return 1;
}

