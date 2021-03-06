#include <ansi.h>
inherit NPC;
void create()
{
        set_name("洋人", ({ "foreigner","man" }) );
        set("long","綠眼睛黃頭髮的人，一天到晚在講些嘎嘎烏拉拉的話，不過他們身上倒\n"
                   "是有些值錢的好東西。\n");
        set("level",10+random(10));
        set("age",20+random(3));

        set("combat_exp", 20000);
        set("chat_chance", 4);
        set("chat_msg", ({
  "洋人說道 : 嘎嘎屋拉拉！\n",
  "洋人說道 : 嗚嗚蝦蝦啊！\n",
  "洋人說道 : 依依啊嗚喔！\n"
}));
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (:command("say 嘎嘎屋拉拉！"):),
                (:command("say 嗚嗚蝦蝦啊！"):),
                (:command("say 依依啊嗚喔！"):),
                (:command("help!"):),
                       }) );
        
        set_skill("parry", 70);
        set_skill("unarmed", 80);
        set_skill("dodge", 65);

        setup();
        carry_object(__DIR__"obj/gem-ring")->wear();
        carry_object(__DIR__"obj/gem-kerchief.c")->wear();
}
