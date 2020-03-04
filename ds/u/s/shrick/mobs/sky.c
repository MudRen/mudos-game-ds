#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIB "天下士兵" NOR , ({ "sky warrior","sky" }) );
        set("race", "人類");
        set("age", 25);
        set("long","
眼前的這位老兄面露兇光，龐大的體格，加上
手上的巨槍和厚重的鎧甲，以及背後龐大的雙翼，
令人為之恐懼，難道他就是古代天下的士兵？\n");

        set("str", 80);
        set("cor", 80);
        set("dex",10);
        set_temp("apply/attack", 200);
        set_temp("apply/armor", 20);
        
        setup();
}        
void init()
{
        call_out("incheck",3,this_player());
}
void incheck(object me)
{
        if(me->query("name") != "天下")
        {
say("天下士兵對你說道：" HIY "你是誰？我從來沒有看過像你這樣帥的人了？。\n"NOR);
                command("finalhit" + me->query("id"));
        }else
         {
                say( HIY "你是誰？ \n" NOR );
                say( HIR "天下士兵亮起他的傢伙。 \n" NOR );
                say( HIW "天下士兵揮動著雙翼~~好大的風啊:P。\n"NOR);
                say( HIC "天下士兵耍了耍他的戢。\n" NOR );
      }   
}

