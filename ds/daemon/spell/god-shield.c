//god-shield  ����ë�� -by tmr- //PM 11:33 2000/1/24
//update 2000/4/7 -By Tmr-

#include <ansi.h>
#define GOD_SHIELD	"/open/always/god-benison-shield"

inherit SSERVER;
inherit SKILL;

int clone_shield(object me,int sk,int inn);

int cast(object me, object target)
{
      int sk,inn,cost;

    //return notify_fail("god-shield debuging...sorry by -Acme-\n");
    sk=me->query_spell("god-shield");
    inn=me->query_int();
    cost=(sk*3+inn*2)/2;
    //        if(me->query("ap") < 200 || me->query("mp") < 200)   �������Y
    if( me->query("mp") < 200 || me->query("mp") < me->query("max_mp")/2 )
        return notify_fail("�A���]�k�����A�L�k�ϥΡu����ë�ޡv�C\n");
    if( me->query("hp") < me->query("max_hp")/2 )
        return notify_fail("�ݨӧA���ˤ����A�L�k�ϥΡu����ë�ޡv�C\n");
    if(me->is_fighting() )
        return notify_fail("�A���b�԰����C\n");

    message_vision(
        GRN"$N�u�D�G�u�믫�P�Ѧa�A����ۮ��ġA�W�ǧ߫��O�A�Ҧ]�y�ƥ\\�C�v\n" NOR
        ,me);

    call_out("clone_shield",3,me,sk,inn);
    if( userp(me) )
        me->receive_damage("mp",cost );
    me->start_busy(2);
    return 1;
}

int clone_shield(object me,int sk,int inn)
{
    object shield,ob;
    if( !me ) return 0;
    if( me->is_fighting() )
        return notify_fail("����Ƥ]�S�o��...\n");
    if( (sk*3+inn*2)/4 < random(70)
            || objectp(ob = present("god-benison-shield", me) )  )
        //����I�k�̥u��֦��@��shield�C
        message_vision("���G����Ƥ]�S�o��.....\n",me);
    else    {
        shield=new(GOD_SHIELD);
        if( !shield->move(me) ) {
            message_vision("���G����Ƥ]�S�o��.....\n",me);
            me->improve_spell("god-shield",random(inn) + 2);
            return 1;
        }


        shield->update_shield(me,sk,inn);
        message_vision(HIG "�@�}���{���L��A$N���⤤���M�X�{�@�Ӭ޵P�I�I\n" NOR,me);
        me->improve_spell("god-shield",random(inn) + 2);
    }
    return 1;
}

int improve_limite(object ob)
{
    if(ob->query("int") < 60) return 90;
    else return 100;
}

