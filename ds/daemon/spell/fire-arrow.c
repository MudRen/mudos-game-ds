#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cast(object me, object target)
{
    int sk = me->query_spell("fire_arrows");
    int cost = 20 + sk*8;

    if( !me->is_fighting() ) return notify_fail("�A���b�԰����C\n");
    if( (int)me->query("mp") <  cost )
        return notify_fail("�A���믫�O�����F�C\n");
    me->add("sp", -cost);
    message_vision(
        HIY"$N"HIY"�I�i�u���K�]�}�v�C\n"NOR
        HIY"$N"HIY"��X�@�Τ��K�}�B�b�Ť��A�Φ��@�ӥ��j�����K�}�C\n"NOR
        HIY"$N"HIY"�@�Ԥ}���A�q���K�}�Q�԰ʪ����W�X�{�E�K���K�b�C\n"NOR
        , me);
    me->start_busy(2);
    call_out("start",1, me);
    return 1;
}

int start( object me ) //�}�l�������禡�W�٥����Τ@
{
    int damage, i, j, m, sk;
    object *inv;
    //�bdelay����,�n�Ҽ{�����ܤ�
    if(!me) return 0;
    inv = me->query_enemy();
    m = me->query_might();
    i = sizeof(inv);

    message_vision(HIY"\n$N��}�}���A�L�Ƥ��K�b�I�S�ӥX�A��V�ĤH�}�a�C\n"NOR, me);
    sk = me->query_spell("fire_arrows");
    j = 5 + sk;

    if( j > 15 ) j = 15;

    while( j ) {
        i = random(sizeof(inv));
        if( random(100) < 50 ) continue;
        damage = m/4 + (sk*25);
        damage /= 2;
        damage += random(damage);
        damage = inv[i]->receive_magic_damage("hp", damage, me, "fire");
        message_vision(
            HIR"$N"HIR"�Q�ƪK���K�b�鶴�ӹL�A�q�ˤf���_�X���������A"NOR
            HIR"�y��$N "HIY+ damage + HIR" �I���K�ˮ`�C\n"NOR
            , inv[i]);
        inv[i]->kill_ob(me);      //�����ʪk�N�[�W�o�@��
        COMBAT_D->report_status(inv[i]);       //�[�W�o��i�H���target�����d���p
        j--;
    }
    return 1;
}

string name()
{
    return "���K�]�}";
}

