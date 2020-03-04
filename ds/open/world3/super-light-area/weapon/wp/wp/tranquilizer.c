#include <ansi.h>; 
#include <weapon.h>
inherit GUN;
void create()
{
set_name(MAG"麻醉槍"NOR,({"tranquilizer gun","gun"}));
set("long","它提供一種可以暫時甩掉敵人但不會至敵於死的方法, 
            但是時間並不能維持長久, 屬於全自動的高級武器[0;1m�[1mC[0m\n");
        set_weight(2700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
              set("limit_int",20);
                set("value",2500);
                set("rigidity",600);   
                set("material","iron");
        }

        set("wield_msg","$N從背後的$n拿下來, 將$n的保險桿拉開。\n");
        set("unwield_msg", "$N將手中的$n保險桿推回, 並放回背上去。\n");
        init_gun(20);   
        setup();
}
void attack(object me, object victim)
{
    int damage,def;

    ::attack();
    if(!me) return;
    if(!victim) return;

    if(me->query_skill("gun") > 20 && me->query_int() > 20 && random(10)<3 )
    {
      message_vision(HIW "\n突然從槍口暴出一隻小箭向$n！！\n" NOR,me,victim);
      damage += me->query_skill("gun")+me->query_str()+random(30);
      def += victim->query_skill("parry")+victim->query_skill("dodge")+victim->query_dex()+victim->query_con();
      def = def/3;
      if(damage-def>0 && random(10)>5)
      {
        damage=damage+random((damage-def));
        message_vision(HIR "$N一個失神, 被這隻箭麻痺了！\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
     victim->start_busy(5);
        }
      else message_vision(HIG "$N一個巧妙的迴旋踢, 將小箭給踢掉了。\n"NOR,victim);
    }
    return;
}

