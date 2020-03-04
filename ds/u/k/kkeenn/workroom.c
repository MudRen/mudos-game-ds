#include <room.h>;
#include <ansi.h>;
inherit ROOM;
string *members = ({ });
void create()
{
set("short",HIC"龍之聖地"NOR);
set("long","
╭╮  ╭╮╭╮  ╭╮╭───╮╭───╮╭╮  ╭╮╭╮  ╭╮
││╭╯│││╭╯││╭──╯│╭──╯│╰╮│││╰╮││
│╰╯╭╯│╰╯╭╯│╰─╮  │╰─╮  │  ╰╯││  ╰╯│
│╭╮╰╮│╭╮╰╮│╭─╯  │╭─╯  │╭╮  ││╭╮  │
││╰╮│││╰╮││╰──╮│╰──╮││╰╮│││╰╮│
╰╯  ╰╯╰╯  ╰╯╰───╯╰───╯╰╯  ╰╯╰╯  ╰╯
");
set("exits", ([
"wiz":"/open/world3/meetroom",
"future":"/open/world3/tmr/basic/hotel",
"now":"/open/world2/lichi_town_2/map_5_26",
"past":"/open/world1/tmr/area/hotel",
 ]) );
set("valid_startroom", 1);
set("objects",([
]) );
set("light",1);
setup();
call_other("/obj/board/kkeenn_b", "???");
}
void init()
{
        if( userp(this_player()) )
                call_out("delay", 0, this_player());
 add_action("do_move","move");
 add_action("do_trans","trans");
        if( getuid(this_player()) == "kkeenn" )
        {
                add_action("do_control", "control");
        }
}

void delay(object me)
{
        write("

 "HIW"\t(想到"HIC"遊龍俠(Kkeenn)"HIW"的領域去, 請打move)\n
"NOR);
}
int do_move(string arg)
{
 object me = this_player();
 if(!arg) return notify_fail("你想去哪裡ㄚ﹖\n");
 if(arg == "love")   //情城池(古代)   
{
 message_vision(HIW+me->query("name")+"大聲的說出目的地『"HIM"情城池"HIW"』！\n"NOR,me);
  me->move("/open/world1/kkeenn/love/enter"); 
 message_vision(HIY+me->query("name")+"的身形出現在一陣強光之中！\n"NOR,me);    
   return 1;
   }
if(arg == "secret")  //地下城(未來)
 
  {
 message_vision(HIW+me->query("name")+"大聲的說出目的地『"CYN"地下城"HIW"』！\n"NOR,me);
  me->move("/open/world3/kkeenn/secret-area/enter"); 
 message_vision(HIY+me->query("name")+"的身形出現在一陣強光之中！\n"NOR,me);    
   return 1;
   }
if(arg == "light")  //超光子訓練場(未來)
   {
 message_vision(HIW+me->query("name")+"大聲的說出目的地『"HIY"超光子訓練場"HIW"』！\n"NOR,me);
  me->move("/open/world3/super-light-area/1"); 
 message_vision(HIY+me->query("name")+"的身形出現在一陣強光之中！\n"NOR,me);    
   return 1;
   }
else
   {
    write("Sorry, 遊龍俠並沒有寫這個領域歐...\n"); 
    write("祂老人家的領域有：\n1. 情城池(love) 2.地下城(secret) 3.超光子訓練場(light)\n");
   return 1; 
   }
      return 1;
}
int do_trans(string arg)
{
 object me = this_player();
 if(!arg) return notify_fail("你想去哪裡ㄚ﹖\n");
 if(arg == "work")   
   {
 message_vision(HIW+me->query("name")+"大聲的說出目的地『"HIC"辦公室"HIW"』！\n"NOR,me);
  if( member_array(getuid(me), members) != -1 || getuid(me) == "kkeenn" )
    {
     tell_room(this_object(), me->name()+"的身形漸漸隱沒..\n", ({ me }));
     me->move(__DIR__"workroom1.c");
     tell_room(load_object(__DIR__"workroom1.c"),me->name()+"從底下漸漸上升至此地。\n", ({ me }));
           return 1;
    }
else return notify_fail("你沒有得到遊龍俠的同意進入。\n");
    }
 return 1;
}
int do_control(string arg)
{
        if( !arg ) return notify_fail("格式: control <人名>\n");
        if( member_array(arg, members) != -1 )
        {
                members -= ({ arg });
                write("刪除可進出人物 "+arg+"。\n");
                return 1;
        }
        else
        {
                members += ({ arg });
                write("增加可進出人物 "+arg+"。\n");
                return 1;
        }
        return notify_fail("格式: control <人名>\n");
}
string *query_members() { return members; }
