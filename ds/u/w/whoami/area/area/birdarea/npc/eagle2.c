#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���N",({"eagle"}));
        set("level",30+random(15));
        set("race", "���~");
        set("age", 8);
        set("long", "�o�O�@�����N�C\n");
        set("limbs", ({ "�Y��", "����", "�}", "����" }) );
        set("verbs", ({ "bite", "poke" }) );
        setup();
        carry_object(__DIR__"eq/fist.c")->wield();
}

void die()
{
        object ob,newob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        switch( random(1000) ) {
        case 0..200:
        ob->add("popularity",1);
        tell_object(ob,HIG"�A�o��F 1 �I�n��\n"NOR);
        break;
        case 201:
        newob=new(__DIR__"obj/scroll");
        newob->move(ob);
        break;
        default:
        break;
        }
        ::die();
        return;
}

