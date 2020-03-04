#include <ansi.h>
inherit NPC;

void create()
{
        set_name(YEL"長毛怪"NOR, ({"Longhair Monster", "monster","longhair"}) );
        set("long", "
一個全身長滿紅棕色長毛的外星人，他長的粗壯高大，露了一對犬齒出來，
看起來好像在溜口水的樣子，加上一副惡狠狠的眼睛正盯著你瞧，
使你覺得似乎要把你給吞了的感覺，看來不走就太對不起自己了。！\n");
        set("race", "monster");
        set("gender", "男性"); 
        set("age", 83);
        set("level", 20);
      set("bellicosity",10000);
        set("evil", -90);
        set("combat_exp",900);
        set("env/wimpy", 25);        
        set("chat_chance", 3 );
        set("chat_msg", ({   
        "長毛怪發出吼吼的低沉聲音\n",
        "長毛怪背上的紅棕色長毛全豎了起來\n",
        (:command("say"):),
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        (:command("say Fresh meat"):),
        (:command("say 自尋死路"):),
        }) );
        setup(); 
}


