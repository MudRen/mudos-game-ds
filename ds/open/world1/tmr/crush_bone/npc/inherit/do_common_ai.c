#include <ansi.h>

void do_common_issue(object me);        // �ϥΩ���O

void c_race_strength(object me);   // �j�ƨt
void c_race_emit(object me);       // ��X�t
void c_race_variation(object me);  // �ܤƨt
void c_race_operation(object me);  // �ާ@�t
void c_race_concrete(object me);   // ��{�t
void c_race_specical(object me);   // �S��t

void do_issue(object me)
{
    object enemy;

    if( !me ) return;
    if( !objectp(me) ) return;

    switch( me->query_race() ) {
        case "strength":  c_race_strength(me);  break;
        case "emit":      c_race_emit(me);      break;
        case "variation": c_race_variation(me); break;
        case "operation": c_race_operation(me); break;
        case "concrete":  c_race_concrete(me);  break;
        case "specical":  c_race_specical(me);  break;
    }
}

void c_race_strength(object me)    // �j�ƨt
{
    switch( me->skill_mapped("psychical") ) {
        default: break;
    }
}

void c_race_emit(object me)        // ��X�t
{
    switch( me->skill_mapped("psychical") ) {
        default: break;
    }
}

void c_race_variation(object me)   // �ܤƨt
{
    switch( me->skill_mapped("psychical") ) {
        default: break;
    }
}

void c_race_operation(object me)   // �ާ@�t
{
    switch( me->skill_mapped("psychical") ) {
        case "dragon four feat":         // skill: �a�s�|���Z
          command("issue dragon-kiss");
        break;
    }
}

void c_race_concrete(object me)    // ��{�t
{
    switch( me->skill_mapped("psychical") ) {
        case "chamber nina-fish":        // skill: �K�ǩ���
            if( random(100) > 50 ) command("issue concrete");
            else if( me->query_temp("damage_shield/hp") <= 0 ) command("issue fish-scale");
        break;
    }
}

void c_race_specical(object me)    // �S��t
{
    switch( me->skill_mapped("psychical") ) {
        case "the-time":
            command("issue strength");
        break;
    }
}
