
inherit NPC;
void create()
{
        set_name("村民",({ "villager" }) );
        set("long","一個在路邊乘涼的村民。\n");
        set("race","人類");
        set("age",50);
        set("level",3);
        set("attitude","friendly");
        setup();
}
