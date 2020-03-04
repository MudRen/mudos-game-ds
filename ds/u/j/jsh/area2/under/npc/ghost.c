#include <ansi.h>
inherit NPC;
void create()
{
        set_name(GRN"百毒鬼"NOR, ({ "poison ghost","ghost" }) );
        set("long","從一本古書跑出來的鬼怪。\n");
        set("level",32+random(15));
        set("age",100+random(4)); 
        set("title",HIG"毒毒毒"NOR);
        set("combat_exp", 10000+random(1000)); 
        set("evil",-20);        setup();
}  
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
   if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*10) > tdex+tcon)
    {
      message_vision("\n"
                    +HIW"$N忽然眼睛一亮 -____-+\n" NOR     
                    +HIG"往$n衝去，張開大口咬了下去..!!!\n"NOR 
                    +HIR"傷口立即腐爛，發出臭味....\n"NOR
                    ,me,target);
      target->receive_damage("hp",50+random(50), this_object()); 
      apply_condition("poison",50);      return 1; 
    }
void die() 
{
    object ob; 
    if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);

    if( !ob ) { 
        ::die();
        return;
    } 
    ob->add("popularity",1); 
    message_vision(HIW"$N變成一陣煙霧散去了。\n"NOR, this_object() );
    ::die();
    return;
}

