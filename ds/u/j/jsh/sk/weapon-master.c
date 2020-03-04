/*************************************************/
/*  Skill 兵器大師           Date:2003.4.7       */
/*  Editor - Jangshow        Lv 50 new sk        */
/*  說明:依此 sk 的高低來決定增加時間的長短      */
/*************************************************/ 
#include <ansi.h>
#define SKILL_NAME "兵器大師"
inherit SKILL;
inherit SSERVER;

int exert(string arg)
{    
     int sk_lv,damage;
     object me=this_player(); 
     sk_lv=me->query_skill("weapon-master"); 
     weapon=me->query_temp("weapon"); 
     damage=me->weapon*(1+0.03*sk_lv); //這行有問題,你改一下,weapon的攻擊力我沒抓
     if(me->query("level") < 50 ) return notify_fail("你的等級不夠喔。\n"); 
     if(me->query("str") < 70 ) return notify_fail("你的力量不夠承受此項技能。\n");  
     if(!weapon) return notify_fail("你手中沒有武器，如何來提升攻擊力？\n"); 
      message_vision(HIW"$N眼神一亮，增加了手中的殺傷力。\n"NOR,me); 
     { 
      me->add("damage",damage); //攻擊力的data是啥?
       裝備武器時,提升之攻擊力=(武器攻擊力)*(1+0.03*sk_lv)
     }      me->improve_skill("weapon-master",2+random(me->query_int()/5)); 
      return 1;
} 
void DE_ADD(object me)
{ message_vision("$N的眼神漸漸暗淡。\n",me);me->receive_damage("max_hp",); return;}   
int valid_learn(object me)
{
        return 1;
} 

int improve_limite(object ob)
{
        return 100;
}

int practice_skill(object me)
{
        return 1;
}

