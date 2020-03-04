inherit NPC;

void create()
{
        set_name("看門狗", ({"watchdog","dog"}) );
        set("long", "一隻忠心耿耿的看門狗，誓死保護入口•\n");
        set("unit","隻");
        set("race", "野獸");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳" })); //受攻部位
        set("verbs", ({ "bite","poke","crash" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
        set("age", 5);
        set("level",20);
        set("dex",50);
        set("str",50);
        set("con",50);
        set_temp("apply/hit",20);      
        set_temp("apply/dodge",20);    
        set("max_hp",3000);
        set("evil",-10);
        setup();
}
