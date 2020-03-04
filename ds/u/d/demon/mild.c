#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
        set_name(HIC"七星大香菸"NOR,({"mild seven sword","sword","mile"}));

        set_weight(5000+random(1000));
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIB"這隻菸看起來並不顯眼，可是在你抽出這隻菸時，卻發現這菸粗大堅硬\n"
                      "之處，在菸頭上隱隱有些許\的煙霧飄散出來。傳說這隻菸是古代時異人\n"
            "用菸絲和玄鐵紙包捲而成，所以這一隻菸當然是無與倫比的頂級貨(博來品ㄛ)。\n"NOR);
                set("volume",2);
                set("unit", "隻");
                set("value",12500);
        set("limit_skill",60);
        set("material","silver");
                set("limit_lv",25);
                set("limit_str",30);
                set("limit_dex",35);
        }
        init_sword(70);
        set("wield_msg","$N從背後的菸盒中抽出一隻$n，登時一片煙霧從$N的身上散發出來！\n");
        set("unwield_msg", "$N將手中的$n小心收好。\n");
        set("replica_ob", __DIR__"longsword.c");
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
        str = me->query("str")-random(20);
        dex = me->query("dex")-random(18);
        random1 = 1+random(2);
        damage = random1*(str+dex);
        victim->receive_damage("hp", damage, me );
        message_vision(
        "\n"
        +HIY"七星大香菸在菸頭一片一片的煙霧隱隱的散了出來。\n"NOR
        +HIG"一股熱能從菸頭激射而出∼∼∼．．．．．．\n"NOR
        +HIR"倏地間，在$N眼前一片煙霧彌漫！！！從菸頭散出一道黑煙往$N而去。\n"NOR
        +HIB"結果造成$N"+damage+"點的傷害！！！！\n"NOR
        ,victim);
        return;
        }
}
  
