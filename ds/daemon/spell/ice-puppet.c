// ice-puppet �B�����w
// create by tmr 2007/01/04

#include <ansi.h>
#define PUPPET  __DIR__"frost-obj/ice-puppet"

inherit SSERVER;
inherit SKILL;

int clone_shield(object me,int sk,int inn);

int cast(object me, object target)
{
      int sk,inn,cost;

    sk = me->query_spell("ice-puppet");
    inn=me->query_int();
    cost=(sk*3+inn*2)/2;
    if( me->query("mp") < 200 || me->query("mp") < me->query("max_mp")/2 )
        return notify_fail("�A���]�k�����A�L�k�ϥΡu�B�����w�v�C\n");
    if( me->query("hp") < me->query("max_hp")/2 )
        return notify_fail("�ݨӧA���ˤ����A�L�k�ϥΡu�B�����w�v�C\n");
    if(me->is_fighting() )
        return notify_fail("�A���b�԰����C\n");

    message_vision(
          HIB "$N�I�i�_�B�����w���k�A���Ǫ����𭰦ܦB�I�A�C�C�a���E�_��...\n" NOR
        ,me);

    call_out("clone_shield", 3,me,sk,inn);
    if( userp(me) )
        me->receive_damage("mp", cost );
    me->start_busy(2);
    return 1;
}

int clone_shield(object me,int sk,int inn)
{
    object pet,ob;
    if( !me ) return 0;
    if( me->is_fighting() )
        return notify_fail("����Ƥ]�S�o��...\n");
    if( (sk*3+inn*2)/4 < random(70)
            || objectp(ob = present("ice-puppet", me) )  )
        //����I�k�̥u��֦��@�� pet�C
        message_vision("���G����Ƥ]�S�o��.....\n",me);
    else    {
        pet=new(PUPPET);
        if( !pet->move(me) ) {
            message_vision("���G����Ƥ]�S�o��.....\n",me);
            me->improve_spell("ice-puppet",random(inn) + 2);
            return 1;
        }

        pet->update_pet( me );
        message_vision(HIW "�@���������v���B�����w�X�{�b$N��̡A���o�۵����H��C\n" NOR,me);
        me->improve_spell("ice-puppet", random(inn) + 2);
    }
    return 1;
}

int improve_limite(object ob)
{
    if(ob->query("int") < 60) return 90;

    return 100;
}


