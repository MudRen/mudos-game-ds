#include <ansi.h>
inherit NPC;
void create()
{
       set_name("���",({"treeer frog","frog"}));
        set("level",30+random(20));
        set("race", "���~");
        set("age", 23);
        set("long", "�o�O�@���C�⪺�p��C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}"}) );
        set("verbs", ({ "bite","crash"}) );
        setup();
}
void die()
{
        object ob,newob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        switch( random(1000) ) {
        case 0: 
        newob=new(__DIR__"obj/scroll");
        newob->move(this_object());
        break;
        case 1..200:
        ob->add("popularity",1);
        tell_object(ob,HIG"�A�o��F 1 �I�n��\n"NOR);
        break;
        default:
        break;
        }
        ::die();
        return;
}

