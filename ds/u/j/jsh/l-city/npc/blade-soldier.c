#include <ansi.h> 
inherit NPC; 
void create() 
{ 
       set_name("開羅士兵",({"kailo soldier","soldier"}));
       set("gender","人類");
       set("level",30);
       set("age",30);      
       set("attitude","unfriendly");  
       set("evil",20);
       set("chat_chance", 4);
       set("chat_msg", ({
                       (: this_object(), "random_move" :), 
                        "開羅士兵大喊：衝啊！！殺呀！！\n"}));
       set("long",@LONG      
開羅國的士兵，身手矯健。

LONG
); 
        setup();  
        carry_object(__DIR__"obj/blade")->wield();
} 

