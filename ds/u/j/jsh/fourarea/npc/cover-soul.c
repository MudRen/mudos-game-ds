#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"�u�@��"HIW"��"HIR"�F"NOR,({"cover soul","soul"}) );
  set("long",
HIC"\n�u�@�̬O�u�ۥ@�ɤ��ۭn�몺�j��\n"NOR
HIB"\n�H�������������J�H�����@��\n" NOR);
  set("race", "�H��");
  set("unit","��");
  set("age",1240);
  set("level",60);
  set("attitude", "heroism");
  set("limbs", ({ "�Y��", "����","�ݤf","�}","��","�I" }) );
  set("addition_armor",250);
  set("addition_damage",200);
  set("Merits/bar",5);
  add("apply/hit",60);
  setup();
  carry_object(__DIR__"obj/cover-sword")->wield();
}

void init()
{
  ::init();
  add_action("do_guard","go");
}

int do_guard(string arg)
{
  if(!userp(this_player())) return 0;
  if(arg == "enter")
  {
    message_vision(HIC"$n"HIR"�i�}����N$N�פF�U�ӡI\n"NOR,this_player(),this_object());
    write(HIG"�n�i�J�@�ɤ��ۭn��A�A�������˥�\n"NOR);
    if(!random(4))
    {
      message_vision(HIC"$N��$n����V�ĹL�ӡA���h���A���W����/n"NOR,this_object(),this_player());
      kill_ob(this_player());
    }
    return 1;
  }
  return 0;
}

void die()
{
   object ob, env, obj;
   int temp;
   string msg;

   if( !ob = query_temp("last_damage_from") )
   ob = this_player(1);
   if( !ob )
   {
     ::die();
     return;
   } 
   message("world:world1:vision",
   HIC"\n�i �u�@�� ���F �j  ���"+ob->name(1)+"�j�� : ���n ~ ~ ���n�h�� ! ! !  �C\n\n"+NOR
        ,users());
   ob->add("popularity",1);
   tell_object(ob,HIR"�A�o�� 1 �I�n��\n"NOR);


   ::die();
   return;
}

