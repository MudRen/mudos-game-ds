/*
�r�N - �~�Ьr�g (shouyu-poison) 

       �Q�ʧޯ� �C 20 sk ���@�Ӷ��q �C�L�@�Ӷ��q �r���¤O�N�|���� �åB����ϥηs���r��
                
          �_���H�r(cold-poison)      sk 20  ����ʫd��ĤH ap & mp & hp            (�C���d�� sk*2) 
          �_�����r(hot-poison)       sk 40  �d��ĤH max_hp & max_mp & max_ap      (�T�w�� sk*10)     
          ���u�۬r(gu-poison)        sk 60  �d��ĤH str & con & int & dex         (�T�w�� sk/10) 
          �T��������(scotoad-poison) sk 80  �d��ĤH �����O & ���m�O & ���F��ܤO  (�T�w�� sk/2) 
          �Ʀ�G���r(body-decayed)   sk 100 ���v�ʫd��ĤH merits                  (bar bio wit tec sou �ܤ@�ئ��@�I) 
           
           ����ɶ��� tec �M�w�åB���_�I�i�|�������֭p 
           �R���v�ѥ��� skills �M��� dodge & dex �M�w 
           �r�ܩʤӧC �|�Q�Ͼ� 
*/

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

int exert(object me, object target, string arg)
{
    string msg;

    if(arg=="off" )
    {
        if( me->query_skill_mapped("combat")!="shouyu-poison") return notify_fail("�A�èS���ϥΡy�~�Ьr�g�z�C\n");
        me->map_skill("combat");
        me->reset_action();
        message_vision(CYN "�����¶�b$N�P�D���@���������}�A�_��޲����Pı�]�������L�v�L�ܡC\n" NOR,me);
        write("�ޯ�y�~�Ьr�g�z�w�����C\n");
        return 1;
    }
//    �����a���w�ۤv�Q�I�񪺬r�N 
    if( me->query_skill_mapped("combat")=="shouyu-poison"){
        switch( arg ){
                case "cold-poison":
                     if( me->query_skill("shouyu-poison") < 19 ) return notify_fail("�A���~�Ьr�g���⮩�٤����`�p�A�|������I�i�_���H�r�C\n"); 
                     msg += HIB "��¶��$N�|�P���@���A�ܦ���޲����`�Ŧ�F�K�K�K\n" NOR;
                     if( me->query_skill("anti_poison") < 19 ) target->apply_condition(arg, 1+random(5));      
                     me -> set_temp("shouyu-poison", arg);
                     break;
                case "hot-poison":
                     if( me->query_skill("shouyu-poison") < 39 ) return notify_fail("�A���~�Ьr�g���⮩�٤����`�p�A�|������I�i�_�����r�C\n"); 
                     msg += RED "��¶��$N�|�P���@���A�ܦ���޲����`����F�K�K�K\n" NOR;
                     if( me->query_skill("anti_poison") < 39 ) target->apply_condition(arg, 1+random(5));
                     me -> set_temp("shouyu-poison", arg);
                     break;
                case "gu-poison":
                     if( me->query_skill("shouyu-poison") < 59 ) return notify_fail("�A���~�Ьr�g���⮩�٤����`�p�A�|������I�i���u�۬r�C\n"); 
                     msg += MAG "��¶��$N�|�P���@���A�ܦ���޲����`����F�K�K�K\n" NOR;
                     if( me->query_skill("anti_poison") < 59 ) target->apply_condition(arg, 1+random(5));
                     me -> set_temp("shouyu-poison", arg);
                     break;
                case "scotoad-poison":
                     if( me->query_skill("shouyu-poison") < 79 ) return notify_fail("�A���~�Ьr�g���⮩�٤����`�p�A�|������I�i�T�������ϡC\n"); 
                     msg += BLK+GRN "��¶��$N�|�P���@���A�ܦ���޲����`���F�K�K�K\n" NOR;
                     if( me->query_skill("anti_poison") < 79 ) target->apply_condition(arg, 1+random(5));
                     me -> set_temp("shouyu-poison", arg);
                     break;
                case "body-decayed":
                     if( me->query_skill("shouyu-poison") < 99 ) return notify_fail("�A���~�Ьr�g���⮩�٤����`�p�A�|������I�i�Ʀ�G���r�C\n"); 
                     msg += HIW+BLK "��¶��$N�|�P���@���A�ܦ���޲����`�¦�F�K�K�K\n" NOR;
                     if( me->query_skill("anti_poison") < 99 ) target->apply_condition(arg, 1+random(5));
                     me -> set_temp("shouyu-poison", arg);
                     break;
                     }
                message_vision(msg, me);
    }

    if(me->query("ap")<50 || me->query("hp")<50) return notify_fail("�A�����骬�L�k�ϥΡy�~�Ьr�g �z�C\n");
    if(!me->skill_active( "shouyu-poison",(: call_other, __FILE__, "delay", me :), 4)) return notify_fail("�A���~�Ьr�g���۰ʧ@�٨S�����C\n");

    me->map_skill("combat", "shouyu-poison"); 
    me->reset_action();

    message_vision(MAG "$N�����g�߰f��A�~�Ьr�g���ĤO�b$N���|�P�����X���A$N�P�D���G�޲����@���C\n" NOR,me);
    me->receive_damage("ap",15);
    me->receive_damage("hp",30);
    me->start_busy(1);
    return 1;
}

void delay(object me)
{
    object target;
    string msg, arg = me->query_temp("shouyu-poison");
    int tec, sk, effect;
    if( !me ) return;
    if( me->query_skill_mapped("combat")!="shouyu-poison" ) return; 
    me->receive_damage("ap", 15); //���ަ����S���R���A���� ap 15 
    if( me->query("ap") < 50 )
    {
        me->map_skill("combat");
        me->reset_action();
        message_vision(CYN "�����¶�b$N�P�D���@���������}�A�_��޲����Pı�]�������L�v�L�ܡC\n" NOR, me);
        tell_object(me, "�A����O�����L�k�~��ϥΡy�~�Ьr�g�z�C\n");
        return ;
    }
    if( me->is_fighting() ){
        if( !target ) target = offensive_target(me);
        tec = me->query_tec();
        sk = me->query_skill("shouyu-poison");
//shouyu-poison �����m�׼W�[���P�� anti-poison �]�|��۴��ɼ��m�� 
        me -> improve_skill("shouyu-poison", 1+random(me->query_int()));
        me -> improve_skill("anti_poison", me->query_int()*2);
//�o�ʪ����v��
        if( random(me->query_tec()*4) < random(20) ) return;        
        msg += HIC "�಴����¶�b$N�|�P��������$n�ɬ��ӥh�A";
        if( (sk*2) > (random(target->query_dex()/2)+random(target->query_skill("dodge"))) ){
            msg += "$n�@�ӫ鯫�A�N�Q���������ͥͪ��]�F�U�h�C\n" NOR;
            if( arg == "cold-poison" ) effect = tec*2;
            if( arg == "hot-poison" ) effect = tec*2;
            if( arg == "gu-poison" ) effect = tec;
            if( arg == "scotoad-poison" ) effect = tec/2;
            if( arg == "body-decayed" ) effect = tec/4;
            if( target->query_temp("shouyu-poison/"+arg+"/effect") < sk ) target->set_temp("shouyu-poison/"+arg+"/effect", sk); 
            effect += target->query_condition(arg);
            if( effect > 49 ) effect = 49; //�̦h49 tick 
            target->apply_condition(arg, effect);             
            target->receive_damage("hp", random(effect)+1); //�@�I�I���r�� 
        } else {
            msg += "$n�����@�D�A�{�L�F�o�ӭn�R������C\n" NOR; 
          }         
        message_vision(msg, me, target);
        }
        me->skill_active( "shouyu-poison",(: call_other, __FILE__, "delay", me :), 4);
}

int valid_learn(object me){ return 1; }
int practice_skill(object me){ return 1; }

int improve_limite(object me)
{
    if( !me->query("quest/shouyu-poison") ){ return 75; }
    else { return 100; }
}


