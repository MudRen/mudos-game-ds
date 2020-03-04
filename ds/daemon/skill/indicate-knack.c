// �e���� - �����߳Z
// -tmr 2007/05/03

#include <ansi.h>
#define SWORD_FIELD  __DIR__"wind-obj/sword-field"
#define NAME "�����߳Z"
#define SKILL_NAME "indicate-knack"

inherit SSERVER;
inherit SKILL;

int clone_field(object me, object target);

int exert(object me, object target, string arg)
{
     int sk,cost;

    sk = me->query_spell(SKILL_NAME);
    cost = 5 + sk/20;

    if( me->query("ap") < cost )
        return notify_fail("�A���]�O�����A�L�k�ϥ�"NAME"�C\n");
    if( !objectp(target) )
        return notify_fail("�A�Q�n�Τ���F��G�����C�}�H\n");

        if ( me->query_skill("star-sword") < 90
                 || me->query_skill("moon_force") < 90
                 || me->query_skill("indicate-knack") < 10
                 || me->query("level") < 40 )
        return notify_fail("�A����O�����A�ٵL�k�ϥΫ����߳Z�C\n");
        
    if( !target->is_weapon()
            || target->query("skill_type") != "sword"
            || target->query("equipped")
        || target->query_autoload()     // save wp �����
         || environment(target) != me     // ���b�ۤw���W���A�����
         )
        return notify_fail("�o�تF��L�k�G�����C�}�C\n");

        if( objectp(present("_INDICATE_KNACK_FIELD_", environment(me))) ) {
        return notify_fail("�o�̤w�g�G���@�ӫ����C�}�F�C\n");
        }

    message_vision(
        HIG "$N��X�@��$n"HIG"�A���C�Z�u�D�G�u�e��E���s�D��A�a��C�P����B�v\n" NOR,me, target);

    me->receive_damage("ap",cost );
    call_out("clone_field",3,me,target);
    me->start_busy(2);
    return 1;
}

void dest_field(object field) {
        if(!field) return;
        message_vision(HBK "���j�a�@�n�T�A$N"HBK"�N����l��a�}�H�������H���C\n"NOR, field);
        destruct(field);
}

int clone_field(object me, object target)
{
        int timeout;
          object field;
        string msg;
    if( !me ) return 0;

    field = new(SWORD_FIELD);
    if( !target 
                ||      objectp(present("_INDICATE_KNACK_FIELD_", environment(me)))
        ) {
                message_vision("���O����Ƥ]�S���o�͡C\n",me, target);
                me->improve_skill(SKILL_NAME, 2 + random(me->query_dex()/2) );
                destruct(field);
                return 1;
    }

        if( !field->move(environment(me)) ) {
                message_vision("���O����Ƥ]�S���o�͡C\n",me, target);
                me->improve_skill(SKILL_NAME, 2 + random(me->query_dex()/2) );
                destruct(field);
                return 1;
        }

        msg = HIW "$N�w�N$n"HIW"�Ʀ������C�}����_���P����Aí�p���s�A��սS�I\n" NOR;
    message_vision( msg,me, target);

        field->set("name", 
                sprintf(HIG"�����C�} "HBK"[%s(%s)�ҧG]"NOR, me->name(), me->query("id")) );
        field->set("power", me->query_skill(SKILL_NAME) );
        field->set("damage", target->query("weapon_prop/damage") );
        field->set("long", 
                field->query("long") + 
                HIW "���C�}�ϥ�" + target->query("name") + "(" + target->query("id") + ")"+ HIW "�ҧG���A" NOR 
                + HIW "�֦�" + field->query("power") + "%��" + field->query("damage") + "�I�����O�C" NOR );

      me->improve_skill(SKILL_NAME, me->query_dex() * (4+random(2)) );
    destruct(target);

        // �C�}�ɮġG�� 180 ��A�C1�ITEC�i�W�[ 180 ��C
        timeout = 180 + me->query_tec()*180;
        if(timeout < 180) timeout = 180;
        call_out( "dest_field", timeout, field);
        return 1;
}

int improve_limite(object ob)
{
        return  50 + ob->query_dex();
}


