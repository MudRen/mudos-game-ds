inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("�q�u�Y",({ "mineral collector","collector" }));
        set("long","�ӤH�U�ΨӦ����q�۪��u�H�C\n");
        set("level", 10);
        set("age",35);
        set("chat_chance", 8);
        set("chat_msg", ({
             "�q�u�Y�۵�:�ĨӤZ�q�۽浹�ڴN��F�C\n"
}));
        setup();
}
void init()
{
  add_action("do_sell","sell");
}
int do_sell(object who,object ob)
{

if(ob->name()!="�q��")  
        {
            command("say �ڤ����n");
            command("? "+who->query("id"));
            command("say �A�ۤv�d�ۥΧa...");
            return 0;
          }
ob->set("value",1000);
 message_vision("$N��$n��F�C",who,ob);
return 1;
}

