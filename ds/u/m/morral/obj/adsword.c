#include <weapon.h>
#include <ansi.h>

inherit SWORD;
void create()
{set_name(HIY"強化•深皇禮花"NOR,({"advanced fantasy sword","sword","advanced"}) );
set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("long",HIG"這把劍厚重鋒利，可說是劍中極品，比原來的深皇禮花還好。
這把是隊長才能持有的劍，而且代代相傳。傳說開拓者－吉伯踏上這片
大陸時，手中持的就是這一把劍。但真的那一把已經不知去向。\n"NOR);
set("value",20000);
set("sword",120);
init_sword(300);
                set("material", "blacksteel");
set("wield_msg","$N從側背拔出$n，霸氣登時從$N的身上散發出來！\n");
set("unwield_msg", "$N將手中的$n小心收好。\n");
}
setup();
}  
void attack(object me,object victim)
{
int damage,str,dex;

if( random(200)>80)
    {
str =me->query("str");
dex=me->query("dex");
damage=1000+random(50)*(str+dex);
        victim->receive_damage("hp", damage, me );
message_vision(HIY" 強化•深皇禮花忽然往天空飛去，挾帶著神聖之光
          
                   向$N擊去！！！造成$N"+damage+"點的傷害！！！！\n"NOR,victim);           
         return;    
  }
}             
