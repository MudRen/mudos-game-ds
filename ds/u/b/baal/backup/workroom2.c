#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", MAG"索思受詛咒的城堡"NOR);
        set("long", @LONG
邪惡的氣息充斥在這個房間裡, 你感到死亡的威脅, 不禁害怕的全
身發抖, 牆上刻著代表黑暗之后塔克西絲的五頭龍, 看來這就是索思所
侍奉的神祇了, 你感到邪惡慢慢的攫住你的心靈, 在這個幾被冰凍的空
間中, 你可以聽到自己的心跳聲...
LONG 
);
        set("exits", ([ /* sizeof() == 2 */
        "out" : __DIR__"workroom",
        "down" : __DIR__"npctestroom",
        "north" : __DIR__"workroom3",
        "up" : __DIR__"workroomf2-1",
        ]));
        set("light",1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("no_recall",1);  // 不能recall也可以刪掉
        set("no_kill",1);  // 不會有戰鬥也可以刪掉它
        setup();
  call_other("/obj/board/baal_b" , "???");
}

void init()
{
  object me;
  
if(wizardp(this_player())) return;
  ::init();
  if( interactive(me = this_player()) && !me->is_fighting())
  {
  remove_call_out("hi");
  call_out("hi",1,me);
  }
}
void hi(object me)
{
object amulet;
if(!objectp(amulet=present("amulet",me) ) )
{
        message_vision(HIC"$N一進來這裡..便因自心中生出恐懼而不停的發抖...。\n"NOR,me);
        me->receive_damage("hp",300); //因為冷所以減hp
        call_out("cold",10,me);
        return;
}
else
{
message_vision(HIG"$N緊抓著手中的護身符, 而使的恐懼稍減, 寒冷漸漸退去, 但你仍可以感覺到邪惡正注意著你。\n"NOR,me);
return;
}
}
void cold(object me)
{
     if(!me) return;
     message_vision(HIC"$N感到越來越害怕...心中的恐懼漸漸吞噬了你的心靈...生命力開始離開你的身軀。\n"NOR,me);
     me->receive_damage("hp",150);
     call_out("cold2",7,me);
     return;
}
void cold2(object me)
{
     if(!me) return;
     message_vision(HIC"$N已經無法抵抗這恐懼了.再不離開這的話一定會死在這,成為亡靈的.。\n"NOR,me);
     me->receive_damage("hp",250);
     call_out("cold3",8,me);
     return;
}
void cold3(object me)
{
     if(!me) return;
     message_vision(HIR"你只剩下微弱的一口氣.快失去意識了....。\n"NOR,me);
     me->set_temp("freeze",1);
     call_out("cold4",30,me);
     return;
}
void cold4(object me)
{
     if(!me) return;
     message_vision(HIC"最後$N在不斷顫抖中斷斷續續的吐出了一口氣...閉上了雙眼...身體覆上了一層薄薄的冰..永遠沉睡了。\n"NOR,me);
     me->set_temp("temp/death_type",HIC"[結凍了]"NOR);
     me->die();
     return;
}


