/* ghost.c
   by -Acme-
*/

#include <ansi.h>
inherit NPC;

object owner;

// 設定擁有者
int set_owner(object obj)
{
    if( !objectp(obj) ) return 0;
    owner = obj;
}

// 查詢擁有者
object query_owner()
{
    if( !objectp(owner) ) return 0;
//    if( !owner->query_temp(query("number")) ) return 0;
//    if( owner->query_temp(query("number")) != this_object() ) return 0;
    return owner;
}

// 刪除ghost
void do_destruct()
{
    message_vision("附近傳來淒涼的「咿∼呀呀∼」聲音，$N就消失不見了...\n", this_object());
    // 每死掉一隻ghost ，都可以替主人增加1點太陰凝精
        if(objectp(owner)) 
                SPELL_D("moon-essence")->checkAdd(owner);

    set_heart_beat(0);
    destruct(this_object());
        return;
}

// 檢查鬼魂是不是要消失了
void do_check()
{
    if( !objectp( query_owner() ) ) {
        do_destruct();
        return;
    }

    if( query("hp") < 1 ) {
        do_destruct();
        return;
    }

    if( environment(this_object()) != environment(owner) ) {
        do_destruct();
        return;
    }

    return;
}

void die()
{
    message_vision("附近傳來淒涼的「咿∼呀呀∼」聲音，$N就消失不見了...\n", this_object());
    // 每死掉一隻ghost ，都可以替主人增加1點太陰凝精
        if(objectp(owner)) 
                SPELL_D("moon-essence")->checkAdd(owner);
        
    destruct(this_object());
    return;
}

void create()
{
    set_temp("float",1); // 鬼應該浮在空中吧, By Acme

    set_name("孤魂野鬼", ({ "ghost" }));
    set("long", "一個渾身素衣，不知已死了多少年，至今乃未投胎的野鬼。 \n");
    set("gender", "男生");
    set("race", "人類");
    set("age", 30);
    set("level",1);
    set("evil", 40);         
       set("no_scroll", 1);

    // 平時動作：檢查owner還在不在，並吸取其查克拉
    set("chat_chance", 2);
    set("chat_msg", ({
        this_object()->query("name")+"飄了過去，又飄了過來....\n",
        this_object()->query("name")+"長嘆了一口氣　∼嗚∼∼　\n",
        (: do_check :),
    }));

    // 戰鬥時動作：檢查owner還在不在，並吸取其查克拉
    set("chat_chance_combat", 5);
    set("chat_msg_combat", ({
        (: do_check :),
    }) );

    setup();
}

