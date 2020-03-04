#include <ansi.h>
#include <combat.h>     
inherit NPC;

void create()
{
  set_name("���K�Ѯv��", ({ "EQ master","master" }) );
  set("gender", "�k��" );
  set("long",@LONG
���몺�Ѯv�աA�����a�����Z���θ˳ơA���L��
�̳���b�u�ɶ����ײz�n [�ݭn�@�I�N��]�C
LONG
);
  set("title",HIC"�ײz�j�v"NOR);
  set("age",74);
  set("level",80);
  set("race","human");
  set("chat_chance", 20);
  set("chat_msg", ({
"�Ѯv�ձN�@���N�����K���u��v�a�@�n���J�@�Ǫ����c���C\n",
(: command("sweat") :),
(: command("hmm") :),
}));
  set_temp("apply/hit",50); // add by ksj
  set_temp("apply/dodge",50); // add by ksj
  set("talk_reply","�Q�n�ײz�Z���άO�˳ƶܡH ��F��浹�ʹN��F�I (give master <���~ id>)\n");
  setup();
  carry_object(__DIR__"hammer")->wield();
}

int accept_object(object who, object ob)
{
        if( this_object()->is_fighting() )
                {
                command("say �ڨS�Ű�!"); // add by alickyuen.
                return 0;
        }
  if( ob->query_amount() > 0 )
  {
    command("thank");
    return 1;
  }
        if( ob->query("no_repair") )
        {
                command("say �o��F��S��k�ײz��...�t�V���H�a~");
                return notify_fail("");
        }
  if( ob->query("secured") ) 
  {
    command("say �F��Х��Ѱ��O�s���A�A�浹�͡C");
    return notify_fail("");
  }

  message_vision(NOR"$N"NOR"���X"+ob->query("name")+NOR"("+ob->query("id")+")��$n�C\n"NOR,who,this_object());

  if( !ob->query("skill_type") && !ob->query("armor_type") )
  {
    command("say �ͤ��|�ײz�o�تF��A�z�t�а����a�C");
    return notify_fail("");
  }

  if(this_object()->is_busy())
  {
    command("say ���٦b���A�бz���@�U�C");
    return notify_fail("");
  }

  command("say �еy���A�Ͱ��W�ײz�C");
  this_object()->start_busy(4);
  call_out("fixing",5,ob,who);

  return 1;
}
// add �ĤO�@�� by ksj
int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(10))
  {
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  return 0;
}

void fixing(object ob, object who)
{
  int price, level;

  if(!who || environment(who) != environment(this_object()))
  {
    command("drop all");
    return;
  }

  level = 100 - ob->query_durable();
  if(ob->query("value") == 1) price = level * ob->query("init_value") / 100;
    else price = level * ob->query("value") / 100;
 message_vision(NOR+YEL"\n���K�Ѯv�ջ��R"NOR"$n"NOR+YEL"���ײz�O�O"HIC+chinese_number(price)+NOR+YEL"�T�j���C\n\n"NOR,this_object(),ob);
  if(who->query("bank/past") < price)
  {
    command("say �z�n���I���X�o�����a�A���A�s�ڰ��F�A�ӧ�͡C");
    command("give "+who->query("id")+" "+ob->query("id"));
    return;
  }

  if(level > 90) command("say �o���N��X�G���a�F���A�S���Y�A�ݭͪ���q�C");
    else if(level > 60) command("say �a�o���Y�����A���L�����סC");
           else if(level > 30) command("say �o�F���٤����a�o���Y�����A�X���ײz�]�O�n���C");
                  else command("say �o���N��ˬO�S����l�a�A�A�n�׭ͫK���z�ӿ�C");

  ob->set_durable(100);
  who->add("bank/past",-price);
  command("say ��F�A�צn�F�A���´f�U�A���|�q�z���Ȧ�̦��C");
  command("give "+who->query("id")+" "+ob->query("id"));
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
HIR"\n�i�K�K���|�j�K�K�Ѯv�ճQ�i�c��"+ob->name(1)+"�����F�C\n\n"NOR,users());

   tell_object(ob,HIC"[�]���A���@�c�h�ݡA�A�o��F�B�~�� 3 �I�n��!!]\n"NOR);
   ob->add("popularity",3);   
   ::die();
   return;
}
