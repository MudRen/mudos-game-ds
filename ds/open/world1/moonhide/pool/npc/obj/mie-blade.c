
#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit BLADE;
void create()
{
        set_name(HIM"滅語魔神刀"NOR,({"evil-god blade","blade","evil"}));

        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "上古神兵石製造，加上惡魔血液打造出的魔性之作。\n"NOR);
                set("volume",2);
                set("unit", "把");
                set("value",20000);
                set("limit_skill",50);
                set("material","silver");
        }

        init_blade(65, TWO_HANDED);
        set("wield_msg","$N裝備$n後，奔騰的魔性便附加在$N身上！\n"NOR);
        set("unwield_msg","$N收起$n後，一切回歸正常。\n"NOR);
        set("replica_ob", __DIR__"evil-blade.c");
        setup();
}

/*
void attack(object me,object victim)
{
        int damage,str,con,random1;
        ::attack();
        if(!me) return;
        if(!victim) return;
        if( random(200)>150)
        {
        str = me->query("str")-random(22);
        con = me->query("con")-random(20);
        random1 = 1+random(2);
        damage = random1*(str+con);
        victim->receive_damage("hp", damage, me );
        message_vision(
HIR"\n\t手中的刀魔性大發，數道亡魂變從刀裡竄出，\n"
HIW"\t餓鬼、前鬼、後鬼、莿鬼變化身數道真氣，\n"
HIG"\t攻擊$N的百竅穴、天關穴，使得$N身上魔氣無法散出！！\n"

HIM"\t(造成"+damage+"點的傷害！！)\n\n"NOR      
                ,victim);
        return;
        }
}
*/
