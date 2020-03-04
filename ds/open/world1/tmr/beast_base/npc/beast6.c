#include <npc.h>
#include <ansi.h>
#include <skill.h>

inherit __DIR__"inherit/action.c";

void die()
{
    object revive;
        object ob ;
    ob = last_damage_giver();
    if( !ob || ob==this_object() )
        if( !ob )
        {
                ::die();
                return;
        }

    if( this_object()->query("revive") > 0 ) {

        if( file_size("/d/beast_base/npc/beast6.c") < 0 ) return;
        if( catch(revive = new("/d/beast_base/npc/beast6.c")) ) return;

        message_vision(HIM"\n$N�˦a�s�z�F���n�A�B�R�F�@�a©���A�����S���F�_�ӡA�B���Χ��㥨�j�C\n\n"NOR, this_object());

        switch( this_object()->query("revive") ) {
            case 2:
                revive->set("revive", 1);
                revive->set_temp("apply/armor", 50);
                revive->move(environment(this_object()));
                return;
                break;

            case 1:
                revive->set("revive", 0);
                revive->set_temp("apply/armor", 100);
                revive->move(environment(this_object()));
                return;
                break;
            default:
                destruct(revive);
::die();
                return;
                break;
        }
    }

        message( "world",
        HIG "�i�y�H�s�D�j" HIW "�G ���������~�~�j���Q "+ob->name(1)+"(" + ob->query_id() + ") �����F�I�I\n"+NOR
        ,users() );
    ::die();
    return;
}

void create()
{
    set_name("�~�~�j��", ({ "the king of huge beast", "beast", "_94_NEW_YEAR_" }) );

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
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
        (: do_fight_issue, this_object(), "heavy_attack" :),
        (: do_fight_issue, this_object(), "multi_attack" :),
        (: do_fight_issue, this_object(), "heal" :),
    }) );

    set("vendetta_mark", "_94_NEW_YEAR_");

    // �_������
    set("revive", 2);

    setup();

    /* �ޯ�]�w */
    set_skill("dodge", 200);
    set_skill("parry", 200);
    set_skill("unarmed", 200);
    set_skill("psychical", 200);

    /* ���ɪ��A�]�w */
    advance_stat("hp", 5500 + random(2000));

    set_level(45);
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
