inherit NPC;
void create()
{
        set_name("磐龍蜥",({ "panlon shea","shea","panlon" }));
        set("long","磐龍城裡裡外外都可以看的生物。\n");
        set("level", 10);
        set("age",10+random(20));
        set("chat_chance", 10);
        set("chat_msg", ({
  "磐龍蜥發出怪怪的聲音： tsk tsk tsk。\n",
  (: random_move :), 

}) );
        setup();
        
}

