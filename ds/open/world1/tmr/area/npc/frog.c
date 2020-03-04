inherit NPC;

void create()
{
        set_name("田蛙",({"frog"}) );
        set("long","一隻青綠色的肥田蛙，正在荷葉上嘓嘓地叫著。\n");
        set("race", "野獸");
        set("env/wimpy", 10);
        set("unit","隻");
        set("age",1);
        set("level",1);
      set("str",1);
         set("dex",-1);
      set("attitude","heroism");
        set("limbs", ({ "頭部", "身體", "腳" }) ); //受攻部位
        set("verbs", ({ "bite" }) );                         //攻擊方式
        set("chat_chance",6);
        set("chat_msg",({
		"田蛙朝著藍藍的天空叫道：「嘓∼∼∼嘓∼∼∼」\n",
        }) );

        setup();
	add_money("coin",10);
}
