#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIR"����"NOR, ({ "loa hone","hone" }) );
        set("level",35);
        set("combat_exp",20000);
set("exp",20000);
        set("evil",200);
        set("long",@LONG
�줣�O�E�ת���U,�]����E�ץX�ͤJ�����h
�i�o�ѤU,�Z�\���b�E�פ��U,��E�׳ФU�F��
�ת����Z,�P��������˥S�̮t���O���@��,�E
�ץ��y�F��Ĥ@���L ��z ,�}�l�ॢ�F�H��,��
�p���_,�X�ʸU�����ͩR,�N�G���b�L����W,�Z
�\���O�z�W���L,�]�X�׮t�I�⸨���e�W���u,
��������,�W�e����E��,�S�ӱ�������,�ƫ᪺
�E�ײM���F,�o�{�F�L���ா�^����,��O�E��
�D�U��z�����O,��E�פQ�����@���ةR�����F
����,�������O�]��z�ӦA�ͪ�,�ҥH��������
����,�]�Q ��z �P�V�F,�E�פ]���y�F�@��a��
�L,���W�������C,�]�Q���O�P�V���L,�A�׬��E
�׺٦�,�ͩR�����p,�N���i�}
LONG
);  

      set("age",1645284);
        set("attitude","killer");
        set("gender","�k��");
        set("title",HIG"�E���@��"NOR);
        set_skill("unarmed",80);
        set_skill("dodge",100);
        set_skill("parry",80);
        set_skill("sword",100);
        set("chat_chance_combat",10);
        set("chat_msg_combat", ({
"������:�@�r ~ ~ ~ ~ �@�r ~ ~ ~ ~�C\n\n",
"������:�i�c!! �����Z�Ѥl��.. !! �C\n\n"                       }) );
       setup();
       carry_object("/u/t/tako/red@sword.c")->wield();
}



