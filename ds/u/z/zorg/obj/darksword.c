#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW"【"HIG"闇"HIR"之"HIC"劍"HIW"】"NOR, ({ "darksword","sword" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", ""HIW"【"HIG"闇"HIR"之"HIC"劍"HIW"】"NOR"之劍刃上泛透著"BLK"深黑色"NOR"ㄉ闇光。\n");
                set("value", 20000); 
                set("no_sell", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_get", 1);
                set("rigidity", 500);
                set("wield_msg", "$N將手向下一晃$n之柄由袖口滑出,霎那間這裡ㄉ光暗ㄌ一倍有餘,劍刃上泛透著"BLK"深黑色"NOR"ㄉ闇光。\n");
                set("unwield_msg", "$N將手上的$n收回袖內。\n");
        } 
                set("weapon_prop/bar",3);
                set("weapon_prop/bio",3);
                set("weapon_prop/wit",3);
                set("weapon_prop/sou",3);
                set("weapon_prop/tec",3);
                set("weapon_prop/str", 15) ;
                set("weapon_prop/con", 15) ;
                set("weapon_prop/int", 15) ;
                set("weapon_prop/dex", 15) ;
                set("weapon_prop/shield", 300) ;  
                set("weapon_prop/damage", 300) ; 
                set("weapon_prop/hit", 300) ;  
                set("weapon_prop/armor", 300) ;  
                set("weapon_prop/parry", 300) ;  
                set("weapon_prop/dodge", 300) ;
     init_sword(300);
        setup(); 
{
  if(!wizardp(this_player())) destruct(this_object());
}
}
int query_autoload() { return 1; }


