#include <ansi2.h>
#include <room.h>
inherit ROOM;

void create ()
{
  set("short",HIG"霧之森"NOR);
  set("long",
"這裡是一片美麗的森林，有相當多的小生物居住在這裡，你可以試著\n"
WHT"呼叫(co)"NOR"他們，親近大自然，在小高的屋子旁有個小記事板，寫了些字。\n"
);
  set("exits",([
  "up" : __DIR__"workroom",
  "down" : "/d/wiz/hall1",
  "west" : "/open/world1/tmr/area/hotel",
]));
  set("light",1);
  setup();
}

void init()
{
  add_action("do_co","co");
}

int do_co(string arg)
{
  object ob,me;
  string file, path;
  path = "/u/w/wilfred/npc";
  me = this_player();

  if(!arg)
  { return notify_fail("你想叫哪隻動物出來呢 :>\n"); }
  else
  {
    file = resolve_path(path,arg);
    file +=".c";
  }

  if(sizeof(file)<=0 || !find_object(file))
  {
    return notify_fail(HIR"一點動靜也沒有....\n"NOR);
  }
  else
  {
    ob = new(file);
    ob->move(environment(me));
    message_vision(HIW"森林的角落忽然鑽出了一隻"NOR"$N\n",ob);
    return 1;
  }
}

