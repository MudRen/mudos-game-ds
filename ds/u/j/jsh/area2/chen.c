#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"���H��"NOR, ({ "ran lin-chen","chen" }) );
        set("long",HIW"���H���j�Ӱg�c�}������A���O�]���Y�ǭ�]�A�ϱo�\\�O�j���p�e�C\n"NOR);

    set("level",44);
        set("age", 20+random(1));

        set("combat_exp", 20000);
        set("chat_chance", 21);
        set("chat_msg", ({
  (: command,"say �p�b���z ... ?.." :),
   this_object()->name()+"��ۧA��:�A���D�� ?\n",
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

