inherit NPC;
#include <ansi.h>
inherit SELLMAN;
void create()
{
        set_name("司馬迎月",({ "si-ma doctor","doctor" }));
        set("long",
"    她是惡人谷的藥草販司馬煙的女兒，因為某些原因讓她願意來情城池\n"
"幫忙販賣草藥！你可以向她詢問尚無存貨(list),購買(buy)或醫治(heal)\n"
"[P.S 醫治(heal + coin) 付的醫藥費越多, 補的也越多^.^]\n"
        );
        set("age",15+random(10));
        set("no_fight",1);
     set("gender","女性");
        set("nickname",HIC"一代名醫"NOR);
        set("chat_chance", 3);
        set("chat_msg", ({
  "司馬迎月正在清點櫃子中的藥草。\n",
}) );
        set("sell_list",([
"/open/world1/acme/area/npc/obj/god_pill" : 15,
"/open/world1/acme/area/npc/obj/head_pill" : 20,
"/open/world1/acme/area/npc/obj/hand_pill" : 20,
"/open/world1/acme/area/npc/obj/body_pill" : 20,
"/open/world1/acme/area/npc/obj/foot_pill" : 20,
"/open/world1/cominging/area/npc/obj/pdragon-herb.c": 12,
"/open/world1/cominging/area/npc/obj/big-pill.c": 15,
"/open/world1/cominging/area/npc/obj/tp_candy.c": 20,
"/open/world1/cominging/area/npc/obj/appill.c": 20,
]));
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_list","list");
        add_action("do_heal","heal");
}
int do_heal(string arg)
{
        int i;
        object me,ob,coin;
        me=this_player();
        ob=this_object();
        if(!arg ) 
                return notify_fail("你要為自己出多少醫藥費呢？\n");
        if(sscanf(arg,"%d",i)!=1 ) 
                return notify_fail("你要為自己出多少醫藥費呢？\n");
	if( ob->is_busy() ) 
		return notify_fail(ob->query("name")+"正忙著，沒空理你。\n"); // add busy settings by -alick
        if(me->is_busy() )
                return notify_fail("你正忙著，沒有空付醫藥費。\n");
        if(me->is_fighting() )
                return notify_fail("你正忙著，沒有空付醫藥費。\n");
       if(!objectp(coin=present("coin",me) ) )
            return notify_fail("你身上沒有錢耶。\n");
     if(i > coin->query_amount() )
         return notify_fail("你身上的錢不夠耶。\n");
if(i < 100 ) return notify_fail("你的醫藥費不夠多歐。\n");
        message_vision("$N付了"+(string)(i)+"文醫藥費給$n\n",me,ob);
         command("smile");
         command("thank "+ me->query("id") );
         me->receive_money(-i);
        command("say 這位朋友手筆可真闊阿，讓姑娘我來為你調養身心，資補體健。");
 message_vision(HIW"\n$N手中金光一現，九九八十一隻金針快速穿梭在$n身上！！\n"HIR"$n「哇」地一聲吐了幾口黑血。\n\n"NOR ,ob,me);
   me->receive_heal("hp",i/2);
   me->receive_heal("mp",i/3);
   me->receive_heal("ap",i/3);
	ob->start_busy(2);
	me->start_busy(2);
        return 1;
}

