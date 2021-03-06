#include <path.h>
#include <ansi.h>
#include <command.h>
inherit ROOM;

void create()
{
        set("short", HIY"毛廁"NOR);
        set("long", @LONG
"HIC"如你所見這是一間毛廁，裡面什麼東西都沒有，有的只有一個跨\n"
"HIC"世紀的大馬桶，和一張貼在牆壁上的"NOR"使用手冊("HIC"vote)。\n"NORLONG
        );

        set("exits", ([ /* sizeof() == 1 */
 "west" : __DIR__"hall2",
        ]) );
        set("item_desc", ([ 
                "vote": HIC"歡迎使用"HIR"Kenshin"HIC"牌抽水馬桶，本產品已通過ISO9002國際\n"                        
                        HIC"品質保證，絕對沒問題，請安心使用。\n"
                         HIC"請遵循以下步驟，否則我就送你"HIB"一桶汽油"HIC"，還有"HIM"一支歡仔
                         "HIM"火"HIC"，順便再送你"HIY"一個雞蛋糕"HIC"，幫你好好的"HIR"過生日"HIC"！！\N"
                         "HIG"步驟一: 請打"HIC"sit on toilet\n"
                         "HIG"步驟二: "HIW"準備等死吧，哈哈！！\n"
                         "HIW"最後，謝謝您的使用，並祝你旅途愉快！！\n"
                                                                HIY"Kenshin 筆\n"NOR,                        ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_fight",1);
        set("no_kill",1);
        setup();
}

void init()
{
 add_action("do_sit","sit");
}

int do_sit(string arg)
{
 object me,*inv;
 int i;
 string buffer1,file,name;
 me=this_player();
 if(!arg) return 0;
 if(me->query_temp("ride"))
 {
        write(HIC" 你有聽說過騎馬上廁所的事嗎??\n"NOR);
        return 1;
 }
  if(me->is_busy())
 {
        write("你上一個動作還沒完成。\n");
        return 1;
 }
 if(sscanf(arg, "on %s", arg)==1)
 {
  if(arg=="bed")
  {
   if(name=this_object()->query_temp("on_use"))
   {
        if(name == me->query("name")) write(HIC"你已經坐上馬桶上上廁所了!!\n"NOR);
        else write(HIY"正當你要坐上馬桶時,"+name+"搶先你一步上了馬桶。\n"NOR);
        return 1;
   }
   inv = all_inventory(me);
   for(i=0; i<sizeof(inv); i++)
   {
    if(inv[i]->query("secured")) inv[i]->delete("secured");
    if(!inv[i]->query("base_value"))
    {
     file=base_name(inv[i]);
     if(sscanf(file,"/open/world1/%s",buffer1)!=1
     && sscanf(file,"/open/always/%s",buffer1)!=1 )
     {
      if(inv[i]->query("equipped")) inv[i]->unequip();
      DROP_CMD->do_drop(me, inv[i]);
     }
    }
   }
   this_object()->set_temp("on_use",me->name());
   call_out("empty",8);
   me->start_busy(6);
   me->disable_player(HIC" ===上廁所中===\n"NOR);
   tell_room(this_object(),me->name()+"一股腦兒的坐上了馬桶上，開始了他的馬桶之旅!!\n",({ me }));
   message("system", HIG"你拋開了所有的煩惱，眼中只有那個馬桶，一股腦兒的坐下去了!!\n"NOR,me);

   call_out("step1",3,me);
   call_out("step2",8,me);
      return 1;
  } 
 }
 else return 0;
}

void empty()
{
 this_object()->delete_temp("on_use");
}

void step1(object me)
{
 if(!me) return;
 message("system", HIW"\n你突然感覺全身豁然開朗了起來•••\n\n"NOR,me);
 me->set_temp("block_msg/all", 1);
 message_vision(HIR"廁所中出現了$N的一陣陣的慘叫聲!!\n"NOR,me);
}

void step2(object me)
{
 if(!me) return;
 this_object()->delete_temp("on_use");
 message_vision(HIW"突然間，馬桶馬力加大，不虧是kenshin牌抽水馬桶，把$N吸進了馬桶的世界!!\n"NOR,me);
 me->move(__DIR__"r2");
 me->set("startroom",__DIR__"r2");
 me->save();
 me->set_temp("block_msg/all", 0);
 message("system", HIG"一陣暈眩, "HIB"再次醒來的時候卻來到了一個不同的世界來•••。\n\n",me);
 me->set_temp("block_msg/all", 1);
 message_vision("天上突然有個人影, $N從上掉了下來•••\n",me);
}


