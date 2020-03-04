#include <ansi.h>  
#include <armor.h>
inherit SHIELD; 
void create()
{
        set_name(HIW"水鏡之盾"NOR,({ "water-mirror shield","shield" }) );
        set("long","這是用白水晶細細磨成的小盾，表面光滑而閃亮，裡面則刻滿花紋 \n"                   "對於魔法類的攻擊有絕佳的抵抗力。\n");
        set_weight(6000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material","gold");
                set("unit", "件" );
                set("no_sell",1); 
                set("value",30000);
                set("armor_prop/armor", 10);
                set("armor_prop/shield",45);
        }
        setup(); 
        call_out("do_back", 100);
} 
void do_back(string arg)
{
     object me,victim,ob;
     me = this_player(); 
     ob = this_object();
     if(!me->is_fighting() ) 
     write(HIW""+ob->name(1)+"微微振動了一下，發出微微的白光•••\n"NOR);
     victim = me->select_opponent();
     message_vision(HIW""+ob->query_name(1)+""+HIB"發動了神聖力量─"+HIG"『彗星•反擊』！\n"+NOR,me);
     me->start_busy(2);
     if(random(10) >5 )
     {
     message_vision("一道"HIW"白光"NOR"把"HIC""+victim->query_name(1)+""NOR"籠罩住，瞬間"HIR"炸開！！\n"NOR,me);
     COMBAT_D->do_attack(me, victim, this_object(), 5);
     COMBAT_D->report_status(victim);
     victim->start_busy(5);
     victim->receive_damage("hp",200+random(33));
     }
     else
     {
     message_vision(""+victim->query_name(1)+"向旁一閃，躲開了致命的白光••\n",me);
     me->add_busy(2);
     }
     return 1;
}
