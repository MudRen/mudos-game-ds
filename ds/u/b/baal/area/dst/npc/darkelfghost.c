#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "闇精靈怨靈", ({ "darkelf ghost","ghost" }) );
           set("level",24);
           set("combat_exp",1800);
        set("gender","無性");
       set("evil",88);
set("long" ,"步上黑暗之路的精靈-黯精靈死後的靈魂, 他們最令人畏
             懼的便是他們尖銳的歌聲。\n");
        set("age",358);
           set_skill("unarmed",33);
           set_skill("parry",24);
           set_skill("dodge",60);
            set("attitude","killer");
        setup();
}

int special_attack(object me,object target,int hitchance)
{
  int i, hit = random(5)+2, damage;
  if(!me || !target) return 0;
  if(random(5)) return 0;

  message_vision(HIW"\n\t$N臉色忽地刷白，張開了嘴尖聲嘶吼出地獄來的聲音！！\n\n"NOR,me,target);

  {
    damage = 50+random(150);
    message_vision(HIR"$N的尖叫聲鑽入了$n腦袋的最深處，重重的擊在$n的心靈！！造成不小的傷害！ "HIR"("+damage+")\n"NOR,me,target);
    target->receive_damage("hp",damage);
  }
  return 1;
}

