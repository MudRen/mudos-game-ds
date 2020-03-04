#include <ansi.h> 
inherit ITEM;
void create()
{
set_name(HIY"老舊的神像"NOR,({"statue"}));
set_weight(100);
set("value",0);
set("unit","尊");
set("long","灰塵滿滿的神像。\n");
set("no_get",1);
setup();
}

void init()
{
        add_action("do_clean","clean");
}

int do_clean(string str)
{

object me = this_player();
     if(this_object()->query_temp("cleaned") != 0) return 1;
     if( str !="神像") return notify_fail("what?\n"NOR);
        { 
       if( !query("start"))
        {
        message_vision(HIR"$N小心翼翼的擦拭神像上的汙點。\n"+NOR,me);
        message_vision(HIR"突然神像動了起來，像似解開封印似的！！\n"+NOR,me);
        set("start", 1);
        call_out("evil_msg",4);
        } else {
         return notify_fail("神像晃動中。\n");
     } 
 }
return 1;

}

int evil_msg()
{
   message("world:world1:vision",
HIW"\n\t遠方一道金光閃過∼∼\n\n\t"HIY"凌雲寺妙見高僧道："HIG"此乃兇煞腥光，想必遠方定出殺戮之戰！！\n\n\n"NOR,users());
  call_out("getin_msg",3);
} 
int getin_msg(object me)    
{
    object mob;
    me=this_player();
    mob=this_object();

    message_vision(HIR"七邪塔的千年妖佬甦醒個過來！！\n"NOR,me);
    set("item_desc",([
        "神像":"此神像上已無任何灰塵。\n",
        ]));
    me->move(__DIR__"4f_1");
    mob=new(__DIR__"npc/evil3.c");
    mob->move(__DIR__"4f_1");
    mob->kill(me); 
    destruct(this_object());     
  return 1;
}

