#include <ansi.h>
inherit NPC;
void create()
{
       set_name("���H��",({"eat people flower","flower"}));
        set("level",30+random(15));
        set("race", "���~");
        set("age", 100);
        set("long", "�@���|�Y�H���j��A���C���⪺�D�`�}�G�C\n");
        set("limbs", ({ "�ᦷ", "�K��", "���F", "�K��"}) );
        set("verbs", ({ "bite", "crash"}) );
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

