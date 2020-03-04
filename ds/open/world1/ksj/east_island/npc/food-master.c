#include <ansi.h>
inherit NPC;

void create()
{
  set_name("�Ʋz�K�H", ({ "food master","master"}));
  set("long",@long
��۰��b��������~�Ʋz�v�šA�Y�W�j�ۥզ��Y�y�A��}�W���a�B�z
�ۭ����A�L�O���l�̻s�@�Ʋz���Ĥ@���ȡA�������s�L�y�K�H�z�A
���ȥN��L���H�Q���ˡA�]��ܥL��Ʋz���H���P����C
long);      
  set("gender", "�k��" );
  set("age",42);
  set("level",35);
  set("race","human");
  set("no_fight",1);
  set("talk_reply","�z�n��Q�Y�I����H�аѦ���W�����(menu)\n");
  set("chat_chance", 5);
  set("chat_msg", ({
      "�Ʋz�K�H��ۮ�W���C�����A���D�G�s�A������{���Ʋz��\n",
      "�Ʋz�K�H���ή̰ʡA����ֳt�a�ްʮƲz�Ψ�A�ݱo�A�ؤ��v���C\n",
     }));
  setup();
  add_money("coin",100);
}

void init()
{
  object ob;
  ::init();
  if( interactive(ob = this_player()) && !is_fighting() ) 
  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
  add_action("do_order","order");
}

void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;
  switch( random(2) ) 
  {
    case 0:
         say( "�Ʋz�K�H�@����۳��פ@�仡�D�G�ȤH�z�n���w����{�C\n");
         break;
    case 1:
         say( "�Ʋz�K�H�s�y���D�G�ȤH�o��Ч���\n");
         break;
  }
}

int do_order(int arg)
{
  object me,ob;
  me = this_player();
  ob = this_object();

  if( !arg )
    return notify_fail("�A�n�I�����O�H(order)\n");
  if( me->query_temp("is_busy/eat_food"))
    return notify_fail("�A�w�g�I�F�F��Y�F�C\n");

  switch(arg) 
  {
    case "1":
          if( !me->can_afford(30) )
            return notify_fail("�A���W���������C(30���)\n");
          me->receive_money(-30);
          command("nod "+me->query("id"));
          me->disable_player_cmds("�A���b�Y�F��C\n");
          me->set_temp("is_busy/eat_food","�A���b�Y�F��C");
          me->start_busy(6);
          message_vision("�Ʋz�K�H���D�G���W�N�n�A�еy�ݡC\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"��l",me);
          call_out("eatting",4,me);
          call_out("finish",6,"��l",me);
          me->receive_heal("hp",50);
          me->receive_heal("ap",30);
          me->receive_heal("mp",10);
          break;

    case "2":
          if( !me->can_afford(50) )
            return notify_fail("�A���W���������C(50���)\n");
          me->receive_money(-50);
          command("nod "+me->query("id"));
          me->disable_player_cmds("�A���b�Y�F��C\n");
          me->set_temp("is_busy/eat_food","�A���b�Y�F��C");
          me->start_busy(6);
          message_vision("�Ʋz�K�H���D�G���W�N�n�A�еy�ݡC\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"�K�l",me);
          call_out("eatting",4,me);
          call_out("finish",6,"�K�l",me);
          me->receive_heal("hp",100);
          me->receive_heal("ap",50);
          break;

    case "3":
          if( !me->can_afford(20) )
            return notify_fail("�A���W���������C(20���)\n");
          me->receive_money(-20);
          command("nod "+me->query("id"));
          me->disable_player_cmds("�A���b�Y�F��C\n");
          me->set_temp("is_busy/eat_food","�A���b�Y�F��C");
          me->start_busy(6);
          message_vision("�Ʋz�K�H���D�G���W�N�n�A�еy�ݡC\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"�Y�ާl",me);
          call_out("eatting",4,me);
          call_out("finish",6,"�Y�ާl",me);
          me->receive_heal("hp",30);
          me->receive_heal("ap",20);
          me->receive_heal("mp",10);
          break;

    case "4":
          if( !me->can_afford(40) )
            return notify_fail("�A���W���������C(40���)\n");
          me->receive_money(-40);
          command("nod "+me->query("id"));
          me->disable_player_cmds("�A���b�Y�F��C\n");
          me->set_temp("is_busy/eat_food","�A���b�Y�F��C");
          me->start_busy(6);
          message_vision("�Ʋz�K�H���D�G���W�N�n�A�еy�ݡC\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"���Ѥ�",me);
          call_out("eatting",4,me);
          call_out("finish",6,"���Ѥ�",me);
          me->receive_heal("hp",80);
          me->receive_heal("ap",40);
          break;

    case "5":
          if( !me->can_afford(25) )
            return notify_fail("�A���W���������C(25���)\n");
          me->receive_money(-25);
          command("nod "+me->query("id"));
          me->disable_player_cmds("�A���b�Y�F��C\n");
          me->set_temp("is_busy/eat_food","�A���b�Y�F��C");
          me->start_busy(6);
          message_vision("�Ʋz�K�H���D�G���W�N�n�A�еy�ݡC\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"����Ѱ�ù",me);
          call_out("eatting",4,me);
          call_out("finish",6,"����Ѱ�ù",me);
          me->receive_heal("hp",60);
          me->receive_heal("ap",15);
          break;

    case "6":
          if( !me->can_afford(60) )
            return notify_fail("�A���W���������C(60���)\n");
          me->receive_money(-60);
          command("nod "+me->query("id"));
          me->disable_player_cmds("�A���b�Y�F��C\n");
          me->set_temp("is_busy/eat_food","�A���b�Y�F��C");
          me->start_busy(6);
          message_vision("�Ʋz�K�H���D�G���W�N�n�A�еy�ݡC\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"�Q�N",me);
          call_out("eatting",4,me);
          call_out("finish",6,"�Q�N",me);
          me->receive_heal("hp",150);
          me->receive_heal("ap",30);
          break;

    case "7":
          if( !me->can_afford(50) )
            return notify_fail("�A���W���������C(50���)\n");
          me->receive_money(-50);
          command("nod "+me->query("id"));
          me->disable_player_cmds("�A���b�Y�F��C\n");
          me->set_temp("is_busy/eat_food","�A���b�Y�F��C");
          me->start_busy(6);
          message_vision("�Ʋz�K�H���D�G���W�N�n�A�еy�ݡC\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"�����Q�N",me);
          call_out("eatting",4,me);
          call_out("finish",6,"�����Q�N",me);
          me->receive_heal("hp",100);
          me->receive_heal("ap",50);
          break;

    case "8":
          if( !me->can_afford(10) )
            return notify_fail("�A���W���������C(10���)\n");
          me->receive_money(-10);
          command("nod "+me->query("id"));
          me->disable_player_cmds("�A���b�Y�F��C\n");
          me->set_temp("is_busy/eat_food","�A���b�Y�F��C");
          me->start_busy(6);
          message_vision("�Ʋz�K�H���D�G���W�N�n�A�еy�ݡC\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"��Ĭ���z",me);
          call_out("eatting",4,me);
          call_out("finish",6,"��Ĭ���z",me);
          me->receive_heal("mp",30);
          break;

    case "9":
          if( !me->can_afford(10) )
            return notify_fail("�A���W���������C(10���)\n");
          me->receive_money(-10);
          command("nod "+me->query("id"));
          me->disable_player_cmds("�A���b�Y�F��C\n");
          me->set_temp("is_busy/eat_food","�A���b�Y�F��C");
          me->start_busy(6);
          message_vision("�Ʋz�K�H���D�G���W�N�n�A�еy�ݡC\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"�Ǩ�",me);
          call_out("eatting",4,me);
          call_out("finish",6,"�Ǩ�",me);
          me->receive_heal("mp",30);
          break;

    case "10":
          if( !me->can_afford(100) )
            return notify_fail("�A���W���������C(100���)\n");
          me->receive_money(-100);
          command("nod "+me->query("id"));
          me->disable_player_cmds("�A���b�Y�F��C\n");
          me->set_temp("is_busy/eat_food","�A���b�Y�F��C");
          me->start_busy(6);
          message_vision("�Ʋz�K�H���D�G���W�N�n�A�еy�ݡC\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"�M�s",me);
          call_out("eatting",4,me);
          call_out("finish_d",6,"�M�s",me);
          me->receive_heal("ap",100);
          me->receive_heal("mp",200);
          break;

    case "11":
          if( !me->can_afford(130) )
            return notify_fail("�A���W���������C(130���)\n");
          me->receive_money(-130);
          command("nod "+me->query("id"));
          me->disable_player_cmds("�A���b�Y�F��C\n");
          me->set_temp("is_busy/eat_food","�A���b�Y�F��C");
          me->start_busy(6);
          message_vision("�Ʋz�K�H���D�G���W�N�n�A�еy�ݡC\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"�N�s",me);
          call_out("eatting",4,me);
          call_out("finish_d",6,"�N�s",me);
          me->receive_heal("ap",140);
          me->receive_heal("mp",250);
          break;

    case "12":
          if( !me->can_afford(150) )
            return notify_fail("�A���W���������C(150���)\n");
          me->receive_money(-150);
          command("nod "+me->query("id"));
          me->disable_player_cmds("�A���b�Y�F��C\n");
          me->set_temp("is_busy/eat_food","�A���b�Y�F��C");
          me->start_busy(6);
          message_vision("�Ʋz�K�H���D�G���W�N�n�A�еy�ݡC\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"���s",me);
          call_out("eatting",4,me);
          call_out("finish_d",6,"���s",me);
          me->receive_heal("ap",150);
          me->receive_heal("mp",300);
          break;

    case "13":
          if( !me->can_afford(300) )
            return notify_fail("�A���W���������C(300���)\n");
          me->receive_money(-300);
          command("nod "+me->query("id"));
          me->disable_player_cmds("�A���b�Y�F��C\n");
          me->set_temp("is_busy/eat_food","�A���b�Y�F��C");
          me->start_busy(6);
          message_vision("�Ʋz�K�H���D�G���W�N�n�A�еy�ݡC\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"�¦̤j�u�C",me);
          call_out("eatting",4,me);
          call_out("finish_d",6,"�¦̤j�u�C",me);
          me->receive_heal("ap",300);
          me->receive_heal("mp",600);
          break;

    case "14":
          if( !me->can_afford(180) )
            return notify_fail("�A���W���������C(180���)\n");
          me->receive_money(-180);
          command("nod "+me->query("id"));
          me->disable_player_cmds("�A���b�Y�F��C\n");
          me->set_temp("is_busy/eat_food","�A���b�Y�F��C");
          me->start_busy(6);
          message_vision("�Ʋz�K�H���D�G���W�N�n�A�еy�ݡC\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"�س߿N",me);
          call_out("eatting",4,me);
          call_out("finish",6,"�س߿N",me);
          me->receive_heal("hp",400);
          me->receive_heal("ap",80);
          break;

    case "15":
          if( !me->can_afford(180) )
            return notify_fail("�A���W���������C(180���)\n");
          me->receive_money(-180);
          command("nod "+me->query("id"));
          me->disable_player_cmds("�A���b�Y�F��C\n");
          me->set_temp("is_busy/eat_food","�A���b�Y�F��C");
          me->start_busy(6);
          message_vision("�Ʋz�K�H���D�G���W�N�n�A�еy�ݡC\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"�R�R��",me);
          call_out("eatting",4,me);
          call_out("finish",6,"�R�R��",me);
          me->receive_heal("hp",400);
          me->receive_heal("ap",80);
          break;

    case "16":
          if( !me->can_afford(250) )
            return notify_fail("�A���W���������C(250���)\n");
          me->receive_money(-250);
          command("nod "+me->query("id"));
          me->disable_player_cmds("�A���b�Y�F��C\n");
          me->set_temp("is_busy/eat_food","�A���b�Y�F��C");
          me->start_busy(6);
          message_vision("�Ʋz�K�H���D�G���W�N�n�A�еy�ݡC\n",me);
          call_out("cooking",1,me);
          call_out("giving",2,"�e����",me);
          call_out("eatting",4,me);
          call_out("finish",6,"�e����",me);
          me->receive_heal("hp",500);
          me->receive_heal("ap",200);
          break;

    default:
          write("�S���A�n�I�����H\n");
          break;
  }
  return 1;
}

void cooking(object me)
{
  if(!me) return;
  tell_object(me,HIG"�Ʋz�K�H�ΫW�������⨳�t�N�����B�z�n�A�A�H�¼�����k�i��i�աC\n"NOR);
  return;
}

void giving(string arg,object me)
{
  if(!me) return;
  message_vision("�Ʋz�K�H�N"HIW+arg+NOR"�ݨ�$N�����e�C\n",me);
  return;
}

void eatting(object me)
{
  if(!me) return;
  message_vision(HIG"$N���F�U�ӡA�Ӳӫ~�����I�������C\n" NOR,me);
}

void finish(string arg,object me)
{
  if(!me) return;
  message_vision("$N�z�z�����a�N"HIW+arg+NOR"�Y�o�@�I���ѡC\n",me);
  me->delete_temp("is_busy/eat_food");
  me->enable_player_cmds();
}

void finish_d(string arg,object me)
{
  if(!me) return;
  message_vision("$N�N"HIW+arg+NOR"�C�C�ܧ��F�C\n",me);
  me->delete_temp("is_busy/eat_food");
  me->enable_player_cmds();
}
