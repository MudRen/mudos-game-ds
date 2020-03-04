inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("礦工頭",({ "mineral collector","collector" }));
        set("long","商人顧用來收集礦石的工人。\n");
        set("level", 10);
        set("age",35);
        set("chat_chance", 8);
        set("chat_msg", ({
             "礦工頭喊著:採來凡礦石賣給我就對了。\n"
}));
        setup();
}
void init()
{
  add_action("do_sell","sell");
}
int do_sell(object who,object ob)
{

if(ob->name()!="礦石")  
        {
            command("say 我不須要");
            command("? "+who->query("id"));
            command("say 你自己留著用吧...");
            return 0;
          }
ob->set("value",1000);
 message_vision("$N把$n賣了。",who,ob);
return 1;
}

