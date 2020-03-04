#include <ansi.h>
#include <login.h>
inherit NPC;

void flee();

void create()
{
  set_name("����",({"yellow horse","horse"}) );
  set("race", "beast");
  set("level",25);
  set("age",10);
  set("limbs", ({ "�Y��", "����", "�e�}", "��}","�_��"}));
  set("verbs", ({"bite","hoof","crash"}));
  set("ridable",1);
  set("chat_chance_combat", 30);
  set("value", 700);
          setup();
}
void init()
{
        ::init(); //luky
        add_action("do_name","name");
        if(environment(this_object())==this_player())
        {
          add_action("do_member","member");
          add_action("do_run","run");
          add_action("do_power","power");
          add_action("do_full","full");
        }
}


int ride_before_action(object me)
{
  message_vision("$N�@��½���A�D�W�F"+this_object()->name()+"�����I�C\n",me);
  return 1;
}

int ride_after_action(object me)
{
  message_vision("$N�w�g�M�W�F"+this_object()->name()+"�C\n",me);
  return 1;
}

int ride_off_action(object me)
{
  message_vision("$N�q"+this_object()->name()+"���I�W���F�U�ӡC\n",me);
  return 1;
}


