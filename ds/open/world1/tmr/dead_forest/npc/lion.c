#include <npc.h>

void create()
{
        set_name( "����" ,  ({ "huge lion" , "lion" }) );
        set_race("beast");
        set("verbs", ({ "bite", "claw","crash"}) );
        set("age", 20 );
        set("long",@LONG
�@�@�o�O�@���������`���j����l�A����۱z�i�R�۾W�U�����l�A��֤j�f
���S�X���j���y���A���V�̤��ɵo�X�C�q�n�A���ؤ����������n�ۧA�@�C
LONG
        );
        set("attitude", "aggressive");
        set("title","���`����");
        set_skill("unarmed" , 100 );
        set_skill("dodge" , 100 );
        set_skill("parry" , 100 );
        set_attr( "cor" , 25 );
        set_attr( "strength" , 50 );
        set_stat_maximum("hp" , 800);
        set_stat_maximum("nina" , 300);
        setup();
        set_level(15);
        do_heal();
        //carry_object(__DIR__"obj/QuestJawei.c");
        carry_object(__DIR__"obj/lion-jerk.c");
}
