inherit NPC;
void create()
{
        set_name("老人",({ "man" }) );
        set("long","一個獨居的老人。\n");
        set("race","人類");
        set("title","晴子的阿公");
        set("age",75);
        set("level",10);
        set("chat_chance",5);
        set("chat_msg",({
               (:command("sing 我沒醉∼我沒醉∼請不要同情我"):),
                "老人高聲唱道：「沒人性的晴子∼∼∼」\n",
        }) );

        set_skill("dodge",5);
        set_skill("unarmed",5);
        set_skill("parry",5);

   setup();
add_money("silver",8);
}
