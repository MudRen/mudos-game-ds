#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�P�@", ({ "lieh shen","shen" }) );
        set("race","human");
        set("gender", "�k��");
        set("level",43);
        set("age",45);
        set("evil",-20);
        set("title",HIR"�t���s��"NOR);
        set("long",@LONG
���������o���A�@�y�Q�𪺤��~�k�l�A���Ӫ������A�o�F��
�٦סA�b�b��ܥX�o�ӤH���׬����z�C����A�ݨ�L���W��
�ܪ��ܭ��W�L���K�[���s���лx�A�~���D�L�N�O�t���Ϫ̤�
���C
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/bc_cloak")->wear();
        carry_object(__DIR__"../wp/soon_flame")->wield();
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
                    +HIR"$N�@�n�ɳܡA�����W�U���_�X���ӡA�{�p�@�Ӥ��H......\n"
                    +"$N���t�a��$n���W�h�A$n�����W�U�]���ۤ��F�I�I\n"
                    +"$n�Q���N�o�M�����......\n\n"NOR
                    ,me,target);
      target->receive_damage("hp",200+random(150), this_object());
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIR"$N�@�n�ɳܡA�����W�U���_�X���ӡA�{�p�@�Ӥ��H......\n"
                    +"$N���t�a��$n�A���O$n�b�d�v�@�v���ک��k��{......\n"
                    +"$n���M�{�L$N�����������A���o�Q$N���W�����`�ˤF......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",100+random(50), this_object());
      return 1;
    }
}

