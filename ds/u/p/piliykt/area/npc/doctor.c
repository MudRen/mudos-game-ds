#include <ansi.h>
inherit NPC ;
inherit SELLMAN ;
void create()
{
        set_name("郝依生" , ({ "good doctor","doctor" }) );
        set("title",HIG "妙手回春" NOR);
        set("level",5);
        set("race","人類");
         set("gender","男性");
        set("age", 54);
        set("no_fight",1);
        set("long",@LONG
站在你面前是神木村小藥舖的掌櫃, 他的醫術可以說是神乎其技, 不管
有任何疑難雜症, 他一定可以醫好, 也因此他有個稱號叫妙手回春.
LONG    
);
        set("sell_list",([
         __DIR__"obj/god_pill" : 15,
         __DIR__"obj/head_pill" : 20,
         __DIR__"obj/hand_pill" : 20,
         __DIR__"obj/body_pill" : 20,
         __DIR__"obj/foot_pill" : 20,
        ]) );
        setup();
}





