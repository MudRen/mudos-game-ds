inherit NPC;

void create()
{
set_name("寄居蟹",({"pagurian"}));
set("race", "野獸");
set("level",13);
set("age",5);
set("long","一隻活潑的寄居蟹正偷偷的從你的面前緩緩爬過。\n");
set("limbs", ({ "頭部", "身體", "前螯", "腹足","腹部"}));
 set("verbs", ({ "bite"}));
set("chat_chance",30);
set("chat_msg",({
(:command("east"):),
(:command("west"):),
(:command("north"):),
(:command("south"):),
}));
set("amount",1);
        setup();
add_money("coin",random(200));
}

