#include <ansi.h>
inherit NPC;
void create()
{
        set_name("探險家",({ "man" }));
        set("long","一個從外地來的探險家，看起來好像有什麼心事。\n");
        set("level", 10);
        set("age",44);
        set("chat_chance", 8);
        setup();
        add_money("coin",200);
}

int talk_action(object me)
{
        object ob;
        ob = this_object();
        if( !query_temp("pe") )
             message_vision(ob->name()+"對$N說："+RANK_D->query_respect(me)+"可不可以幫我拿到"HIR"殺人狐 九尾"NOR"身上的皮??\n",me);                             
        return 1;
}

int accept_object(object who, object ob)
{
        object tob, a;
        tob = this_object();
        if( ob->query("id")!="fox fur" || query_temp("pe") ) return 0;

        command("thank "+who->query("id"));
        command("say 真是太感謝你了，"+RANK_D->query_respect(who)+"！\n");
        who->add("exp", 8000);
        set_temp("pe",1);
        tell_object(who,HIW"你得到 8000 點經驗值。\n"NOR);
        call_out("delay",600,this_object());
        set("long","一個從外地來的探險家，正摸著他手上狐皮。\n");

        return 1;
}

void delay(object tob)
{
delete_temp("pe");
        set("long","一個從外地來的探險家，看起來好像有什麼心事。\n");
        return;
}


