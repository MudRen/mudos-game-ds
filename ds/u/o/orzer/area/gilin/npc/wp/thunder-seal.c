#include <weapon.h>
inherit THROWING;
mapping *w_actions=({
                ([
                "action":       "$N�N$w��b����,�ޥX�F$w���F�N��$n�ӥh",
                "damage_type":  "�p��",
                "post_action":  (: call_other, __FILE__, "throw_weapon" :),
                "attact_type":  "wit"
                ]) ,
                
                ([
                "action":       "$N�N$w��b����,�ޥX�F$w���F�N��$n�ӥh",
                "damage_type":  "�p��",
                "post_action":  (: call_other, __FILE__, "throw_weapon" :),
                "attact_type":  "wit"
                ]) ,});
void create()
{
        set_name("���Y",({"stone"}) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("base_unit", "��");
                set("unit", "��");
                set("base_volume",1);
                set("base_weight",300);
                set("material", "rock");
        set("long",@LONG
�@�����J��j�p�����Y�C
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
      message_vision("$N�Q�p�q����,����@�}�o�µL�k�ʼu�T\n",victim);     
      victim->start_busy(1);
     }
}
