/* write by -Acme-
*/

#include <ansi.h>
inherit NPC;
inherit __DIR__"inherit/heal.c";
inherit __DIR__"inherit/attack.c";

void create()
{
    int i;
    set_name( "絕無期", ({ "over ghost", "ghost" }) );
    set("level", 45);

    set_skill("dodge", 100);
    set_skill("parry", 100);
    set_skill("unarmed", 100);
    set_skill("axe", 100);

    set("long" ,"鬼將，禿頭無毛，眼歪嘴斜，走路還同手同腳。\n");
    set("age", random(100)+100);
    set("title", GRN "群魔亂舞" NOR);
    set("chat_chance", 5);
    set("chat_msg", ({ (: random_move :) }) );
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: do_heal, this_object(), "hp" :),
        (: do_attack, this_object() :),
    }));

    setup();
    set_living_name("__BIG_GHOST_WAR__");
    switch( random(100) ) {
        case  0..20: carry_object(__DIR__"obj/ball");
        case 21..40: carry_object(__DIR__"obj/pill");
        case 41..90: carry_object(__DIR__"obj/drink"); break;
    }

    i = random(4)+3;
    while( i-- ) {
        switch( random(14) ) {
            case  0: carry_object(__DIR__"eq/armor")->wear(); break;
            case  1: carry_object(__DIR__"eq/boots")->wear(); break;
            case  2: carry_object(__DIR__"eq/cloth")->wear(); break;
            case  3: carry_object(__DIR__"eq/finger")->wear(); break;
            case  4: carry_object(__DIR__"eq/hands")->wear(); break;
            case  5: carry_object(__DIR__"eq/helmet")->wear(); break;
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

    carry_object(__DIR__"wp/s_axe")->wield();
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

    ob->add("popularity", 3);                // 加聲望
    tell_object(ob, HIG"(因為你殺死了"+this_object()->query("name")+"，所以你得到了 3 點聲望。)\n"NOR);


    ::die();
    return;
}

int receive_damage(string type, int damage, object who)
{
    if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
    if( type!="hp" && type!="mp" && type!="ap" )
        error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
    if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

    switch( random(100) ) {
        case 0..10:
            if( objectp(who) )
            message_vision(YEL"$N運勁使出「吸」勁，要將$n的攻勢完全吸收。"NOR, this_object(), who);
            else message_vision(YEL"$N運勁使出「吸」勁，要將攻勢完全吸收。"NOR, this_object());

            this_object()->receive_heal("hp", damage);
            damage = 0;
            break;
        case 11..25:
            if( objectp(who) )
            message_vision(YEL"$N運勁使出「纏」勁，將$n的攻勢往旁一帶。"NOR, this_object(), who);
            else message_vision(YEL"$N運勁使出「纏」勁，將攻勢往旁一帶。"NOR, this_object());

            damage /= random(damage)+1;
            if( objectp(who) ) who->start_busy(random(3)+1);
            break;
        case 26..40:
            if( objectp(who) )
            message_vision(YEL"$N運勁使出「御」勁，想要化解$n的攻勢。"NOR, this_object(), who);
            else message_vision(YEL"$N運勁使出「御」勁，想要化解攻勢。"NOR, this_object());
            damage -= random(damage)+1;
            break;
    }

    if( damage < 0 ) damage = 0;
    if( objectp(who) ) ::receive_damage(type, damage, who);
    else ::receive_damage(type, damage);
    return damage;
}
