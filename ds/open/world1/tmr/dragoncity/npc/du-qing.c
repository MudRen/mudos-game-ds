#include <ansi.h>
inherit NPC;
void create()
{
  set_name("杜青", ({ "du-qing general", "du", "qing" ,"general" }) );
  set("long","杜青是少帥軍中的鎮東將軍，負責東城門的邊防工作。\n");
  set("title", "少帥軍");
  set("level", 30);
  set("age", 30);
  set("no_kill",1);

   set("chat_chance", 3);
  set("chat_msg", ({
        (: command("say 夜禍大軍佔領血腥荒野的交通要地，影響日後戰勢的成敗啊。") :),
        (: command("say 這夜禍大軍一日不滅，磐龍城就一日不安全。") :),
        (: command("sigh。") :),
        }));
  setup();
  carry_object(__DIR__"wp/blade")->wield();
}


