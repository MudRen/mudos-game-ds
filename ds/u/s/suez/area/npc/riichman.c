inherit NPC;
void create()
{
       set_name("富人",({"richman"}));
       set("long","一個有錢人！");
       set("gender","男性");
       set("age", 51);
       set("level", 1);
      set("str", 70);
        setup();
        add_money("coin", 70000);
}
