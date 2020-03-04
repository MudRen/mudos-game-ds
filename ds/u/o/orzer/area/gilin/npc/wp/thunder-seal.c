#include <weapon.h>
inherit THROWING;
mapping *w_actions=({
                ([
                "action":       "$N將$w闔在雙手,引出了$w的靈術往$n而去",
                "damage_type":  "雷傷",
                "post_action":  (: call_other, __FILE__, "throw_weapon" :),
                "attact_type":  "wit"
                ]) ,
                
                ([
                "action":       "$N將$w闔在雙手,引出了$w的靈術往$n而去",
                "damage_type":  "雷傷",
                "post_action":  (: call_other, __FILE__, "throw_weapon" :),
                "attact_type":  "wit"
                ]) ,});
void create()
{
        set_name("石頭",({"stone"}) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("base_unit", "顆");
                set("unit", "堆");
                set("base_volume",1);
                set("base_weight",300);
                set("material", "rock");
        set("long",@LONG
一顆雞蛋般大小的石頭。
LONG);
        }
        init_throwing(10);
        setup();
        set("value",30);
        set("volume", 1);
        set_amount(1);

}


mapping query_action()
{
        return w_actions[random(sizeof(w_actions))];
}


void throw_weapon(object me, object victim, object weapon, int damage)
{
     if(objectp(weapon))
     {
      message_vision("$N被雷電擊中,身體一陣發麻無法動彈﹗\n",victim);     
      victim->start_busy(1);
     }
}
