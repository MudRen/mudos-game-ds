#include <ansi.h>
#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("哈嘻皮", ({ "ha xipi", "xipi"}) );
        set_race("human");
        set_attr("int", 30 );
        set_attr("str", 19);
        set_attr("cor", 17);
        set_attr("cps", 15);
        set_attr("dex", 18);
        set("title", "村長");
        set("age", 20);
        set("long",@long
哈嘻皮是哈哈村的村長，十分和善，待人親切，以服務全村人
民為已任，要是你有什麼問題，都可以找他來幫忙。
long
);
        set("chat_chance", 5);
        set("chat_msg", ({
            "哈嘻皮仰著天嘴裡發出「嘻∼嘻∼」的聲音...\n",
            "哈嘻皮轉頭過來，對著你發出「嘻∼嘻∼」的聲音...\n",
            "哈嘻皮對著你說道：「嘻∼嘻∼請問你有什麼問題嗎？」\n",
            "哈嘻皮對著你說道：「嘻∼嘻∼你有蛇膽嗎？」\n",
        }));
        setup();
}

void relay_say(object ob, string arg)
{
    object item;

    if( arg == "蛇膽" )  {
        do_chat( ({ "哈嘻皮說道：「只要你給我一個蛇膽，我就會給你一件好東西。」\n", }) );
        return;
    }
}

int accept_object(object me, object ob)
{
    object item;

    if( is_fighting() ) {
        do_chat((: command, "say 別吵！沒看到我正在打架啊！" :));
        return 0;
    }

    if( ob->id("_SNAKE_GALL_") ) {
        if( file_size(__DIR__"obj/snake_belt.c") < 0 ) return 0;
        if( catch(item = new(__DIR__"obj/snake_belt.c")) ) return 0;

        if( item->move(me) ) {
            message_vision(HIW"$N從背後拿出了一條蛇皮腰帶，拿給了$n。\n"NOR, this_object(), me);
        } else {
            if( item->move(environment(me)) ) {
                message_vision("$N從背後拿出了一條蛇皮腰帶，拿給了$n，但是掉在地上了。\n", this_object(), me);
            } else {
                destruct(item);
                return 0;
            }
        }
    } else { return 0; }

    message_vision("$N高興的看著" + ob->short() + "笑道：「哈哈，太棒了！實在很感激您啊！」\n", this_object() );

    do_chat( ({ ( : destruct , ob : ), }) );

    return 1;
}
