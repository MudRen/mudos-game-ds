#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name(HIM"穿姻緣"NOR,({"Marriage needle-whip","whip"}) );
        set_weight(1000);
        set("long",@long
一捆長長的絲線，通體銀白，為一粉紅色的金屬從頭貫穿，煞是好看。
long
        );
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("value",1500);
        set("unit","根");
        set("wield_msg","$N將$n倏地抽出，纏繞在手上。\n");
        set("material","iron");
        }
        init_whip(30);
        setup();

}

void attack(object me,object victim)
{
        ::attack();
        if(!me) return;
        if(!victim) return;
 if( me->query("mp") < 50 ) return;
 if( random(10) < 6 ) return;
 message_vision("\n"
                        +HIW"$N輕旋指尖，穿姻緣若有神引的往$n飛去！\n"NOR
                        +HIW"穿姻緣貫穿了$n的身體，猛地一聲炸響！\n\n"NOR,me,victim);
  victim->receive_damage("hp", 100+random(100),me);
 me->receive_damage("mp",30);
 me->add_busy(1);
return;
}
