#include <ansi.h>
#include <login.h>
inherit F_UNIQUE;
inherit NPC;

void flee();

void create()
{
  set_name(YEL"烈風黃"NOR,({"fierce-wind horse","horse"}) );
  set("race", "beast");
  set("level",15);
  set("age",10);
  set("long",@LONG
傳說黃沙平原中產著一種黃色烈馬，此馬來無影，去
無蹤，其能力可媲美名馬『的盧』，是為萬中選一的
良駒，據說後來有個商人費了許多力氣才捉到一隻，
此馬看來神駿非凡，難道這隻便是....？
LONG
);
  set("chat_chance_combat", 30);
  set("chat_msg_combat", ({ (: flee :) }));
  set("limbs", ({ "頭部", "身體", "前腳", "後腳","復部"}));
  set("verbs", ({"bite","hoof","crash"}));
  set("ridable",1);
  set("replica_ob",__DIR__"obj8");
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
