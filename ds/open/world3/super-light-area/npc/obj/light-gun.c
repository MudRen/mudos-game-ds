#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name(HIY"光子槍"NOR,({"light gun","gun"}) );
set("long","一把上面有『光子訓練場』的超級武器！\n");
set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",1200);
                set("rigidity",800);    
                set("material","iron");
 set("limit_lv",15);
                                set("limit_con",5);
                set("limit_int",15);
                set("limit_str",15);
        }

        set("wield_msg","$N拿起一顆膠囊念了幾句，它就變成了一把$n！\n");
        set("unwield_msg", "$N把$n沾了幾滴水，$n就便回一顆膠囊。\n");
        set("bullet_type","light_clip");
        set("max_load",25);             //最大裝填量
       init_gun(25);
        setup();
}
