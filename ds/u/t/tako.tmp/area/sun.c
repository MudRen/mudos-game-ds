#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIY"����"NOR, ({ "hown heart","heart" }) );
        set("level",40);
        set("combat_exp",20000);
set("exp",20000);
        set("evil",200);
        set("long",@LONG
   ���ߥ��O�Ӿ��ӶԾĪ��A��,�U�a,�U�d,�U�l
�k,�S������������L,�O�H�H�������j�k�H,��
�y,�A��,�D��,�˼˺�q,�̳��w�ΪŤ�,����D�`
���F��,���O���@��,�L��˪L�̥h���y,�~��E
�׷��y��,�V�e���F�L�h,�E�׵oı�ߨ��ਭ
��_�F ��z �V�e����,���O�o�o�ͤF�@���,�E
�רC�C�n�夤���߮�,�o�C�C�Q���ߥ����⼷�}
,���ߨ�������,�޻L�N�],�E�׫o�r�l�b��,�t��
�S���E�ק֪��L,���W�N�Q�l�W�F,�E�רϥX�F��
�㪺�@��,���߸��פ���,�A��������Q�˼��},��
�o�ا���,�w�g�Q�E�׬ݯ}�F, ��z �ƯB���w,����
�@���p��,�Q ��z �Ψ�I��, ��z �}�l�⨸�O��
�_���e������餺,�L���F�h�[,���������ܬ�,��
�׶��_,�E�ר��L����,���L����U,�Q ��z �P�V��
�L,�]�n�֪������F,�E�׽絹�L�@��a���L,���W
��ģ���,�q���N��۰E�פF 
LONG          );
        set("age",1946827);
        set("attitude","killer");
        set("gender","�k��");
        set("title",HIG"�E���@��"NOR);
        set_skill("unarmed",80);
        set_skill("dodge",100);
        set_skill("parry",80);
        set("chat_chance_combat",10);
        set("chat_msg_combat", ({
"���߻�:�@�r ~ ~ ~ ~ �@�r ~ ~ ~ ~�C\n\n",
"���߻�:�i�H���˸���..�Z��������.. !! �C\n\n"                       }) );
       setup();
       carry_object("/u/t/tako/sunfist.c")->wield();
}





