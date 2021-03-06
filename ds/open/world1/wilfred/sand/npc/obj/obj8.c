#include <ansi.h>
#include <login.h>
inherit NPC;

void flee();

void create()
{
set_name(HIW"銀星"NOR,({"silver-star horse","horse"}) );
  set("race", "beast");
  set("level",15);
  set("age",10);
  set("long",@LONG
此馬身如白雪，伴之如星點般的銀斑，高
大神駒，看來的確是千中擇一的良品。
LONG
);
  set("chat_chance_combat", 30);
  set("chat_msg_combat", ({ (: flee :) }));
  set("limbs", ({ "頭部", "身體", "前腳", "後腳","復部"}));
  set("verbs", ({"bite","hoof","crash"}));
  set("ridable",1);
  setup();
}

int ride_before_action(object me)
{
  message_vision("$N左足輕點，輕輕的躍上了"+this_object()->name()+"的馬背。\n",me);
  return 1;
}

int ride_after_action(object me)
{
  message_vision("$N已經騎上了"+this_object()->name()+"。\n",me);
  return 1;
}

int ride_off_action(object me)
{
  message_vision("$N從"+this_object()->name()+"的背上跳了下來。\n",me);
  return 1;
}

void flee()
{
        string *dirs;
        int i;

        message_vision("$N受到了攻擊，驚慌之下開始亂跑...。\n", this_object());
        if( !mapp(environment(this_object())->query("exits")) )
        {
		message_vision("$N往四周亂糟糟的跑，你也不知道他跑到那了...。\n", this_object());
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
                write(" 或許\你可以到 recall start 去找看看..。 \n");
        }
        dirs = keys(environment(this_object())->query("exits"));
        i = random(sizeof(dirs));
        command("go "+dirs[i]);
        write("go "+dirs[i] + "\n");
}
