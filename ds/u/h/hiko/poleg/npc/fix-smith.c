#include <ansi.h>
inherit NPC;

void create()
{
  set_name("�K�K�v��", ({ "fix smith","smith" }) );
  set("gender", "�k��" );
  set("long",@LONG
�O�Өɦ��ܦn���n�A�����K�K�A�ڻ��O�X�۩�ɿ�
�Ѯv�Ū��U�A�ثe�ۤv�}�~���A�ӭn�תZ�����覡
�O[give smith �Z��<id> ]�H�ΥI�X�@�ǿ��C
LONG
);
  set("title",HIC"�ײz����"NOR);
  set("age",51);
  set("level",50);
  set("race","human");
  set("chat_chance", 20);
  set("chat_msg", ({
"�K�K�v�է�N�����K���Τ⤤�l�l�V���A�o�X�y��z���n���C\n",
"�K�K�v�Ż��ۡJ�n�����K�޳N���ܡA�ڷɿ����v�Ť~�O�̱j���r�C\n",
(: command("sweat") :), 
(: command("hmm") :),
}));
set("talk_reply","�Q�n�ײz�Z���άO�˳ƶܡH ��F��浹�ʹN��F�I (give smith �Z�� <id>)\n");
  setup();
  carry_object("/open/world1/wilfred/newbie/hammer")->wield();
}

int accept_object(object who, object ob)
{
        if( this_object()->is_fighting() )
                {
                command("say Sorry�ڲ{�b�S��!"); // add by alickyuen.
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

  message_vision(NOR+YEL"\n�K�K�v�ջ��R"NOR"$n"NOR+YEL"���ײz�O�O"HIC+chinese_number(price)+NOR+YEL"�T�j���C\n\n"NOR,this_object(),ob);
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

message_vision(HIR"$N�{���e�j�۹D�J�v�š��ڧ������F�o�����K�޳N���ϩR�F�C\n"NOR,this_object() );
      
tell_object(ob,HIC"[�A�W�[�F 1 �I�n��!!]\n"NOR);
   ob->add("popularity",1);
   ::die();
   return;
}



