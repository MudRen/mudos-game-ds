#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW"【"HIG"闇"HIR"之"HIY"神"HIC"劍"HIW"】"NOR, ({ "darksword-spirit","sword","spiritsword" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", ""HIW"【"HIG"闇"HIR"之"HIY"神"HIC"劍"HIW"】"NOR"之劍刃上泛透著"BLK"深黑色"NOR"ㄉ闇光。\n");
                set("value", 200000); 
                set("no_sell", 1);
                set("rigidity", 500);
                set("wield_msg", "$N將手向下一晃$n之柄由袖口滑出,霎那間這裡整個的暗ㄌ下來,漆黑的啥麼都看不見。\n");
                set("unwield_msg", "$N將手上的$n收回袖內。\n");
        } 
                set("weapon_prop/bar", 5);
                set("weapon_prop/bio", 5);
                set("weapon_prop/wit", 5);
                set("weapon_prop/sou", 5);
                set("weapon_prop/tec", 5);
                set("weapon_prop/str", 25) ;
                set("weapon_prop/con", 25) ;
                set("weapon_prop/int", 25) ;
                set("weapon_prop/dex", 25) ;
                set("weapon_prop/shield", 400) ;  
                set("weapon_prop/damage", 400) ; 
                set("weapon_prop/hit", 400) ;  
                set("weapon_prop/armor", 400) ;  
                set("weapon_prop/parry", 400) ;  
                set("weapon_prop/dodge", 400) ;
     init_sword(789);
        setup(); 
{
  if(!wizardp(this_player())) destruct(this_object());
}
}
int query_autoload() { return 1; }














