#include <ansi.h>

inherit NPC;
void heal();
void create()
{
        set_name(HIR"�]"NOR, ({ "devil" }) );
        set("long",@LONG
���~����b�a���U�A�P�ѧ��D�P�X�@��A�ͩʦn�j�A��ðd
�����ͪ��A�u���u���v�o�ӿ�k�C 
LONG
);  
        set("gender", "�k��");  
        set("race", "�H��");
        set("attitude","aggressive");
        set("level",45+random(10));
        set("age",200+random(100));
        set("evil",-20);
        set("title",HIC"��"NOR); 
        set_skill("unarmed",120);
        set_skill("dodge",150); 
        set_skill("parry",100);       
        set_skill("combat",100);
        set("combat_exp",200000);
        set("max_exp",80000);
        set("max_hp",30000); 
        set("chat_chance",10);
        set("chat_msg",({
        (: heal :),  
}));
     setup();  
     carry_object(__DIR__"obj/evil-armor-only")->wear();
     carry_object(__DIR__"obj/evil-spear")->wield();  
     //carry_object(__DIR__"obj/evil-eye");   
     carry_object(__DIR__"obj/evil-pants")->wear();
     carry_object(__DIR__"obj/evil-cloak")->wear();  
     carry_object(__DIR__"obj/fire-fruit");
} 
void heal()
{ 
  if(query("hp") > query("max_hp")) return;  
  add("hp",600); 
  return;
}   
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{ 
        object me=this_player();
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0: 
                        message_vision(HIR"\n���]��������$N���ݤf��F�U�h�I\n"+NOR,me);
                        me->receive_damage("hp",300);
                        this_object()->kill_object(environment(me));
                        break;
                case 1: 
                        this_object()->kill_object(environment(me));
                        break;
        }
} 
/*int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*10) > tdex+tcon)
    {
      message_vision(HIR"\n$N"+HIW"�i�}����A�������E�@�Ѯ�l�E�E\n"     
                    +HIC"���X�I�I�y"+HIB"�����]�y"+HIC"�z�����a\n"
                    +HIC"���V$n�A�y��"+HIR"�I�������ˡI\n"+NOR,me,target);
      target->receive_damage("hp",400+random(150), this_object());
      return 1; 
    }
    else
    {
      message_vision(HIR"\n$N"+HIW"��M����"+HIG"�C��"+HIW"�A�f�������E���@�ѯ�q�E�E\n" 
                    +HIW"�Q�X�I�����ʪ�"+HIR"���V"+HIW"�L�����N�V$n�A\n"
                    +HIW"�y��"+HIR"�Y�����N�ˡI\n"+NOR ,me,target);      
      target->receive_damage("hp",300+random(100), this_object());
      return 1;
    }
}  
*/int special_attack_two(object me, object target, int hitchance)
{ 
  if(!me) return 0;
  if(me->is_busy()) return 0;
  if(random(hitchance*40) > this_player()->query_str()*2)
  if(!random(9))
  { 
    me->start_busy(2);
    target->add_busy(1);
    message_vision(HIM"\n�@�}�ѷn�a��.....�@�D�j�P������q�a�_«�X�A�����¶��$N\n\n"NOR,me);
    call_out("do_shot",2,me);
    return 1;
  }
  return 0;
}

void do_shot(object me)
{ 
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision(HIR"\n���]"+HIW"����@�}�I�L�ƪ�"+HIC"��q�y"+HIW"�|�B�����A�¤O�L�a�I\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]))
    {
      damage = random(500)+250;
      message_vision(HIW"$N�Q"+HIC"��q�y"+HIW"�����A�����֤F�@�j�b���ͩR�I+"HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
    }
  }
  me->start_busy(3);
  return;
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
 HIC"\n\t\t\t  "+ob->name(1)+"�P����^���j�Ԥ��]�Ʀʦ^�X��A�������V���]�����F�I�I\n\n"+NOR   
    HIR"\n\t\t       �@�x���H�F���]�����F�`���A���]���n�˦a�A���F�q�}�H���`���e�X�I�I\n\n"+NOR   
    HIW"\n\t\t\t\t\t�@�ۤƬ��L�ƥե��A�}���ӳu�I�I\n\n"+NOR,users());  
   //HIG"\n\t\t\t\t\t �����b�V���F�t�a�w�w�m��ù��n\n\n"+NOR
        ob->add("popularity",8); 
        ::die();
        return;
}

