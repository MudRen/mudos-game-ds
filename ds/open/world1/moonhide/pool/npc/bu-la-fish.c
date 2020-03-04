#include <ansi.h> 
inherit NPC; 

void create() 
{ 
       set_name("吻仔魚",({"bu la fish","fish"}));
       set("race","beast");
       set("level",5);
       set("age",10);      
       set("attitude","friendly");
       set("limbs", ({ "頭部", "身體", "腹部", "尾巴"}) );
       set("verbs", ({ "claw","bite"}) ); 
       set("chat_msg", ({
                       (: this_object(), "random_move" :), 
                        "吻仔魚:魚兒魚兒水中游~~~A_A~~~~\n" }) );
       set("long",@LONG      
吻仔魚，是這裡最瘦弱的魚，很好欺負。

LONG
); 
        setup(); 
        carry_object(__DIR__"obj/ticket");
} 
