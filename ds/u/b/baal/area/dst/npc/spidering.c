inherit NPC;
void create()
{
        set_name("小蜘蛛", ({ "spidering" }) );
        set("race", "beast");
        set("age", 2);
     set("level",1);

        set("long", "一隻全身深藍色的小蜘蛛，看來是剛孵出來的吧？\n");
   set("str",3);
      set("max_hp",13);
    set("dex",-3);
     set("int",1);
       set("con",1);

        set("limbs", ({ "頭部", "身體", "前肢", "後肢" }) );
        set("verbs", ({ "bite" }) );

        set("chat_chance", 3);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "小蜘蛛跑到你的腿上，在你腿上吐起絲來了。\n",
                "小蜘蛛扭了扭，慢慢的在草叢裡鑽來鑽去。\n",}) );
                

        setup();
}

