// thousand-hair �T�d�дo��
// ������ �i���ޯ�
// tmr 2006/10/07

#include <ansi.h>
#define THE_WHIP      "/open/always/thousand-hair.c"

inherit SSERVER;
inherit SKILL;

int clone_whip(object me);

int exert(object me, object target, string arg)
{
        int cost;

    if(me->is_fighting() )
        return notify_fail("�A���b�԰����C\n");

    cost = 100 + me->query_skill("thousand-hair")*3 ;

    if( me->query("ap") < cost )
        return notify_fail("�A�����l�����A�L�k�ϥΡu�T�d�дo���v�C\n");

    message_vision(
        GRN"$N���X�a�ۥX�@�q�q�n�G�u���_�T�d�дo�� �Ƨ@���y�J�կv�v\n" NOR
        ,me);
    
    me->receive_damage("ap",cost );
    me->start_busy(2);
    call_out("clone_whip",3, me);
    return 1;
}

int clone_whip(object me)
{
    object whip, ob;
    int sk, dex,dmg;
    if( !me ) return 0;
    if( me->is_fighting() )
        return notify_fail("����Ƥ]�S�o��...\n");
    
    sk = me->query_skill("thousand-hair");
    dex = me->query_dex();

    if( objectp(ob = present("thousand-hair", me) )  ) {
        message_vision("���G����Ƥ]�S�o��.....\n",me);
            return 1;
    }
    
    // �@���u�঳�@���T�d�дo��
    if( objectp(ob = present("THOUSAND_HAIR_WHIP", me) )  ) {
        message_vision("���G����Ƥ]�S�o��.....\n",me);
        return 1;
    }
        
        // ��@��whip �ӷ��¦
    if( !objectp(ob = present("whip", me) )  ) {
        message_vision("���G����Ƥ]�S�o��.....\n",me);
            return 1;
    }
    
    whip=new(THE_WHIP);
    
    if(!whip->move(me) ) {
            message_vision("���G�n���o�ͤ���j���D�F�A�Чֳq���Ův�ѨM�A���¡C\n",me);
            return 1;
    }

    if(!whip->move(me) ) {
                message_vision("���G����Ƥ]�S�o��.....\n",me);
                return 1;
        }
        
        dmg = ob->query("weapon_prop/damage")*(1.0 + sk*0.005);
        whip->set("weapon_prop/damage", dmg);
        whip->set("weapon_prop/dex", sk/20);
         whip->set("weapon_prop/con", sk/20);
    message_vision(HIM "$N�ŤU�@�������Y�v�A�B�Τߪk�A�N�v����$n"HIM"�b�|�b�@�_�A�̫ᳺ�Φ��@�����F�C�ت����@�I�I\n" NOR, me, ob);
      me->improve_skill("thousand-hair", dex + random(dex) );
    ob->unequip();  // unwield whip
    destruct(ob);       // �R���ª��@�l

    return 1;
}

int improve_limite(object ob)
{
    if(ob->query_dex() < 80) return 70;
    return 100;
}


