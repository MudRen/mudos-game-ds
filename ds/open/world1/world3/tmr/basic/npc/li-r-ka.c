#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�ߺ��d",({"li-r-ka","ka"}) );
        set("long",@LONG
�b�A���e���k�H�ݰ_�ӤQ�����ˤ��A���ƾ���A�d�ۤp���Y�A�����y
�H���|���R�O�A��o��z�u�y�H����v�����W�A�n�O�A�Q�����@���y�H��
�ܡA�L�i�H���ѧA�\�h��������T(ask ka about ���W)�C
LONG
);
        set("age",30);
        set("race","�H��");
        set("level",35);
        set("attitude", "peaceful");
        set("title","�G�P�y�H");
        set("gender", "�k��" );
        set("inquiry",([
          "���W":"�{�b���|���y�H������W(join)�A�u��ú����W�O2000�C",
        "���i���˪L":"��..���i���˪L�b�¥@���q�Ϫ���_��C",
        "���示�e":"�o�������示�e�A�N�O�Q�δ˪L�����ѵM�귽�A�l���u���W�v�C",
        "���W":"��..���W�O�ͬ��b���i���˪L���ʪ��A��l�N���K�h���F�C",
        ]) );
        setup();
}

void init()
{
        add_action("do_join","join");
}

int do_join()
{
        object me;
        me=this_player();

       return notify_fail("�{�b�Ȯɰ�����W�C\n");

        if(stringp(me->query("class1") ) )
                return notify_fail("�A�w�g�ѥ[���|�Ϊ����F�C\n");
            if(me->query("bank/future") < 2000) 
                return notify_fail("�A���Ȧ�b�ᤤ�èS�����������C\n");
        if(me->query_temp("join_hunter_test") )
                return notify_fail("�A�w�g���W�ѥ[�F�C\n");
        message_vision("$N�V�ߺ��d�n�O���W�y�H����C\n",me);
        command("nod "+me->query("id") );
        command("say �o��"+me->query("name")+"���W�̵n�O���\\�A�Цܥ��i���˪L�ѥ[����a�C" );
        command("say ���D�o�������示�e�ܡH");
            me->receive_money(-2000);
        me->set_temp("join_hunter_test",1);
        return 1;
}

int accept_object(object me,object obj)
{
        message_vision("$N���F�ߺ��d�@"+obj->query("unit")+obj->query("name")+"�C\n",me);
        if(obj->query("catch_ok")!=1 || obj->query("id")!="yalen cirri" )
        return ::accept_object(me,obj);
        destruct(obj);
        if(!me->query_temp("join_hunter_test") ) {
                command("say ���§A���n�N�C");
                command("say");
        }
        else {
                command("say �@�I�A���\\�������F�y�H����C");
                me->delete_temp("join_hunter_test",);
                me->set_temp("join_hunter_ok",1);
        }
        return 1;
}




