#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIM"�s�Z"NOR, ({ "dragon queen","queen" }));
        set("long","���s���s�����R�d�A��O�������s���C\n");

        set("race","���~");
        set("level", 14);
        set("age", 533);  
        set("exp",3000);        set("title",HIR"���s��"NOR);
        set("limbs", ({ "�s�Y","����","���","Ĳ��","�e�}","��}","�I�_" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",3000); 
carry_object(__DIR__"eq/dragon-ring")->wear();}
int special_attack(object me,object target,int hitchance)
{
    if(!me || !target) return 0;
    if(random(10)) return 0;
     {
    message_vision(HIR"�s�Z�j�O����$n���W��F�X�U�A�y�����i�ٷ����˲��I�I\n"NOR,me,target);
      target->receive_damage("hp",30+random(50), this_object());
      return 1; 
    }
   }
void die()
{
   object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);

        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
HIW"\n\t\t"+ob->name(1)+""HIY"���ѤF���s�� "HIM"�s�Z"HIY"�A���s���j�o�p�^�I�I\n\n"+NOR,users());
                ::die();
        return;
}

void init()
{
  ::init();
  add_action("do_guard","go");
}

int do_guard(string arg)
{
  if(!userp(this_player())) return 0;
  if(arg == "south")
  {

    message_vision(HIW"�s�Z��D�G�n���ڦѤ��A������ڦb���I�I\n"NOR,this_player(),this_object());
    
  }
  return 1;
}

