#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name("兇石斑",({"bad she bun","bun","she","bad"}));
       set("gender","野獸");
       set("level",20);
       set("age",10);      
       set("attitude","friendly");
       set("limbs", ({ "頭部", "身體", "腹部", "尾巴"}) );
       set("verbs", ({ "bite"}) ); 
       set("chat_msg", ({
                       (: this_object(), "random_move" :), 
                        "兇石斑:魚兒魚兒水中遊~~~~~"}));  
       set("long",@LONG      
兇石斑，魚群裡最兇的魚類，但還是屈服在魚老大的膝下。

LONG
); 
        setup(); 
        carry_object(__DIR__"obj/ticket");
} 

