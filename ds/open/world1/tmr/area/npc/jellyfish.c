inherit NPC;

void create()
{
        set_name("水母",({"jellyfish"}) );
        set("long","一隻半透明的水母，正在揮動它的觸手捕捉食物...。\n");
        set("race", "野獸");
        set("env/wimpy", 20);
        set("unit","隻");
        set("age",5);
        set("level",2);
        set("attitude", "heroism");  
        set("str",-2);
        set("dex",3);
        set("limbs", ({ "頭部", "身體", "觸手" }) ); //受攻部位
        set("verbs", ({ "bite","claw" }) );                         //攻擊方式
        set("chat_chance",6);
        set("chat_msg",({
          (: this_object(),"random_move()":),
        }) );

        setup();
	add_money("coin",30);
}
