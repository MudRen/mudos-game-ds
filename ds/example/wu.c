#include <ansi.h>

inherit NPC;

void create()
{
        set_name("���t", ({ "wu bonze","bonze" }) );
        set("race","human");
        set("gender", "�k��");
        set("level",39);
        set("age",20);
        set("evil",-20);
        set("attitude", "peaceful");
        set("title",HIY"�t"BLK"�]"HIW"��"NOR);
        set("long",@LONG
�b�����ԧФ��A�������F�L�@�Ӯv�S�ݦn�ͪ��@��v�S�A�L
�Ҵo�U���A�q������ॢ�z�ʤS�ˤF�\�h�x���W�W�U�U���v
�S�̡A�b���Ƥ���K�Q��V�j�v����ۡA�ä����Ѥ�C

LONG
);
        set_skill("quanyin-steps",80);
        set_skill("buddha-force",80);
        set_skill("wuchen-staff",80);
        map_skill("staff","wuchen-staff");
        
        

        setup();
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
       HIW"\n ���t��:\n\n\t�v���ڪ��D�ڿ��F�ЧA��̧ڡC\n\n"+NOR
                ,users());
                ob->add("popularity",2); 
       tell_object(ob,HIW"(�A�����F���t�A�ҥH�o��F 2 �I�n��C)"NOR);
                ::die();
                //destruct(this_object());
                return;
}


int special_attack(object me,object target,int hitchance)
{
        if(!me || !target) return 0;
        if(random(4)) return 0;
        if(me->query("mp")<21) return 0;
        message_vision(HIW"$N"HIY"���ۻy�A���W�S�R���F���O�C\n"NOR,me,target);
        me->receive_heal("hp",210+random(99) );
        me->receive_damage("mp",21);
        me->add_busy(1);
        return 1;
}

