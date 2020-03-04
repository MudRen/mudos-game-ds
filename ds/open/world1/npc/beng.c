#include <ansi.h>

inherit NPC;
void create()
{
        set_name("�y", ({ "beng","beng" }) );
        set("race","human");
        set("gender", "�k��");
        set("level",30);
        set("age",32);
        set("evil",-15);
        set("title",HIR"�t�����"NOR);
        set("long",@LONG
�ϥ��@�l���t���Ϫ̡A�ĦX�F�������¤O�H���@�l���F�ʡA
�гy�X�༹���Ů�y���u�Ū��ޥ��A���H��L�Τ����C
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/bh_leg")->wear();
        carry_object(__DIR__"../wp/cv_whip")->wield();
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(100) > 10) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if( !me->query_temp("weapon") ) return 0;
    if( environment(me) != environment(this_object()) ) return 0;
    if(random(hitchance/2) > tdex+tcon)
    {
      message_vision("\n"
                    +HIC"$N�@���@�l�A�ƥX�@�D�u�Ūi�ĦV$n......\n"
                    +"$n�èS����ı��u�Ūi���L�Χ����A�Q���������F......\n"
                    +"$n�A��g�Q�A�ˤf�`�Ψ���......\n\n"NOR
                    ,me,target);
      target->receive_damage("hp",100+random(30), this_object());
      target->receive_wound("body",5);
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIR"$N�@���@�l�A�ƥX�@�D�u�Ūi�ĦV$n......\n"
                    +"$nĵı��$N���i�ȧ����A�ֳt������{�h......\n"
                    +"$n�ήɪ��j�סA�u���u�Ūi���}�֦סA���P������......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",random(50), this_object());
      return 1;
    }
}