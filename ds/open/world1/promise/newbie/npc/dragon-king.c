#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY"�s��"NOR, ({ "dragon king","king" }));
        set("long","���s�𪺦Ѥj�A���ˤO���װ��C\n");

        set("race","���~");
        set("level", 15);
        set("age", 533);  
        set("exp",5000);        set("title",HIR"���s��"NOR);
        set("limbs", ({ "�s�Y","����","���","Ĳ��","�e�}","��}","�I�_" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",3000); 
carry_object(__DIR__"eq/dragon-helmet")->wear();
}
int special_attack(object me,object target,int hitchance)
{
    if(!me || !target) return 0;
    if(random(10)) return 0;
    {
      message_vision(HIR"�s����M�����o���A�V$n�ƨg���ç�I�I\n"NOR,me,target);
      target->receive_damage("hp",50+random(50), this_object());
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
HIW"\n\t\t"+ob->name(1)+""HIR"���ѤF���s�� "HIW"�s��"HIR"�A�ҩ��ۤv����O�w�D�s��I�I\n\n"+NOR,users());
          ob->add("popularity",1); 
        ::die();

        return;

}

