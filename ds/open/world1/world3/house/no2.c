#include <ansi.h>
inherit HOUSE;
void create()
{
        set_name("軍營",({"barracks"}));
        set_short("軍營","軍營內部");
        set_long(@OUTLONG
這裡是訓練機械裝甲兵的地方，這裡擺放著許多的電線和
厚實的金屬板，和一些十分精巧的晶片電路等等，在一旁
有許多半成品的裝甲兵，其還未經訓練，故無法戰鬥，你
可以訓練(drill)這些裝甲兵。
OUTLONG
,@INLONG
這裡空空蕩蕩的十分寬敞，一個相當普通的建築物。
INLONG
); // 長敘述
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
      case "1":    //機械裝甲兵
          message_vision("$N向軍營的電腦下了一個指令，軍營即開始訓練裝甲兵。\n",me);
          this_object()->set_temp("makename","裝甲兵");
          call_out("make",2,arg);
          break;
      default:
          message_vision("\n",me);
          list = "\n";
          list += "��������������������������������������������������������������\n";
          list += "��                         機械兵種 :                       �鱋n";
          list += "�礜w─────────────�煍w─────────────�瀵n";
          list += "��1.  裝甲兵(armor sodlier)   ��2.                          �鱋n";
          list += "�譀����������������������������������������������������������瀵n";
          list += "�灟Y需要訓練機械兵輸入：  drill <代號> 即可。               �鱋n";
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
obj->set_short("訓練"+HIW+obj->query_temp("makename")+HIR"(完成度："+obj->query("right")+"%)"NOR"  軍營","軍營內部" );
       obj->add_temp("makenow",10+random(10));
       call_out("make",2,arg);
    }
    else {
      switch(arg) {
        case "1":    //裝甲兵
            message_vision(HIW"軍營電腦說道：機械裝甲兵！訓練完成！\n"NOR,obj);
            set_short("軍營","軍營內部");
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
