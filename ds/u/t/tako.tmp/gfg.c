#include <ansi.h>
inherit NPC; 
void create()
{
        set_name(HIY"布丁"NOR, ({ "poo ding","ding" }) );
        set("long","可愛的女孩,是一位痴情的人。\n");
        set("level",10);
        set("age",15);

        set("combat_exp", 10); 
        set("chat_chance",10);
        set("chat_msg",({
            "布丁說:老公出去送貨怎麼還沒回來呢..^^....\n",
        }) );                               
        set_skill("combat", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
         
        setup(); 
        add_money("coin",100);
        obj=new("/u/t/tako/item/pearl");
        ::die();
        return;        }



