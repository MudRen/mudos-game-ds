#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�x��",({"soldier's doctor","doctor"}) );
        set("long","\n");
        set("age",40);
        set("race","�H��");
        set("level",25);
        set("attitude", "peaceful");
        set("gender", "�k��" );
        set("chat_chance",6);
        set_skill("unarmed",80); 
        set_skill("dodge",80);
        set_skill("parry",80); 
        set_skill("dagger",80);
        set_temp("soldier",1);
        setup();
        add_money("coin", 1000);
}

void init()
{ 
  object me=this_player(),ob=this_object(),obj,env;
  env = environment(ob);
  ::init();
  if( !me->query_temp("soldier") ) return;
  command("say �A�n�����ˤF..");
  message_vision("$N��$n�v���F�ˤf�E\n",ob,me); 
  return;
} 

int accept_object(object who, object ob)
{ 
  if( ob->query("id") == "secret bottle" && who->query_temp("ask_doctor") && !this_object()->query_temp("no_give") )
  {
    command("say �o�O..?");
    call_out("poison",2,this_object()); 
    destruct(ob);    return 1;
  }

  tell_object(who,this_object()->name(1)+"���G��"+ob->name(1)+"�ä��P����E\n");
  return notify_fail("");
  return 1;
}

void poison()
{
  object me=this_player(),ob=this_object();
  switch( me->query_temp("ask_doctor") ){
        case 1:
          message_vision(YEL"$N��p�~�l���F�_�ӡA�J�Ӫ��@�F�@�|�E\n"NOR,ob);
          me->add_temp("ask_doctor",1); 
          call_out("poison",6,this_object());
        break;
        case 2:
          command("ack");
          command("say �o�F��O�r�İ�!!"); 
          me->add_temp("ask_doctor",1); 
          call_out("poison",2,this_object());
        break;
        case 3:
          command("say �A�쩳�O�q���̮���o��M�I���F��..");
          message_vision(YEL"$N����o�~�l���g�L�A�@���@�Q������$n���F�E\n"NOR,me,ob);          me->add_temp("ask_doctor",1); 
          call_out("poison",4,this_object());
        case 4:   
          command("say �o�i���o�F�F..�ڥh��N�x���i�o���..");
          command("say �A�N�Q��k����Ӫ���a");
          me->delete_temp("ask_doctor"); 
          me->add_temp("kill_cook",1);
          command("south"); 
          destruct(ob);
        break;            
  }
 return;
}
