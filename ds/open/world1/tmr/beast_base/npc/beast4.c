#include <npc.h>
#include <ansi.h>
#include <skill.h>

inherit __DIR__"inherit/action.c";

void create()
{
    set_name("���j�~�~", ({ "huge beast", "beast", "_94_NEW_YEAR_" }) );

    set_race("beast");

    set("age", 1);
    set("title", CYN"�A�����~"NOR);
    set("long", "�@���b�A�����s�~�]�X�ӦY�H�ת��~�~�C\n");

    set("forect_ratio", 100);

    /* �H���ʧ@ */
    set("chat_chance", 30);
    set("chat_msg", ({
        (: do_random_move, this_object() :),
    }) );

    /* �԰��ʧ@ */
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: do_fight_issue, this_object(), "attack" :),        
        (: do_fight_issue, this_object(), "heal" :),
    }) );

    set("vendetta_mark", "_94_NEW_YEAR_");

    setup();

    /* �ޯ�]�w */
    set_skill("dodge", 150);
    set_skill("parry", 150);
    set_skill("unarmed", 150);
    set_skill("psychical", 150);

    /* ���ɪ��A�]�w */
    advance_stat("hp", 2000);

    set_level(35);
    set_living_name("_94_NEW_YEAR_");
}

void init()
{
    if( this_player()->query("life_form") == "ghost" ) return;
    if( environment(this_object())->query("no_fight") ) return;
    if( this_player()->is_character() && !this_player()->id("_94_NEW_YEAR_") ) {
        if( !this_player()->is_fighting(this_object()) || !this_object()->is_killing(this_player()) ) {
            object obj;
            if( objectp(obj = present("_CHICKEN_YEAR_GIFT_", this_player())) )
                this_player()->add("_CHICKEN_NEW_YEAR_", 1);
            this_object()->kill_ob(this_player());
            this_player()->fight_ob(this_object());
        }
    }
}
