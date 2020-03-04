/* write by -Acme-
*/

#include <ansi.h>
inherit NPC;
inherit __DIR__"inherit/heal.c";
inherit __DIR__"inherit/attack.c";
void create()
{
    int i;
    set_name( "��j��", ({ "ban goo evil", "evil" }) );
    set("level", 35);

    set_skill("dodge", 75);
    set_skill("parry", 75);
    set_skill("unarmed", 90);
    set_skill("staff", 90);

    set("long" ,"�����G���@��@��Ǧⴳ�I�����ǡC\n");
    set("age",50);
    set("title", GRN "�s�]�ûR" NOR);
    set("chat_chance", 5);
    set("chat_msg", ({ (: random_move :) }) );
    set("chat_chance_combat", 60);
    set("chat_msg_combat", ({
        (: do_heal, this_object(), "hp" :),
        (: do_attack, this_object() :),
    }));

    setup();
    set_living_name("__BIG_GHOST_WAR__");
    switch( random(100) ) {
        case  0..10: carry_object(__DIR__"obj/ball");
        case 11..40: carry_object(__DIR__"obj/pill");
        case 41..90: carry_object(__DIR__"obj/drink"); break;
    }

    i = random(4);
    while( i-- ) {
        switch( random(14) ) {
            case  0: carry_object(__DIR__"eq/armor")->wear(); break;
            case  1: carry_object(__DIR__"eq/boots")->wear(); break;
            case  2: carry_object(__DIR__"eq/cloth")->wear(); break;
            case  3: carry_object(__DIR__"eq/finger")->wear(); break;
            case  4: carry_object(__DIR__"eq/hands")->wear(); break;
            case  5: carry_object(__DIR__"eq/helmet")->wear(); break;
            case  6: carry_object(__DIR__"eq/leggings")->wear(); break;
            case  7: carry_object(__DIR__"eq/mask")->wear(); break;
            case  8: carry_object(__DIR__"eq/neck")->wear(); break;
            case  9: carry_object(__DIR__"eq/pants")->wear(); break;
            case 10: carry_object(__DIR__"eq/shield")->wear(); break;
            case 11: carry_object(__DIR__"eq/surcoat")->wear(); break;
            case 12: carry_object(__DIR__"eq/waist")->wear(); break;
            case 13: carry_object(__DIR__"eq/wrists")->wear(); break;

        }
    }

    carry_object(__DIR__"wp/staff")->wield();
}

void init()
{
    ::init();
    if( environment(this_player())->query("no_kill") ) return;
    if( environment(this_player())->query("no_fight") ) return;
    if(!this_object()->visible(this_player())) return;
    if(this_player()->query("level") > 25 && userp(this_player()) )
        this_object()->kill_ob(this_player());
}
void die()
{
    object ob;
    if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
    if( !ob ) {
        ::die();
        return;
    }

    ob->add_temp("BIG_GHOST_WAR", 3);

    if(ob->query_temp("BIG_GHOST_WAR") > 2 ) {
        ob->add("popularity",1);                // �[�n��
        tell_object(ob, HIG"(�]���A�����F"+this_object()->query("name")+"�A�ҥH�A�o��F 1 �I�n��C)\n"NOR);
        ob->add_temp("BIG_GHOST_WAR", -3);
    }
    ::die();
    return;
}
