#include <ansi.h>
inherit HOUSE;
void create()
{
        set_name("�x��",({"barracks"}));
        set_short("�x��","�x�示��");
        set_long(@OUTLONG
�o�̬O�V�m����˥ҧL���a��A�o���\��۳\�h���q�u�M
�p�ꪺ���ݪO�A�M�@�ǤQ���륩�������q�������A�b�@��
���\�h�b���~���˥ҧL�A���٥��g�V�m�A�G�L�k�԰��A�A
�i�H�V�m(drill)�o�Ǹ˥ҧL�C
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
         add_action("do_drill","drill");
}
int do_drill(string arg)
{
    string list;
    object me;
    me=this_player();
    switch(arg) {
      case "1":    //����˥ҧL
          message_vision("$N�V�x�窺�q���U�F�@�ӫ��O�A�x��Y�}�l�V�m�˥ҧL�C\n",me);
          this_object()->set_temp("makename","�˥ҧL");
          call_out("make",2,arg);
          break;
      default:
          message_vision("\n",me);
          list = "\n";
          list += "��������������������������������������������������������������\n";
          list += "��                         ����L�� :                       ��\n";
          list += "��w�w�w�w�w�w�w�w�w�w�w�w�w�w�ޢw�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
          list += "��1.  �˥ҧL(armor sodlier)   ��2.                          ��\n";
          list += "��������������������������������������������������������������\n";
          list += "���Y�ݭn�V�m����L��J�G  drill <�N��> �Y�i�C               ��\n";
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
obj->set_short("�V�m"+HIW+obj->query_temp("makename")+HIR"(�����סG"+obj->query("right")+"%)"NOR"  �x��","�x�示��" );
       obj->add_temp("makenow",10+random(10));
       call_out("make",2,arg);
    }
    else {
      switch(arg) {
        case "1":    //�˥ҧL
            message_vision(HIW"�x��q�����D�G����˥ҧL�I�V�m�����I\n"NOR,obj);
            set_short("�x��","�x�示��");
            nnew=new(__DIR__"npc/soldier");
            nnew->move(environment(obj));
            break;
        default:
            break;
      }
      obj->delete_temp("makenow");
    }
    return 1;
}
