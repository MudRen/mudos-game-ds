#include <ansi.h> 
inherit NPC;
void create()
{
  set_name(HIR"�j�a"NOR, ({"hua-di snake","di","hua", "snake"}) );
  set("long","���~���b�a���U�����~�A�w���o�ʦ~���A�y�U�������A���|�a�ӭ��j���ˤ`�C\n");
  set("race", "beast");
  set("unit","��");
  set("age",106);
  set("title","���}");
  set("level",45); 
  set("max_hp",26000);
  set_skill("dodge",200);
  set_skill("unarmed",100);
  set("limbs", ({ "�Y��", "����","�ݳ�","����" }) );
  set("verbs", ({ "bite" }) ); 
        set("chat_chance_combat",13);
        set("chat_msg_combat",({ 
    (: random_move :), 
}));  
  setup(); 
  set_temp("apply/armor", 200);
  set_temp("apply/damage",100);
  set_temp("apply/shield", 150);
}
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(6)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*30) > tdex+tcon)
    {
      message_vision(HIR"\n\n$N"+HIW"�i�}��֤j�f�I\n"
                    +HIW"�@��"+HIB"�Ŧ�"+HIW"����q�������E�E�E�E�E\n"
                    +HIR"�Q�V$n�A$n�Q���j����q�T�S�A���麥���·��I\n\n"+NOR,me,target);  
     target->receive_damage("hp",350+random(350), this_object()); 
     target->start_busy(2);
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
                HIR"\n\t ���}�ʦ~�j�D �j�a ���Q"+ob->name(1)+ HIR "���A�F�I�I\n\n"+NOR,users());
        ob->add("popularity", 2);
         if( random(100) < 15)
                new(__DIR__"snake-surcoat3")->move(this_object());
        else
                new(__DIR__"snake-surcoat2")->move(this_object());
        ::die();
        return;
}


