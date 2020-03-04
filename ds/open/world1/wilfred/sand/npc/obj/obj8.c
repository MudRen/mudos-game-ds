#include <ansi.h>
#include <login.h>
inherit NPC;

void flee();

void create()
{
set_name(HIW"�ȬP"NOR,({"silver-star horse","horse"}) );
  set("race", "beast");
  set("level",15);
  set("age",10);
  set("long",@LONG
�������p�ճ��A�񤧦p�P�I�몺�ȴ��A��
�j���s�A�ݨӪ��T�O�d���ܤ@���}�~�C
LONG
);
  set("chat_chance_combat", 30);
  set("chat_msg_combat", ({ (: flee :) }));
  set("limbs", ({ "�Y��", "����", "�e�}", "��}","�_��"}));
  set("verbs", ({"bite","hoof","crash"}));
  set("ridable",1);
  setup();
}

int ride_before_action(object me)
{
  message_vision("$N�������I�A�������D�W�F"+this_object()->name()+"�����I�C\n",me);
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

void flee()
{
        string *dirs;
        int i;

        message_vision("$N����F�����A��W���U�}�l�ö]...�C\n", this_object());
        if( !mapp(environment(this_object())->query("exits")) )
        {
		message_vision("$N���|�P���V�V���]�A�A�]�����D�L�]�쨺�F...�C\n", this_object());
                switch(NATURE_D->which_world(environment(this_object())))
                {
                        case 3:
                                this_object()->move(START_ROOM_FUTURE);
                                this_object()->stop_attack();
                                break;
                        case 2:
                                this_object()->move(START_ROOM_NOW);
                                this_object()->stop_attack();
                                break;
                        case 1:
                                this_object()->move(START_ROOM_PAST);
                                this_object()->stop_attack();
                                break;
                        default:
                                destruct(this_object());
                                return;
                }
                write(" �γ\\�A�i�H�� recall start �h��ݬ�..�C \n");
        }
        dirs = keys(environment(this_object())->query("exits"));
        i = random(sizeof(dirs));
        command("go "+dirs[i]);
        write("go "+dirs[i] + "\n");
}
