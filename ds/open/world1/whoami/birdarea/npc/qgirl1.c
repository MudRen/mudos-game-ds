#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小女孩" , ({ "litte girl" , "girl"}) );
        set("title",HIR"狂暴中"NOR);
        set("level",1);
        set("race","human");
        set("gender","女性");
        set("age",5+random(5));
        set("max_hp",10000);
        set("hp",1);  
        set("long","在你眼前的是一個年輕的小女孩，它的身上還留著剛打鬥的傷痕"
                   "，看來她就是九尾了！\n");
        set("attitude","aggressive");
        setup();
}

void die()
{ 
    object me=this_object();
    object inv=environment(me);
    message("world:world1:vision", 
    HIR"\n\t\t東北方的天空閃過一道紅色光芒∼\n"NOR,users()); 
"/open/world1/whoami/birdarea/fox19"->add("exits", 
(["out" :"/open/world1/whoami/birdarea/fox18.c"]));
message_vision(HIR"\n\t殺人狐　"HIW"九"HIY"尾"NOR"終於現出它的原形了！\n\n"NOR,
this_player());  
    this_player()->delete_temp("can_k");
    new(__DIR__"kfox")->move(inv);
    destruct(me);
    return;
}

