#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
 set_name(HIC"冰•風暴戰斧"NOR,({"ice storm axe","axe"}));
set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("long","    這把斧頭看來平平無奇，就像一般鐵斧一樣，但是
    外面結了一層不溶的冰，並發出神和冰的氣。大概是掉落在
    神山上的斧頭，受到經年累月神光的保護，才得已擁有如此大的
     力量吧。\n");
set("value",4500);
                set("material", "steel");
}
init_axe(855);
set("wield_msg","$N將$n握在手中，$N登時充滿力量，但$N身旁的人卻冷的直打顫");
set("unwield_msg", "$N將$n掛回腰邊，冷氣終於停止了。\n");  
        setup();
}
void attack(object me,object victim)
{
int damage,str,dex;
if( random(100)>70)
    {
        /*   COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),2);*/
str = me->query("str");
dex=me->query("dex");
damage=(str+dex)*(1+random(10));
        victim->receive_damage("hp", damage, me );
message_vision("                  冰•風暴戰斧突然發出強大的光芒

                       從天上召喚來一陣冰雹

              向$N擊去！！！造成$N"+damage+"點的傷害！！！！\n",victim);
         return;
        }
    return;
}
