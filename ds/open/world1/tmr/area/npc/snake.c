inherit NPC;

void create()
{
        set_name("水蛇",({"water snake","snake"}) );
         set("long","一條身長一尺的水蛇，看起來滿溫馴的，只要你不去惹它的話。。\n");
        set("race", "野獸");
        set("env/wimpy", 20);
        set("unit","條");
        set("age",4);
        set("level",3);
        set("attitude", "heroism");  
        set("str",1);
        set("con",1);
        set("dex",1);
        set("limbs", ({ "頭部", "身體", "腹部", "尾巴" }) ); //受攻部位
        set("verbs", ({ "bite" }) );                         //攻擊方式
        set("chat_chance",6);
        set("chat_msg",({
          (: this_object(),"random_move()":),
        }) );

        setup();
add_money("coin",50);
}
