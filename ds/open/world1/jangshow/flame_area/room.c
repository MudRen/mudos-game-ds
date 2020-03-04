#include <ansi.h>
inherit ROOM;


void create()
{
        set("short", "聖炎殿");
        set("long", 
"\n"
HIR"                  ████████████████\n"
HIR"██████████████████████████████████\n"
HIR"      ██████                                ██████\n"
HIR"      ██████              "HIC"聖炎殿"HIR"            ██████\n"
HIR"      ██████                                ██████\n"
HIR"██████████████████████████████████\n"
HIR"  ████████████████████████████████\n"
HIR"  ████████████████○███████████████\n"
HIR"███████  ███████████████████  ███████\n" 
HIR"████                        ███                        ████\n"
HIR"██                            ███                            ██\n"
HIR"███████████████          ███████████████\n"NOR
        );

        set("item_desc",([
        "圓洞":"聖炎殿正中央的小洞，不知道有什麼作用，好像可以轉的樣子(turned x on x)。\n",
        ]) );
        set("exits", ([ /* sizeof() == 1 */
        "enter":"/open/world1/jangshow/min/map_12_9.c",
          "down":"/open/world1/tmr/wujian/room2",
        ]));
        set("world", "past");
        setup();
}
void init()
{
        add_action("do_turn","turned");
}

int do_turn(string arg)
{
        object me,mir;  
        me=this_player(); 
        if(this_object()->query_temp("CALLED")==1) return notify_fail("剛剛已經有人轉過了。\n");
        if(!arg || arg!="mirror on 圓洞") return notify_fail("你要 turned 什麼?\n");
        if(!objectp(mir=present("turn dragon-mirror",me) ) )
                return notify_fail("你沒有東西可以轉動啊 ? \n");
        message_vision("$N將轉龍鏡放進了圓洞裡，在轉龍鏡消失的瞬間，地底神殿突然開始搖動了。\n",me);
        message("world:world1:vision",HIW"\n\t煙霧彌漫••••\n"
                                    +HIR"\n\t一陣天搖地動後，傳說中的地龍，出現在地底神殿了！\n\n"+NOR,users()); 
        destruct(mir);
        me->start_busy(2);  
        //this_object()->add_temp("CALLED",1); 
        //call_out("DE_CALLED",1000,me);
        call_out("BRING",3,me);    
        return 1;        
} 
void BRING()
{
     object me=this_player(),MOB;
     MOB=new(__DIR__"npc/dragon");
     MOB->move(environment(this_player()));
     MOB->kill_object(environment(me));
     message_vision(HIW"突然一道"+HIG"青光爆射"+HIW"！掃向"+(string)me->query("name")+"！\n"+NOR,me);
     me->receive_damage("hp",this_player()->query("max_hp")/2); 
     return;
}  
/*void DE_CALLED()
{    this_object()->delete_temp("CALLED",1); return;      } 
*/
