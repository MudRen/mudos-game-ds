#include <ansi.h>
inherit NPC;
void create()
{
  set_name("馬若", ({ "ma-ruo general", "ruo" ,"general" }) );
  set("long","馬若是少帥軍中的武略將軍，負責北城門的邊防工作。\n");
  set("title", "少帥軍");
  set("level", 30);
  set("age", 30);
  set("no_kill",1);

   set("chat_chance", 3);
  set("chat_msg", ({
        (: command("say 碎骨寨是鐵櫻族的一支前鋒軍旅，幾個月前在北城外紮營，伺機而動。") :),
        (: command("say 這碎骨寨一日不滅，磐龍城就一日不安全。") :),
        (: command("sigh。") :),
        }));
  setup();
  carry_object(__DIR__"wp/blade")->wield();
}

