#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��ɣ", ({ "swe gui","gui" }) );
        set("race","human");
        set("gender", "�k��");
        set("level",28);
        set("age",20);
        set("evil",-15);
        set("title",HIR"�t���b��"NOR);
        set("long",@LONG
�~�ȤG�Q�N�֦��F�u�t���Ϫ̡v���ٸ��A�ժ����O�N������
���M�b�ϥΡC�t���Ϫ̬O�ϥΪ��N�̪��̰��ٸ��A�d�~�H��
�Ȧ����ּƤH��o�즹�@�ٸ��C
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/gs_waist")->wear();
        carry_object(__DIR__"../wp/flame_blade")->wield();
}

int special_attack(object me,object target,int hitchance)
{

    int tdex; 
    if(!me || !target) return 0;
    if(random(4)) return 0;
    tdex=target->query_dex();
    if(random(hitchance/3) > tdex)
    {
      message_vision("\n"
                    +HIR"$N�����F�X�y�G��A�N�����w�w���E�����M......\n"
                    +"$N�j�ܤ@�n�A�����X�{�b$n���e�A������F$n�@�M......\n"
                    +"$n�P�ɨ���M�˸�N�ˡA�h�W���w......\n\n"NOR
                    ,me,target);
      target->receive_damage("hp",80+random(30));
      target->apply_condition("blooding", target->query_condition("blooding")+1);
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIR"$N�����F�X�y�G��A�N�����w�w���E�����M......\n"
                    +"$N�j�ܤ@�n�A�����X�{�b$n���e�A$n�@��½�����L�F����......\n"
                    +"$n�I�I���L�F�����A���]�~�X�F�@���N��......\n\n"NOR
                    ,me,target);      
      target->add_busy(1);
      return 1;
    }
}