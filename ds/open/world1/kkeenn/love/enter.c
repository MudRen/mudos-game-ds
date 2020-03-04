#include <room.h>;
#include <ansi.h>;
int welcome(object me);
inherit ROOM;
void create()
{
        set("short",HIM"情城池入口"NOR);
        set("long", @LONG
這裡就是武林中以鞭法聞名的情城池，由於重女輕男，所以並不歡
迎男人進城。情城池由當今十大高手，唯一的女性，人稱『詭譎鞭』的
妙法仙尊所創，在武林中有非常崇高的地位。
LONG
        );
  set("exits", ([
"north" : "/open/world1/wilfred/sand/room26",
"south" : "/open/world1/wilfred/sand/room27",
]));
        set("outdoors","land");
                setup();
}
void init()
{
        ::init();
     call_out("welcome",0,this_player());
}
int welcome(object me)
{
   object ob = this_player();
        if( ob->is_corpse() ) return 1;
      if(ob->query_temp("kill_love") > 0)
        {
      message_vision(HIM"《情城池》 "NOR"守衛很邪惡的說道： 快進來受死吧！\n"NOR,ob);
      ob->move(__DIR__"room1.c");
                        return 1;
        }

      if(ob->query("class1") == "情城池")
        {
      message_vision(HIM"《情城池》 "NOR"守衛很高興的說道： 師姐, 你回來了阿^.^ 。\n"NOR,ob);
      ob->move(__DIR__"room1.c");
      tell_room(environment(ob),ob->name()+"踩著輕巧的步法, 像隻蝴蝶般的走進來。\n",({ ob }));
                        return 1;
        }
   else
        {
                message_vision(HIM"《情城池》 "NOR"守衛見$N不是情城池的，開始用懷疑的眼神打量著$N。\n"NOR,ob);
                message_vision(HIG"守衛說： 這位朋友，您此次前來是要..。\n"NOR,ob);
                message_vision(HIW"[ answer killer / guest     滅派 / 參觀]\n"NOR,ob);
               add_action("do_answer", "answer");
                 return 1;
        }
      } 
int do_answer(string arg)
{
        object me,b;
        me=this_player();
        if( me->is_corpse() ) return 1;
 
 if(!arg) return notify_fail("你到底來這裡要幹麻阿 ?\n");
 if(arg=="killer")
 {
        if( me->query("level") < 25 ) return 1;
message("world:world1:vision",HIM"\n《情城快報》：\n\t城主有令，情城蒙難，慘遭"HIW+me->name()+HIM"毒手，請盡快回來援助\n"NOR,users() );
            me->set_temp("kill_love",1);  
      me->move(__DIR__"room1.c");
if( sizeof(filter_array( children(__DIR__"npc/killer"), (: clonep :) )) < 2 )
{
     b = new(__DIR__"npc/killer")->move(__DIR__"room8");
     b = new(__DIR__"npc/killer")->move(__DIR__"room9");
}
 message_vision(HIR+me->query("name")+"滿臉殺氣的衝進來！\n"NOR,me); 
              return 1;
 }
 
 if(arg=="guest")
 {             
    if( me->query("gender") == "男性")   return notify_fail("守衛很客氣的說: 抱歉, 本城不歡迎男子。\n");
 message_vision(HIM"情城池 "NOR"守衛說道：您老請進, 休嫌奴婢怠慢。\n"NOR,me);  
      me->move(__DIR__"room1.c");
 message_vision(HIC+me->query("name")+HIC"帶著一臉的好奇心走進來！\n"NOR,me); 
        return 1;
 }
 return notify_fail("你到底來這裡要幹麻阿(killer),(guest) ?\n");
}

