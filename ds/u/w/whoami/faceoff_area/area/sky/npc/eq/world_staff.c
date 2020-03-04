#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit STAFF;
void create()
{
        set_name(HIW"拂世杖"NOR,({"world staff","staff"}));
        set_weight(5000+random(1000));
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIW"這是傳說中風雲聖道所使用的聖仗, 它的用意本是掃除世間邪惡....\n"
                      "但風雲聖道在三十三歲那年悟出九重天咒, 從此戰鬥不再使用此仗, 因此將\n"
                 "此仗贈與他人...。\n"NOR);
               set("volume",2);
                set("unit", "把");
                set("value",12500);
              set("material","steel");
                set("limit_lv",25);
        }
        init_staff(71);
        set("wield_msg",HIW"$N雙手緊握拂世杖, 霎時一股光芒射出！\n"NOR);
        set("unwield_msg", "$N將手中的$n放了回去, 同時光芒黯淡了不少。\n");
        setup();
}

void attack(object me,object victim)
{
        int damage,str,dex,random1;
        ::attack();
        if(!me) return;
        if(!victim) return;
        if( random(200)>150)
        {
        str = me->query("int")-random(20);
        dex = me->query("dex")-random(18);
        random1 = 1+random(2);
        damage = random1*(str+dex);
        victim->receive_damage("hp", damage, me );
        message_vision(
        "\n"
        +HIW"拂世杖杖頭冒出一股青煙, 一道綠光自青煙中射向$N !\n"NOR
        +HIW"結果造成$N"+damage+"點的傷害！！！！\n"NOR
        ,victim);
        return;
        }
}
