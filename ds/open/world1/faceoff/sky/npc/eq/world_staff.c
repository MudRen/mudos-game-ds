#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit STAFF;
void create()
{
        set_name(HIW"拂世杖"NOR,({"whisk-world staff","staff"}));
        set_weight( 6000 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
這是雲風聖道所使用的聖仗，用來掃除人世間的諸邪萬惡。
雲風聖道在六十六歲那年得道，而創出「九重天咒」, 從此戰鬥
不再使用此仗，而將此杖轉贈與他人。
LONG
                                );
                set("volume",2);
                set("unit", "把");
                set("value",12500);
                set("material","steel");
                set("limit_lv", 25);
        }
        set("weapon_prop/bio", -1);
        set("weapon_prop/sou", 1);
        set("weapon_prop/str", 2);

        set("replica_ob",__DIR__"world_staff2");
        set("wield_msg", HIW "$N雙手緊握拂世杖, 雙眼隱隱約約有股溫和慈愛的光芒。\n"NOR);
        set("unwield_msg", "$N將手中的$n放了回去，又恢復成為平日的狀態了\n");
        init_staff(71);
        setup();
}

void attack(object me,object victim)
{
        int damage;
        ::attack();
        if(!me) return;
        if(!victim) return;
        if( random(100)<70) return;
        if( me->query_skill("staff") < 50 ) return;
        
        damage = (me->query("int") + me->query("dex") - random(50));
        if( damage < 1 ) return;
        message_vision(
                HIW"從拂世杖杖頭冒出一陣亮青色的白煙，竟然浸入了$N"+ HIW "的體內，結果造成了" + damage+"點傷害！！\n"NOR
        ,victim, me);
        victim->receive_damage("hp", damage, me );
}
