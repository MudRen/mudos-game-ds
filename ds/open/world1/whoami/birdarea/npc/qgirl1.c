#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�p�k��" , ({ "litte girl" , "girl"}) );
        set("title",HIR"�g�ɤ�"NOR);
        set("level",1);
        set("race","human");
        set("gender","�k��");
        set("age",5+random(5));
        set("max_hp",10000);
        set("hp",1);  
        set("long","�b�A���e���O�@�Ӧ~�����p�k�ġA�������W�ٯd�ۭ襴�����˲�"
                   "�A�ݨӦo�N�O�E���F�I\n");
        set("attitude","aggressive");
        setup();
}

void die()
{ 
    object me=this_object();
    object inv=environment(me);
    message("world:world1:vision", 
    HIR"\n\t\t�F�_�誺�ѪŰ{�L�@�D������~��\n"NOR,users()); 
"/open/world1/whoami/birdarea/fox19"->add("exits", 
(["out" :"/open/world1/whoami/birdarea/fox18.c"]));
message_vision(HIR"\n\t���H���@"HIW"�E"HIY"��"NOR"�ש�{�X������ΤF�I\n\n"NOR,
this_player());  
    this_player()->delete_temp("can_k");
    new(__DIR__"kfox")->move(inv);
    destruct(me);
    return;
}

