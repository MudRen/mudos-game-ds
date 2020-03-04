#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIR"���Ƥ�"NOR, ({ "ant king","king" }) );
        set("long",@LONG
���ӬO�@���p����, �X�d�~�e�i��O����Y�Ǧ]��. ���餣����ı���ܤj
, �ٷ|����, �ۺٿ��Ƥ�,  ���O�Q�j�N���i�h�Ҿ�, ���b�@���Ϋ�����, 
�����D���h�֦~�S�X��, �U�ʤ]�ܪ����ݵL��C
LONG
);  
        set("gender", "�k��");  
        set("race", "beast");
        set("attitude","aggressive");
        set("level",50);
        set("age",6045); 
        set("limbs", ({ "�Y��", "����","�ݳ�","����","�}��" }) );  
        add("addition_armor",600);
        add("addition_damage",600);      
        set("evil",-20);
        set("title",HIG"�Ƥ�����"NOR); 
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("combat",100);
        set("combat_exp",898745);
        set("max_exp",50000);
        set("max_hp",50000);
     setup(); 
        carry_object(__DIR__"redarmor")->wear(); 
        carry_object(__DIR__"redtooth");
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
                    +HIY"$N��$n����V�R�X�@�f�G��....\n"
                    +"�� ~ ~ �����V$n........�I�I\n"
                    +"$n���Q�{���A�������ӺC, �Q�쨭�W.....\n\n"
                    +HIR"�y��$n�@�B�G�k\n\n"NOR
                    ,me,target);
      target->receive_damage("hp",300+random(200), this_object());
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIY"$N��$n����V�R�X�@�f�G��$N....\n"
                    +"�� ~ ~ �����V$n........�I�I\n"
                    +"$n���T�B�k�T�B���]�Ӷ]�h�A�{�L�F�j�b��, ��..�٬O�Q�p�b���Q��......\n\n"
                    +HIR"�y���@�B�G�k\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",200+random(100), this_object());
      return 1;
    }
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
    HIC"\n�i��     ���j"+HIR "���ݪ��u �� �� �� �v�Q"+ob->name(1)+"�o��i�h�����F�C\n\n"+NOR     
       ,users());
        ob->add("popularity",5); 
     message_vision( "$N"+HIC  "���e�L�ڱi���j�j���A"+HIW"�A���G�i�H�ݨ�@�ګG�������F�� . . "NOR ,this_object() ); 
        ::die();
        return;
}

