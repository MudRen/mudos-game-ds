#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIG"青蛇使"NOR, ({ "green snake woman","woman" }) );
        set("level",37);
        set("combat_exp",6520);
set("exp",4411);
        set("evil",200);
        set("long","他是蚩尤的十妖之一\n"
                   "跟隨蚩尤已經非常久了\n"
                   "手把的蛇鞭,可從遠處就\n"
                   "可以把要的東西拿到手了。\n"
            );
        set("age",32468);
        set("attitude","killer");
        set("gender","女性");
        set("title",YEL"十妖之 "NOR);
        set_skill("unarmed",80);
        set_skill("dodge",75);
        set_skill("parry",80);
        set_skill("whip",150);
        set("chat_chance_combat",20);
        set("chat_msg_combat", ({
"青蛇使說:我美不美ㄚ..!! 哈哈哈哈... 。\n\n"                    
   }) );
       setup();
       carry_object("/u/t/tako/whip.c")->wield();  
       carry_object("/u/t/tako/surcoat.c")->wear();
}





