#include <ansi.h>
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

  set_skill("hammer",100);
  set_skill("dodge",40);
  set_skill("parry",50);
  set("chat_chance", 20);
  set("chat_msg", ({
"�Ѯv�ձN�@���N�����K���u��v�a�@�n���J�@�Ǫ����c���C\n",
(: command("sweat") :),
(: command("hmm") :),
}));

  set("talk_reply","�Q�n�ײz�Z���άO�˳ƶܡH ��F��浹�ʹN��F�I (give master <���~ id>)\n");
  setup();
  carry_object(__DIR__"hammer")->wield();
}

int accept_object(object who, object ob)
{
  if( ob->query_amount() > 0 )
  {
    command("thank");
    return 1;
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
  this_object()->start_busy(2);
  call_out("fixing",2,ob,who);

  return 1;
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
    command("say ���A�s�ڰ��F�A�ӧ�ڧa�C");
    command("give "+who->query("id")+" "+ob->query("id"));
    return;
  }

  if(level > 90) command("say �o���N��X�G���a�F���A�S���Y�A�ݭͪ���q�C");
    else if(level > 60) command("say �a�o���Y�����A���L�����סC");
           else if(level > 30) command("say �o�F���٤����a�o���Y�����A�X���ײz�]�O�n���C");
                  else command("say �o���N��ˬO�S����l�a�A�A�n�׭ͫK���z�ӿ�C");

  ob->set_durable(100);
  who->add("bank/past",-price);
  command("say ��F�A�צn�F�A���´f�U�C");
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

   tell_object(ob,HIC"[�]���A���@�c�h�ݡA�A�o��F�B�~�� 1 �I�n��!!]\n"NOR);
   ob->add("popularity",1);
   ::die();
   return;
}

