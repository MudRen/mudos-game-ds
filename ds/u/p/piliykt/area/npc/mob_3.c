inherit NPC;
void create()
{
        set_name("乞丐",({ "beggar" }));
        set("long","一個坐在路邊到處要飯吃的人。\n");
        set("level", 5);
        set_skill("unarmed", 30);
        set_skill("dodge", 20);
        set("age",45);
        set("chat_chance", 5);
        set("chat_msg", ({
  "乞丐說： 唉~~肚子好餓。\n",
  "乞丐說： 好心的人,可不可以給我一個饅頭.\n"
  "乞丐唉~~的嘆了一口氣!!.\n"  
}) );
        setup();
        
}


