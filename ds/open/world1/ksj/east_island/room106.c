#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short",HIW"冰鏡之洞窟"NOR);
  set("long",HIW @LONG
來到這個山洞寒氣逼人，一看四周竟然都是厚厚的冰壁，冰壁表
面光亮無比，像是天然的鏡子，山洞裡有一座冰結而成的臥床，你光
站在洞口就渾身發抖，巴不得趕快離開這裡。
LONG NOR);
  set("exits",([ 
      "out":__DIR__"room105",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("light","1");
  set("objects",([
      __DIR__"npc/yukionna":1,
     ]));
  setup();
}            

int room_effect(object me)
{
  switch(random(5))
  {
    case 0:
    case 1:
    case 2:

    message_vision("如同白霧的寒氣，繚繞在你的腳邊．．．。\n",me);
    if(me->query_skill("dodge")< 35 && random(10)<3 )
    {
      tell_object(me,HIW"你突然地動彈不得，原來雙腳已跟地面結了一層厚厚的冰！！\n" NOR ); 
      me->add_busy(5);
    }
    else if(me->query_skill("dodge")< 70 && random(10)<3 )
    {
      tell_object(me,HIW"你猛然發現雙腳失去知覺，原來已結了一層薄冰！！\n" NOR ); 
      me->add_busy(3);
    }
    else if(me->query_skill("dodge")>69 && random(10)<3 )
    {
      tell_object(me,HIW"你突然感到雙腳血氣滯礙，使得你動作稍緩！！\n" NOR ); 
      me->add_busy(1);
    }
    return 1;
    default:       return 1;
  }
}
