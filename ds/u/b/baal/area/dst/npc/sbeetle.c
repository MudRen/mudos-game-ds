inherit NPC;
void create()
{
        set_name("小甲蟲", ({ "small beetle","beetle" }) );
        set("race", "beast");
        set("age", 1);
     set("level",1);

        set("long", "一隻背上有好幾個咖啡色斑點的小甲蟲。\n");
   set("str",2);
      set("max_hp",8);
    set("dex",-2);
     set("int",1);
       set("con",1);

        set("limbs", ({ "頭部", "身體", "前肢", "後肢" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 3);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "小甲蟲搖搖晃晃的在這裡∼走來∼走去。\n",
                "小甲蟲舉起兩隻鉗子，對著你的方向「喀喀」的夾了兩下，好像在跟你挑戰一樣。\n",}) );
                

        setup();
}

