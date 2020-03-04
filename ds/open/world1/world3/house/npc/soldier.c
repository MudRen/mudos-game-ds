#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����˥ҧL" ,({ "engine soldier","soldier" }) );
        set("level",5);
        set("age", 35);
        set("long",@long
�L�O�@���Ѵ����B�q���B�M���ݪO�һs��������˥ҧL�C
�o�O�̰򥻪��˥ҧL�A�u�����²�檺���ȡC
���O�G
      �{�ѥD�H�G know <id>
      �ѰO�D�H�G forget <�Y���˥ҧL>
      ����ʧ@�G control <�Y���˥ҧL> to <���O>

long
);
        setup();
} 
void init()
{ 
         add_action("do_know","know");
         add_action("do_forget","forget");
         add_action("do_control","control");
}
int do_know(string arg)
{
        object me,obj;
        me=this_player();
        obj=this_object();
        if(!obj->query("user"))
        {
          if( !arg ) return notify_fail("�A�n���L�{�ѽ֡H\n");
          message_vision("$N�b�˥ҧL�餺��F�X�Ӧr�A�˥ҧL�q���{�w"+arg+"���L���D�H�C\n",me);
          obj->set("user",arg);
        }
        else {
          if(me->query("id")==obj->query("user")) return notify_fail("�A�N�O�L���D�H�C\n");
          tell_object(me,"�L�w�g���@�ӥD�H�F�A�L�k�A�O�Цh�l���H�C\n");
        }
        return 1;
}
int do_forget(string arg)
{
        object me,ob;
        me=this_player();
        ob=this_object();
        if(arg == "soldier" || arg =="engine soldier")
        {
          if(ob->query("user") != me->query("id") )
          {
            message_vision("$N�������Q�����J�˥ҧL���餤�A���O�Q�o�{�F�C\n",me);
            ob->kill_ob(me);
          }         
          else {
            message_vision("$N����J�˥ҧL���餤���F�@�U�A�˥ҧL�ѰO�F�D�H�F�C\n",me);
            ob->delete("user");
          }
        }
        else {
           tell_object(me,"�A�n���֧ѤF�D�H�H\n");
        }
        return 1;
}
int do_control(string arg)
{
        string dest, cmd;
        object ob,me;
        me=this_player();
        ob=this_object();
        if(ob->query("user")!=me->query("id") ) return 0;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("���O�榡�Rcontrol <�Y�H> to <���O>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("�o�̨S�� " + dest + "�C\n");
        if(ob->is_busy() ) return notify_fail(ob->query("name")+"�����ۡA�S����ť�A���X�ϡC\n");
        command(cmd);
        return 1;
}
