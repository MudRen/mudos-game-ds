
inherit NPC;
void create()
{
        set_name("信徒",({ "man"}));
        set("long","一位不惜千里奔走前來問佛的旅人。\n");
        set("level", 5);
        set("age",45);
        set("chat_chance", 8);
        set("chat_msg", ({
        (: command,"sweat" :),
        }) );
        setup();
        add_money("coin",100);
}

