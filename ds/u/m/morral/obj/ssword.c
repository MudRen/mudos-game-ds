#include <weapon.h>
#include <ansi.h>

inherit SWORD;
void create()
{set_name(HIR"必殺劍"NOR,({"smash sword","sword","smash"}) );
set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("long",HIG"這把劍厚重鋒利，可說是劍中極品。\n"NOR);
set("value",20000);
init_sword(1000);
                set("material", "blacksteel");
set("wield_msg","$N從側背拔出$n，霸氣登時從$N的身上散發出來！\n");
set("unwield_msg", "$N將手中的$n小心收好。\n");
}
setup();
}  
void attack(object me,object victim)
{
int damage,str,dex;

if( random(200)>=0)
    {
str =me->query("str");
dex=me->query("dex");
damage=1000+random(500*(str+dex));
        victim->receive_damage("hp", damage, me );
message_vision(HIY" 終命一擊！！！

                造成$N"+damage+"點的傷害！！！！\n"NOR,victim);           
         return;    
  }
}             
