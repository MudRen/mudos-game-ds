#include <ansi.h> 
inherit NPC;    
mapping *combat_action = ({
        ([      "action":       "$N以飛快的速度撞向$n的$l！",
                "attact_type":  "bar",  // 設定技能的攻擊種類
                                        // 種類有 生物(bio) 獸性(bar)
                                        // 魔法(wit)心靈(sou)科技(tec)
                "damage_type":  "撞傷",
        ]), 
});  
void create()
{
  set_name(HIW"轉龍球首"NOR, ({"turn dragon-ball-blue","ball","blue"}) );
  set("long","轉龍以念力驅動氣勁所產生的球體。\n");
  set("title",HIB"藍"NOR);
  set("unit","顆");
  set("level",40); 
  set("max_hp",10000);
  set_skill("dodge",100);
  set_skill("unarmed",100);
        set("chat_chance_combat",9);
        set("chat_msg_combat",({
           (:command("follow "+this_player()->query("id")+""):),
}));   
        set("default_actions", (: call_other, __FILE__, "query_action" :));
  setup(); 
}
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*30) > tdex+tcon)
    {
      message_vision(HIW"\n\n$N疾速的衝撞$n的身體！\n"
                    +HIR"$n被撞的飛了十餘尺遠！\n\n"+NOR,me,target);  
     target->receive_damage("hp",200, this_object());
      return 1; 
    }
}    
/*
varargs int receive_damage(string type, int damage, object who)
{
        int val;

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(100)<30)
                {
                        damage/=2;
                        message_vision("$N大吼一聲！瓦解了敵人的攻勢！\n" NOR,this_object());

                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage,who);
                return damage;
}
*/
