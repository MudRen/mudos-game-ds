#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��", ({ "hong","hong" }) );
        set("race","human");
        set("gender", "�k��");
        set("level",28);
        set("age",25);
        set("evil",-15);
        set("title",HIR"�t���ڨ�"NOR);
        set("long",@LONG
�o���y�e�Q���s����ù����B��F�j�����A�O�H�����D�o��
�u�����ءA�ڻ��ݹL�o�u���ت��H���w����o�����N���U�A
�̾ժ����O�N�����E�����Y�����y�A�A�H��g���覡������
�H�C
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/sl_mask")->wear();
        carry_object(__DIR__"../wp/wind_soul")->wield();
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tdod;
    if(!me || !target) return 0;
    if(random(4) ) return 0;
    tdex=target->query_dex();
    tdod=target->query_skill("dodge");
    if(random(hitchance/2) > tdex+tdod)
    {
      message_vision("\n"
                    +HIR"$N�N�����������ƤQ�������y�A�E���b����W......\n"
                    +"$N����@���A�ƤQ�����y�p�Ѥk�����g�V$n......\n"
                    +"$n�Q�\\�h�����y�����A���줣�p���ˮ`�I�I�I\n\n"NOR
                    ,me,target);
      target->receive_damage("hp",random(30)+random(30)+random(30)+random(30)+random(30));
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIR"$N�N�����������ƤQ�������y�A�E���b����W......\n"
                    +"$N����@���A�ƤQ�����y�p�Ѥk�����g�V$n......\n"
                    +"$n�ӱ��a�F����{�A���M�{�L�j���������A�����M�Q�����@��U......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",random(30)+random(30));
      return 1;
    }
}
