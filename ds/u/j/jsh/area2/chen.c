#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"陳人麟"NOR, ({ "ran lin-chen","chen" }) );
        set("long",HIW"此人為古墓迷宮陣的首領，但是因為某些原因，使得功\力大不如前。\n"NOR);

    set("level",44);
        set("age", 20+random(1));

        set("combat_exp", 20000);
        set("chat_chance", 21);
        set("chat_msg", ({
  (: command,"say 妳在哪ㄋ ... ?.." :),
   this_object()->name()+"對著你說:你知道嗎 ?\n",
}));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
  (: command("exert da-fork") :),
}));
        set_skill("fork", 100);
        set_skill("da-fork",90);
        set_skill("parry", 75);
        set_skill("unarmed", 90);
        set_skill("dodge", 95);
        map_skill("fork","da-fork");

        setup();
        carry_object(__DIR__"horse-pike")->wield(); 
        carry_object(__DIR__"green-leggings")->wear();
        carry_object(__DIR__"red-finger")->wear();}

