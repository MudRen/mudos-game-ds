#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�֭�", ({ "xu kong","kong" }) );
        set("race","human");
        set("gender", "�k��");
        set("level",38);
        set("age",70);
        set("evil",-15);
        set("title",HIR"�t���t��"NOR);
        set("long",@LONG
�G�p�B���y�K���A�վv�a�a�����Y�l�A�ݰ_�Ӯz���T���A�@
���_���A���O�i�O�p�ݥL�F�A�L�i�O�t���Ϫ̤����̨㴼�z
���H�A�ӥB�L�����N�¤O�i�O��r���L�N�h���W���C
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/gr_ring")->wear();
        carry_object(__DIR__"../wp/ds_staff")->wield();
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(4)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance/2) > tdex+tcon)
    {
      message_vision("\n"
                    +HIR"$N�����o�X�����A�L��j�j�������������Y�b�L�餺......\n"
                    +"$N�L�@�i�A�@�D�������W�g�X�A�e��F$n......\n"
                    +"$n�w�g�x�{���`�F......\n\n"NOR
                    ,me,target);
      target->receive_damage("hp",180+random(100),this_object());
      target->apply_condition("blooding", target->query_condition("blooding")+2);
      me->add_busy(3);
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIR"$N�����o�X�����A�L��j�j�������������Y�b�L�餺......\n"
                    +"$N�L�@�i�A�@�D�������W�g�X�A���S�����R������ҳy���������w�g�������F$n......\n"
                    +"$n�Q�������o���F�X�h......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",80+random(30),this_object());
      me->add_busy(1);
      return 1;
    }
}
