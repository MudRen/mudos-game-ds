inherit NPC;
void create()
{
        set_name( "吸血蝠" , ({ "bloodsuck bat", "bat", "__GUARD__" }) );
        set("level",2);
        set("gender","雌性");
        set("age",2);
        set("race","野獸");
        set("combat_exp",200);
        set("attitude","killer");
        set("evil",5);
        set("long","這是一隻會吸人血的大蝙蝠。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
