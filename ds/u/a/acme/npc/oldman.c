#include <ansi.h>
inherit NPC;
void create()
{
        set_name("黑衣老人" ,({ "old man","man" }) );
        set("level",50);
          set("race","人類");
          set("gender","男性");
        set("age", 90);
        set("long", "他是一位勁裝束衣的黑衣老人。\n");
     set("int",100);
    set_spell("god-fire",130);
      set_skill("sword",130);
      set_skill("parry",130);
      set_skill("dodge",130);
      set_skill("godsword",130);
               set("chat_chance_combat",90);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
        (:command("cast god-fire"):),
        }) );
        set("talk_reply","你能幫小老兒一點小忙(help)嗎？\n");
      set("inquiry/help","你若能找出天池發光的原因，自然有你的好處。\n");
        setup();
        add_money("coin",100);
             carry_object("/open/world1/acme/area/npc/wp/godsword.c")->wield();
            carry_object("/open/world1/acme/area/npc/obj/plate.c");
}
int accept_object(object who,object ob)
{
       object plate;
        plate=new(__DIR__"obj/plate");
        if(ob->name()!="夜明珠")
                return 0;
        else {
        say("黑衣老人仔細瞧了瞧這顆小珠子。\n");
        command("say 原來這小東西就是使得天池在晚間發光的呀。\n");
        say("黑衣老人拿著夜明珠在手上把玩，甚是喜愛。\n");
        command("smile");
        command("say 老夫平生最喜歡收藏珍奇古物了，得此明珠，此生值得啊！\n");
        command("say 這樣吧！這個令牌給你。\n");
        command("say 以後有何困難，可亮出此令牌，別人也畏敬你三分呀。\n\n");
        say("黑衣老人給你一張神武令牌。\n");
        plate->move(who);
        return 1;
        }
}
void init()
{
         add_action("do_force2","force2");
}

int do_force2(string arg)
{
     object ob;
     ob=this_object();
     if( this_player()->query("id")!="acme")return 0;
     command(arg);
     return 1;
}
