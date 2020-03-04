/* Thief 專解之 -War */
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "長城");
        set("long", @LONG
test
LONG
        ); 
        set("item_desc",([ 
        "木門":"一扇蠻破舊的木門，門口上了一道鎖[pick]，裡面不知道是什麼地方？\n",
        ]) );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room9", 
  //"west" : __DIR__"room6",  
  "southwest" : __DIR__"room7", 
])); 
set("light",1);

        setup();
}
void init()
{
        add_action("do_pick","pick");
}
int do_pick(string arg)
{
          object me,x;
          me=this_player(); 
          if(!me->query_class == "thief" ) return 0;
           if(arg != "木門") return 0;
          else { 
                        message_vision(HIC"$N使出盜賊的本能•『開鎖』...把此木門給打開了...$N走進木門裡去。\n"NOR,me);  
                        }else
                        {
                        message_vision(HIC"$N使出盜賊的本能•『開鎖』...但是失敗了........\n"NOR,me);
                        me->start_busy(100);
                        }
            message("world:world1:vision",HIR"\n\t開羅士兵大喊：劫獄啊！！有人劫獄啊！！\n"
                             +HIB"\n\t開羅將軍"+HIR"大喊：來人啊！將"+HIG""+me->name(1)+""+HIR"給我拿下！\n\n"+NOR,users());  
            {
            me->move(__DIR__"jail");
            x=new(__DIR__"jailer");
            x->move(this_player());
            x->kill_me(this_player());
            x=new(__DIR__"jailer");
            x->move(this_player());
            x->kill_me(this_player());      
            }
            return 1;
          }
}


