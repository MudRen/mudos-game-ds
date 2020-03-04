/*************************************************/
/*  Skill 鍛筋銼骨           Date:2003.4.7       */
/*  Editor - Jangshow        Lv 50 new sk        */
/*  說明:依此 sk 的高低來決定增加時間的長短      */
/*************************************************/ 
#include <ansi.h>
#define SKILL_NAME "鍛筋銼骨"
inherit SKILL;
inherit SSERVER;

int exert(string arg)
{   
     object me=this_player();
     //這行有跟沒有都一樣，但還是寫一下好了
     if(me->query("level") < 50 ) return notify_fail("你的等級不夠喔。\n"); 
     if(me->query("con") < 70 ) return notify_fail("你的體質不夠承受此項技能。\n");   
     message_vision(HIW"$N運起上古的鍛筋銼骨之術，大大提升了體能。\n"NOR,me); 
     {
     //分 4 層
        if(me->query_skill("body-improvement") <= 25)
        {
          me->add("max_hp",200);
          call_out("DE_ADD",120,me);
        }
        else if(me->query_skill("body-improvement") <= 50) 
        {
          me->add("max_hp",200);
          call_out("DE_ADD",180,me);
        }
        else if(me->query_skill("body-improvement") <= 75) 
        {
          me->add("max_hp",200);
          call_out("DE_ADD",240,me);
        }
        else if(me->query_skill("body-improvement") >=100) 
        {
          me->add("max_hp",200);
          call_out("DE_ADD",300,me); 
        }
        else return 1; 
      }
      me->improve_skill("body-improvement",1+random(me->query_int()/5)); 
      return 1;
} 
void DE_ADD(object me)
{ message_vision("$N輕喘一聲，結束了鍛筋銼骨之術。\n",me);me->receive_damage("max_hp",200); return;}   
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
