
inherit NPC;
void create()
{
        set_name("�H�{",({ "man"}));
        set("long","�@�줣���d���b���e�Ӱݦ򪺮ȤH�C\n");
        set("level", 5);
        set("age",45);
        set("chat_chance", 8);
        set("chat_msg", ({
        (: command,"sweat" :),
        }) );
        setup();
        add_money("coin",100);
}

