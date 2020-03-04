#include <ansi.h>
inherit NPC;

int quest();
void power();

void create()
{
  set_name("�Z��", ({ "military" }) );
  set("gender", "�k��" );
  set("long",@LONG
�L�O�@��n�Z�������H�A�T�Q���ɺɱo�U�a�����Z�Ǥ���n�A�E�ܶ��F�����~�A
�]�L�p���K�ߩ�Z�ǡA�ҥH�~���̵��F�L�y�Z���z���ٸ��A���`�`�O�ޥL���Z��
�A�u��m�W�ϦӵL�H�O�o�C�L���`�`�O�H�Z�|�͡A���ڲn�֡A�`�`�s�ܤG�T�Q��
�s�ӭ������C
LONG
);      
  set("age",40);
  set("level",43+random(4));
  set("exp",40000+random(3000));
  set("race","human");

  set_skill("unarmed",90);
  set_skill("parry",60);
  set_skill("dodge",70);
  set_skill("bagi_fist",80);
  set_skill("bagi_force",51);
  set_skill("horse-steps",96);
  set_skill("fogseven",40);
  set_skill("moon_force",80);
  set_skill("buddha-force",80);
  set_spell("god-fire",81);
  set("addition/wit",-3);
	set("class1", "���Z��");
	set("class2", "���Z��");

  set("chat_chance", 30);
  set("chat_msg", ({
"�Z���w�w�����_�B�k�A�C�C�����F�@�M���C\n",
(: command("say �Z�Ǥ��D�L�a�L�ɡA�o�@�W�٦��۷�h�����W���Z�ǡA�����s�a�A�O���ͥ����@�C") :),
(: quest :),
(: command("exert bagi_fist") :),
(: command("exert fogseven") :),
(: command("exert buddha-force armor") :),
(: command("exert bagi_force power_up") :),
(: command("exert horse-steps twine-power") :),
}));

  set("chat_chance_combat",80);
  set("chat_msg_combat", ({
(: power :),
}) );
  set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
  setup();
  add_money("coin",5000);
  carry_object(__DIR__"wp/wp1")->wield();
  set("mirror_number",7);
  call_out("re_quest",900);
}

void init()
{
  object me;
 
  ::init();
  if( interactive(me = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 1, me);
  }
  add_action("do_no_ask","ask");
}

void greeting(object me)
{
  if( !me || environment(me) != environment() ) return;
  command("say �o��" +RANK_D->query_respect(me)+ "�A�Q��ڹL�G�۶ܡH");
  return;
}

int do_no_ask()
{
  write("�Х� say <��ͪ��覡> �Ө��o�һݱ����C\n");
  return 1;
}

int quest()
{
  object ob = this_object();

  if(ob->query_temp("pass_quest"))
    command("say �������I�W������" +ob->query_temp("pass_quest_who")+ "�u����A�u���h�F�F�A�����A�ܦn�A�ܦn�C");
  else command("say ���_���H�����H�تA���ơA�ڷQ�Q.... �ܤ֭n������ѤW�j�ͪ��y�I�G�z�A�~��X��C");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if(strsrch(str,"�Z") !=-1)
    command("say �ڥͥ��̦n�Z�ǡA�A��ڰݪZ�A�u�������A�ӨӡA�ڭ̽תZ�ܰs�A�Q�װQ�צU�a�����Z�Ǫ��߱o�C");
  if(strsrch(str,"����") !=-1)
    command("say �񲴷�N�����A�Z�Ǥ��̬��K�������ݡA�ڦU�����Z�ǬҦ��A�y�A���K���Z�ǳդj��`�A�Z�O�L����ΡH");
  if(strsrch(str,"�K��") !=-1)
  {
    if(strsrch(str,"��") !=-1)
      command("say �Ҧ��򥻤K�����ۧ��O����y�K���p�[�����Z�z�o���ѤW�A�u�O�����{�U�y�����B�C");
    else if(strsrch(str,"�p�[�����Z") !=-1)
         {
           command("say �o���Ѥ��o�F�ڡA���Y�ƦܰO���F�v�`�H���K�����۩O�A�p�G�A�ର�ڧ�쥦�A�ڦ۷����S�¡C");
           me->set_temp("get_bagi_book",1);
         }
         else command("say �Z�Ǥ��̬��K�������ݡA�ڦU�����Z�ǬҦ��A�y�A���K���Z�ǳդj��`�A�S�Z�O�L����ΡH");
  }
  if(strsrch(str,"�r��w���s") !=-1)
  {
    ob->add_temp("msg_index",1);
    switch(ob->query_temp("msg_index"))
    {
      case 1 : command("hehe");
               command("say ����.. �r��w���s�ä��O�K�����̱j�����۩O...");
               break;
      case 2 : command("hehe");
               command("say �d�����Ѩ�d�F�@��� .... ���L�S���a���q�����ǵ����Ѥ娺�p�l.. �����F�A�ӨӡA�ܰs�I");
               break;
      default : command("hmm");
                command("say �ӨӡA�ܰs�C");
                break;
    }
  }
  return;
}

int accept_object(object who, object ob)
{
  object only_check;
  if( ob->query_amount() > 0 )
  {
    message_vision("$N���X"+chinese_number(ob->query_amount())+"�T"+ob->name(1)+"("+ob->query("id")+")��$n�C\n",who,this_object());
    command("say �ڤ��ݭn"+ob->name(1)+"�A�A���^�h�a�C");
    call_out("no_give_money",1,who,ob,ob->query_amount());
    return 1;
  }
  if(ob->query("id") == "bagi book")
  {
    command("flop");
    command("really");
    if(who->query_temp("get_bagi_book"))
    {
      who->delete_temp("get_bagi_book",1);
      command("say �A�u�O��²��A�n�A�ڻ��L�n���A���S�A�Ц��U�o�ӧa�C");

      only_check = filter_array( children(__DIR__"obj/obj1"), (: clonep :) );
      if(sizeof(only_check) > 0)
      {
        this_object()->receive_money(5000);
        command("give " +who->query("id")+ " coin");
      }
      else call_out("fight_you",1,0);
    }
    else command("say �u�P�§A�A�������I�I���ڴN���Ȯ𪺦��U�F�C");
    message_vision("$N����N$n���ð_�ӤF�A�y�W�S�X�D�`�����������C\n",this_object(),ob),
    destruct(ob);
    return 1;
  }
  if( ob->query("victim_name") == HIM"�I�G"NOR )
  {
    if(this_object()->query_temp("pass_quest"))
    {
      who->start_busy(8);
      call_out("talk_msg",1,0);
      set_temp("pass_quest_who",who->name(1));
      return 1;
    }
    command("spank "+who->query("id"));
    command("say �G�M���x�ѡA�ӨӡA�ڰe�A�ӪF��A���̥��B�͡C");
    destruct(ob);
    new(__DIR__"obj/obj15")->move(this_object());
    command("give " +who->query("id")+ " mirror");
    set_temp("pass_quest",1);
    set_temp("pass_quest_who",who->name(1));
    return 1;
  }
  command("�e�ڪF��ڡH�h�§A�F�A���L�ڪ��[��b���a�A�ˤ]���ʤ���A�A�٬O���^�h�a�C");
  write("["+this_object()->name(1)+"��"+ob->name(1)+"�ä��P����]\n");
  return notify_fail("");
}


int re_quest()
{
  this_object()->delete_temp("pass_quest");
  this_object()->delete_temp("pass_quest_who");
  this_object()->delete_temp("item_give");
  this_object()->delete_temp("item_give_who");
  this_object()->delete_temp("msg_index");
  call_out("re_quest",3600);
  return 1;
}

int talk_msg(int index)
{
  switch(index)
  {
    case 0 : command("spank "+this_player()->query("id"));
             break;
    case 1 : command("say �G�M���x�ѡA�ڳo�̤]�S����F��i�H���A���A�o�˧a�A�ڨӧU�A���ɯ�O�C");
             break;
    case 2 : message_vision("$n�b$N�I�ᥴ�F�@�x�A�u��$N�y�z�z���@�n�A�R�F�@�f�¦�C\n",this_player(),this_object());
             break;
    case 3 : command("say �ڥ��q�A���y���աz�y�F�I�z�G�ߡA�A�o�f�¦�O�ҲֻP���������Ҳֿn���y�g��z�A�{�U�ڤv�N���G�X�A�v�L�jê�C");
             break;
    case 4 : write("\n\t[�Aı�o��涶�Z�A�b�Z�ǳy�ڤ譱���y�ڤS��[�i�@�h�C]\n<�A���g��ȼW�[�F�I>\n\n");
      this_player()->add("exp",(this_player()->query("level") * 500) + (random((this_player()->query("level")*100))+1000));
             break;
    case 5 : command("say ���L.....");
             break;
    case 6 : command("say �o��@�u�O�Ȯɪ��A�]���y�g��z�O���_�ֿn���A���b�ƭӮɨ�����A�A���餺�S�|��n�۷�{�ת��y�g��z�A�o�]�O���i�`�󪺨ơC");
             break;
  }
  if(index < 6) call_out("talk_msg",2,++index);
  return 1;
}

int fight_you(int index)
{
  object me = this_player(), ob = this_object();

  me->start_busy(2);
  switch(index)
  {
    case 0 : command("hmm");
             break;
    case 1 : command("say ���L....");
             break;
    case 2 : command("say �o�_���N�o�˥��ժ��e���A�A��b�Ӥ��̤ߡA�ӨӨӡA�����ڬݬݧA���S����O�o�쥦�I�I");
             break;
    case 3 : command("say ���U�D��ӧa�I�I�������I");
             command("cac");
             write(HIW"[�A�ݦ��H�p���K�ߩ�Z�ǡA���H�S���n�A�ˤ]���ԩڵ��L���n�D]\n"NOR);
             break;
    case 4 : ob->kill_ob(me);
             me->set_temp("give_book_fight",1);
             break;
  }
  if(index < 4) call_out("fight_you",2,++index);
  return 1;
}

void die()
{
  object me;
  if( !me = query_temp("last_damage_from") )
  me = this_player(1);
  if( !me )
  {
    ::die();
    return;
  }
  if(me->query_temp("give_book_fight"))
  {
    new(__DIR__"obj/obj1")->move(this_object());
    me->delete_temp("give_book_fight");
    message_vision(HIW"\n$n�����j���A���D�G�y�����A�����I�G�M�O����O���A�ڪA�F$N�աI�z\n\n",me,this_object());
    message_vision(WHT"����H�Y����}�@�B�A�۵��j���C\n"NOR,me);
    me->remove_all_killer();
    command("give " +me->query("id")+ " final book");
    command("say ���ѬöQ���`�A�A���h����i�n���[�Q�ΡC");
    message_vision(HIY"\n\t����$N�K�����ӥh�A�uť�o�����ǨӰ}�}�q�n�A�j���b�u�u���F���줤�C\n\n",this_object());
    destruct(this_object());
  }
  else
  {
   message("world:world1:vision",
HIY"\n\t�Z���b���e�j���D�G �������I" +me->name(1)+ "�A�u���@��A�ڪA�F�A�աI�I\n\n"NOR,users());

    tell_object(me,HIG"[�A�o���B�~�� 4 �I�n��I�I]\n"NOR);
    me->add("popularity",4);
    ::die();
  }
  return;
}

void power()
{
  switch( random(7) )
  {
    case 0 : command("say �Ӫ��n!! ������!!");
             break;
    case 1 : command("exert bagi_fist");
             break;
    case 2 : command("exert bagi_fist");
             break;
    case 3 : command("exert bagi_fist");
             break;
    case 4 : command("cast god-fire");
             break;
    case 5 : command("cast god-fire");
             break;
    case 6 : command("exert moon_force moon-arc");
             break;
  }
  return;
}

int receive_damage(string type,int cost)
{
  object ob = this_object(), me = this_player();

  if(ob->is_busy()) ob->add_busy(-10);
  if(!random(6) && ob->is_fighting() && me != ob)
  {
    message_vision(HIG"\n$N�ϥX�F�۳Ъ����ޡA��B���u�A�H�̤Q�r�k�N$n����í�������I\n\n"NOR,ob,me);
    me->start_busy(1);
    power();
  }

  ::receive_damage(type,cost,me);
  return 0;
}

void no_give_money(object who, object ob, int index)
{
  command("give " +who->query("id")+ " " +index+ " " +ob->query("id"));
}

