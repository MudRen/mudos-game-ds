inherit NPC;

void create()
{
        set_name("工蟻", ({"worker"}) );
        set("long",@LONG
一隻忙得暈頭轉向的工蟻，牠專注地搬運螞蟻們日常所需的食物。
LONG);
        set("unit","隻");
        set("race", "beast");
        set("limbs", ({ "頭部", "身體", "觸角"})); 
        set("verbs", ({ "bite","claw","crash" })); 
        set("age", 1);
        set("level",20);
        set_temp("apply/hit",-10);      
        set_temp("apply/dodge",-20);    
        set("chat_chance",5);
        set("chat_msg",({
                "工蟻忙碌地搬運著物品。\n",
           (: command("sweat") :),
           (: random_move :),
        }));

        setup();
}
void die()
{
     object obj;
     message_vision( "[0;1;32m�[1m@[1m�[1m�[1m�[1mp[1m�[1mp[1m�[1m�[1m�[1mH[1m�[1m�[1m�[1mq[1m�[1mu[1m�[1m�[1m�[1m�[1m�[1m�[1m�[1mW[1m�[1m�[1m�[1mF[1m�[1mU[1m�[1m�[1m�[1mC[0m" ,this_object() );
     obj=new(__DIR__"hill_aphid_5");
     obj->move(environment(this_object() ) );
        ::die();
        return;
}
