#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "小菊", ({ "siu ju","siu","ju" }) );
        set("level",10);
       set("combat_exp",1000);
        set("long" ,
                 "她是天殘邪佬的孫女，她在此把玩著天殘邪佬所收藏的珍奇寶物\n"
                 "頗能自得其樂。她長得眉清目秀，有著讓秋娘所妒忌的容貌，實\n"
                 "在令人不敢相信她會是奇醜無比的天殘邪佬的孫女。\n",
           );
        set("age",14);
        set("gender","女性");
        set("evil",-30);
//          set_skill("darkdagger",20);
           set_skill("dagger",20);
           set_skill("dodge",20);
           set_skill("parry",20);
        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
           (:command("exert darkdagger"):),
           (:command("say 爺爺救命呀！！有人要殺死我！！"):),
           (:command("cry"):),
        }) );

        setup();
        carry_object(__DIR__"wp/dagger.c")->wield();
}
