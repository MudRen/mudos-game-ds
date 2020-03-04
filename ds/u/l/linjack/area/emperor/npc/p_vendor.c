inherit NPC;
void create()
{
        set_name("潦倒的小販",({ "poor vendor","vendor" }));
        set("long","一個窮極潦倒的可憐人, 看來是因為這邊生意太差了的緣故。\n");
        set("level",3);
        set("age",20);
        set("chat_chance", 8);
        set("chat_msg", ({
  "小販說： 真是衰尾到家....身上又只剩這點錢, 怎麼辦才好呢....。\n",
  (: random_move :),
}) );
        setup();
        carry_object(__DIR__"eq/junkcloth")->wear();
        carry_object(__DIR__"wp/stick")->wield();
        add_money("coin",200);
}