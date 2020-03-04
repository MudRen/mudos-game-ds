/* write by -Acme-
*/

#include <ansi.h>
inherit NPC;
inherit __DIR__"inherit/heal.c";
inherit __DIR__"inherit/attack.c";
void create()
{
    int i;
    set_name( "�R�L��", ({ "ever life ghost", "ghost" }) );
    set("level", 45);

    set_skill("dodge", 100);
    set_skill("parry", 100);
    set_skill("unarmed", 100);
    set_skill("blade", 100);

    set("long" ,"���N�A�Y�W���ۤ@�ﰭ���A�����վv�A�C���y���A�Q���~�H�C\n");
    set("age", random(100)+100);
    set("title", GRN "�s�]�ûR" NOR);
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

    carry_object(__DIR__"wp/s_blade")->wield();
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

    ob->add("popularity", 3);                // �[�n��
    tell_object(ob, HIG"(�]���A�����F"+this_object()->query("name")+"�A�ҥH�A�o��F 3 �I�n��C)\n"NOR);


    ::die();
    return;
}

int receive_damage(string type, int damage, object who)
{
    if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
    if( type!="hp" && type!="mp" && type!="ap" )
        error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
    if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

    switch( random(100) ) {
        case 0..10:
            if( objectp(who) )
            message_vision(YEL"$N�B�l�ϥX�u�l�v�l�A�n�N$n����է����l���C"NOR, this_object(), who);
            else message_vision(YEL"$N�B�l�ϥX�u�l�v�l�A�n�N��է����l���C"NOR, this_object());

            this_object()->receive_heal("hp", damage);
            damage = 0;
            break;
        case 11..25:
            if( objectp(who) )
            message_vision(YEL"$N�B�l�ϥX�u��v�l�A�N$n����թ��Ǥ@�a�C"NOR, this_object(), who);
            else message_vision(YEL"$N�B�l�ϥX�u��v�l�A�N��թ��Ǥ@�a�C"NOR, this_object());

            damage /= random(damage)+1;
            if( objectp(who) ) who->start_busy(random(3)+1);
            break;
        case 26..40:
            if( objectp(who) )
            message_vision(YEL"$N�B�l�ϥX�u�s�v�l�A�Q�n�Ƹ�$n����աC"NOR, this_object(), who);
            else message_vision(YEL"$N�B�l�ϥX�u�s�v�l�A�Q�n�Ƹѧ�աC"NOR, this_object());
            damage -= random(damage)+1;
            break;
    }

    if( damage < 0 ) damage = 0;
    if( objectp(who) ) ::receive_damage(type, damage, who);
    else ::receive_damage(type, damage);
    return damage;
}
