#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"���]���H"NOR, ({ "evil man-stone","stone" }) );
        set("long",@LONG
 ���]���H�A�O���F���J�I�j�ӸT�a���H�ҳ]�p���A���j
 �A�e�ӡA�������ۤl��K�a���X�A�����@�j�Ӫ����Ū�
 ���n�\�ڡC
LONG
);  
        set("gender", "�k��");  
        set("race", "beast");
        set("attitude","aggressive");
        set("level",40);
        set("age",2014);
        set("evil",-20);
        set("title",MAG"�g�c�u�@��"NOR); 
        set_skill("unarmed",100);
        set_skill("dodge",80);
        set_skill("combat",90);
        set("combat_exp",120000);
        set("max_exp",10000);
        set("max_hp",4000);
     setup(); 
        carry_object(__DIR__"stone-fist")->wield();
        carry_object(__DIR__"stone-armor")->wear();
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
                    +HIW"$N�ĤO�����ۤv���W��F�@�U�A����...���W���ۤl�z�g�}��....\n"
                    +"�ƥH�ʭp���ۤl���V$n........�I�I\n"
                    +"$n�W�i�L�ұ��A�w�ͥͳQ�{�o�����O��......\n\n"NOR
                    ,me,target);
      target->receive_damage("hp",200+random(180), this_object());
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIW"$N�ĤO�����ۤv���W��F�@�U�A����...���W���ۤl�z�g�}��....\n"
                    +"�ƥH�ʭp���ۤl���V$n........�I�I\n"
                    +"$n�������{�L$N���g���A�����٬O�Q�H�ۥ���......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",100+random(80), this_object());
      return 1;
    }
}

