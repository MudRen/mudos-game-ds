#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIW "瓦爾加布" NOR , ({ "waregabo" }) );
        set("age", 23);
        set("long","
眼前這位威風凜凜的騎士，正是魔龍騎士軍團長
手中的光之槍，耀眼無比，身上的魔龍鎧甲，更襯
托出其不可預知的實力。他眼神銳利，似乎可看破一
切。由於是古代龍族和魔族的混血兒，因此更是位戰
鬥的天才！
");
        set("level",100);
        set("str", 50);
        set("con", 400);
        set("dex",100);
        set("int",250);
        set_temp("apply/attack", 230);
        set_temp("apply/armor", 200);
        set_skill("dodge",100);
        set_skill("parry",100);
        set("chat_chance",20);
        set("chat_msg",({
           (:command("say 聽說sopher是DS最帥的人"):),
           (:command("puke"):),
           (:command("snicker"):),
        }));
        set("chat_chance_combat", 17);
        set("chat_msg_combat", ({HIR"瓦爾加布大喝 : 「可惡的傢伙∼﹗受死吧﹗」\n"NOR,
           (:command("aluba darkfool"):),
            }) );
        set_heart_beat(1);
        setup();
        
}

void init()
{
        call_out("incheck",3,this_player());
}
void incheck(object me)
{
        if(me->query("name") != "瓦爾加布")
        {
say("瓦爾加布說道：" HIR"..........。\n"NOR);
                command("waha" + me->query("id"));
        }else
         {
                say( HIY "瓦爾加布輕輕『哼！』一聲。 \n" NOR );
                                
      } 
}
