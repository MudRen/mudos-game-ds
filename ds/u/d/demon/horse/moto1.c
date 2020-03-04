#include <ansi.h>
inherit NPC;
void create()
{
set_name(MAG"哈雷機車S"NOR,({"hala moto","moto"}) );
  set("race", "beast");
  set("level",99);
  set("age",1000);
  set("long",@LONG
傳說中的機車，並非每個人都能駕馭它。
LONG
);
  set("limbs", ({ "大燈", "汽缸", "前輪", "後輪","引擎"}));
  set("verbs", ({"bite","hoof","crash"}));
  set("ridable",1);
  setup();
}

int ride_before_action(object me)
{
  message_vision("$N左足輕點，輕輕的躍上了"+this_object()->name()+"的座位。\n",me);
  return 1;
}
int ride_after_action(object me)
{
  message_vision("$N已經騎上了"+this_object()->name()+"。\n",me);
  return 1;
}

int ride_off_action(object me)
{
  message_vision("$N從"+this_object()->name()+"座位上跳了下來。\n",me);
  return 1;
}

