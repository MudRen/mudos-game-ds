// �Ѱg�� - ���ʤ���

#include <npc.h>

void create()
{
        set_name( "�a����" ,  ({ "hell lion","lion" }) );
        set("verbs", ({ "bite", "claw","crash"}) );
        set("age", 200 );
        set("long",@LONG
�@�@�o�O�@���������`���j����l�A����۱z�i�R�۾W�U�����l�A��֤j�f
���S�X���j���y���A���V�̤��ɵo�X�C�q�n�A���ؤ����������n�ۧA�@�C�a
�����������v�ɰ��¦�A�@��������o�o���A��o���ˮ��ơC
LONG
        );
        set("attitude", "aggressive");
        set("title","���`����");
        set_skill("unarmed" , 150 );
        set_skill("dodge" , 100 );
        set_skill("parry" , 100 );
        set_attr( "cor" , 25 );
        set_attr( "strength" , 50 );
        set_stat_maximum("hp" , 800);
        set_stat_maximum("nina" , 500);
        set_race("beast");
        setup();
        set_level( 25 );
        carry_object(__DIR__"obj/lionhead.c")->wear();
}
