inherit NPC;
void create()
{
        set_name("女孩",({ "girl" }));
        set("long","磐龍城裡的人民。\n");
        set("level", 12);
        set("age",14);
        set("chat_chance", 10);
        set("chat_msg", ({
  "女孩說： 這裡有好多好多大大的蜥蝪ㄛ ~ ~ ~ 。\n",
  (: random_move :), 

}) );
        setup();
        
}


