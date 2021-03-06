#include <ansi.h>
#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("扶耳 磨擦", ({ "fuer moca", "moca"}) );
    set_race("human");
    set("age", 6);
    set("long", "戴著一頂草帽，還有口罩，一副見不得人的樣子。\n");
    set("title","「福小姐」");

    set("chat_chance", 20);
    set("chat_msg", ({
        "扶耳 磨擦東翻西翻的不知道在找啥...\n",
        "扶耳 磨擦嘴裡唸唸有辭...\n",
    }));

    setup();
}

int accept_fight(object ob)
{
    do_chat("扶耳 磨擦對著你說道：「走開！別礙著我！」\n");
    return 0;
}

void relay_say(object ob, string arg)
{
    object item;

    if( ob->query_temp("quest/haha_quest1") == 2 && arg == "哈顫" )  {
        do_chat( ({ "扶耳 磨擦說道：「哦∼原來你識得『哈顫』那傻小子啊，找我有什麼事嗎？」\n", }) );
        ob->set_temp("quest/haha_quest1", 3);
        return;
    }

    if( ob->query_temp("quest/haha_quest1") == 3 && arg == "證據" ) {
        if( this_object()->query_temp("quest/give_item") ) {
            do_chat( ({ "扶耳 磨擦說道：「哦∼原來你是要來拿證據的啊，沒多久之前已經有人來拿過了。」\n", }) );
            return;
        }

        do_chat( ({ "扶耳 磨擦說道：「哦∼原來你是要來拿證據的啊，吶！拿去，就是這個了。」\n", }) );
        ob->set_temp("quest/haha_quest1", 4);

        if( file_size(__DIR__"obj/proof1.c") < 0 ) return;
        if( catch(item = new(__DIR__"obj/proof1.c")) ) return;

        if( item->move(ob) ) {
            message_vision(HIW"$N從背後拿出了一本證據，拿給了$n。\n"NOR, this_object(), ob);
        } else {
            if( item->move(environment(ob)) ) {
                message_vision("$N從背後拿出了一本證據，拿給了$n，但是掉在地上了。\n", this_object(), ob);
            } else {
                destruct(item);
                return;
            }
        }

        this_object()->set_temp("quest/give_item", 1);
        call_out("reset", 900);
        return;
    }
}

void reset()
{
    this_object()->delete_temp("quest/give_item");
}
