#include <ansi.h>; 
#include <weapon.h>
inherit GUN;
void create()
{
set_name(HIR"離子束加農砲"NOR,({"firestorm cannon","cannon"}));
set("long","此武器可以在數秒內以強大的火力撕裂敵人。
[最多能填裝90發等離子子彈]\n");
 set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
             set("limit_str",15);
                set("value",5000);
                set("rigidity",600);   
                set("material","iron");
        }

        set("wield_msg","$N把$n的保險栓解開。\n");
        set("unwield_msg", "$N把$n保險栓關閉。\n");
        set("bullet_type","firestorm");     
        set("max_load",90);           
        init_gun(30);   
        setup();
}

