/**  更新除了神武教二轉弟子以外, 其他 **
 **  門派弟子使用會出現的Bug    **
 **  By Kkeenn@DS 2002/7/19       **/
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name( HIW "懾日劍" NOR, ({ "se ri sword","sword" }) );
        set_weight(17000);
        if( clonep() )
                 set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("material","crimsonsteel");
        set("limit_str",20);
                set("limit_int",25);
                set("long",
                        "這是一把閃著比太陽還要亮之光芒的長劍，\n"
                        "劍呈金黃色，但卻不是黃金，不知是由何種\n"
                        "材質所鑄造而成，在陽光底下閃爍著，非常\n"
                        "耀眼。\n");
                set("wield_msg", "$N從背後劍鞘中抽出一把金光閃閃的$n，握在手中當武器。\n");
                set("unwield_msg", "$N將手中的$n插入背後劍鞘中。\n");
                set("value",8000);
                  set("replica_ob",__DIR__"sunsword2");
                set("volume",5);
        }
                  set("weapon_prop/dex", 1);
                  set("weapon_prop/int",3);

                set("weapon_prop/hit", 10);
                 set("weapon_prop/wit", 1);
                 set("weapon_prop/bar", -1);
                set("weapon_prop/god-fire",10);
                  set("weapon_prop/shield",10);
        init_sword(67,TWO_HANDED);
        setup();
}

void attack(object me,object target)
{
          int SK;
          int INN;
        ::attack();
           if( !me
           || me->query("class1")!="神武教" 
           || me->query("class2")!="神武教" 
           || me->query("level") < 30
           || me->is_busy()
           || me->query_spell("god-fire") < 80
           || me->query("hp") < 300 
           || me->query("mp") < 300 
           || random(100) <70 )
                return;        
        ::attack();
        SK=me->query_spell("god-fire");
        INN=me->query_int();
        message_vision(
        HIG "$N低頭快速地唸了遍「神祝禱-火神篇」，霎時四週布起了一道火牆！！\n" NOR
        + HIR "\n四周的火焰迅速而機動地聚成了一個似神似妖的形體，盤遊在$N頭上\n" NOR,
        me);
        SPELL_D("god-fire")->cast_fire(target,me,SK,INN);
        message_vision(
        HIG "$N全身一陣乏力，身上的火神也消失了。\n" NOR,me);
        me->receive_damage("mp",40);
}
