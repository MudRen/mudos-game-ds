#include <ansi.h>
inherit NPC ;
inherit SELLMAN ;
void create()
{
        set_name("�q�̥�" , ({ "good doctor","doctor" }) );
        set("title",HIG "����^�K" NOR);
        set("level",5);
        set("race","�H��");
         set("gender","�k��");
        set("age", 54);
        set("no_fight",1);
        set("long",@LONG
���b�A���e�O������p���E���x�d, �L����N�i�H���O���G���, ����
������������g, �L�@�w�i�H��n, �]�]���L���Ӻٸ��s����^�K.
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





