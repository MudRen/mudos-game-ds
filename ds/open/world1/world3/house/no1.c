#include <ansi.h>
inherit HOUSE;
void create()
{
        set_name("��������",({"command center","center"}));
        set_short("��������","�������ߤ���");
        set_long(@OUTLONG
�o�ɫ������ߤQ�����j�A�b�������ߦ��\�h��Ǯa������H
�b���ʡA���G�Q���������A�������߯��s�U�����Ͳ��Τu
��(produce)�A���F�o�Ǥu��~��i�@�B����y��L���ؿv�C
OUTLONG
,@INLONG
�o�̪Ūſ������Q���e���A�@�Ӭ۷��q���ؿv���C
INLONG
); // ���ԭz
        set_weight(999999);
        set("light",1);
        set("no_clean_up",1);
        setup();
}
void init()
{ 
         add_action("do_produce","produce");
}
int do_produce(string arg)
{
    string list;
    object me;
    me=this_player();
    switch(arg) {
      case "1":    //������u
          message_vision("$N�V�D�q���U�F�@�ӫ��O�A�������ߧY�}�l�s�y������u�C\n",me);
          this_object()->set_temp("makename","������u");
          call_out("make",2,arg);
          break;
      case "2":    
          break;
      default:
          message_vision("\n",me);
          list = "\n";
          list += "��������������������������������������������������������������\n";
          list += "��                         �u����� :                       ��\n";
          list += "��w�w�w�w�w�w�w�w�w�w�w�w�w�w�ޢw�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
          list += "��1.  ������u(Engine Arm)    ��2.                          ��\n";
          list += "��������������������������������������������������������������\n";
          list += "���Y�ݭn�سy�u���J�G  produce <�N��> �Y�i�C               ��\n";
          list += "��������������������������������������������������������������\n";
          list += "\n";
          tell_object(me,list);
          break;
      }
    return 1;
}
int make(int arg)
{
    object obj,nnew;
    obj=this_object();
    if(obj->query_temp("makenow") <= 100 )
    {
          obj->set_short("��o"+HIW+obj->query("makename")+HIR"(�����סG"+obj->query("right")+"%)"NOR"  ��������","�������ߤ���" );
       obj->add_temp("makenow",10+random(10));
       call_out("make",2,arg);
    }
    else {
      switch(arg) {
        case "1":    //������u
            message_vision(HIW"�������ߤ���Ǯa�s�D�G������u�I��o�����I\n"NOR,obj);
            set_short("��������","�������ߤ���");
            nnew=new(__DIR__"obj/arm");
            nnew->move(environment(obj));
            break;
        default:
            break;
      }
      obj->delete_temp("makenow");
    }
    return 1;
}