#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([      "action":               "$N忽然鬼嘯一聲, 內力猛然集於雙掌,  "+WHT+"「"+NOR+"催星手"+WHT+"」"+NOR+", 威猛無濤的劈出 !",
                "attact_type":  "bar",  // 設定技能的攻擊種類
                                        // 種類有 生物(bio) 獸性(bar)
                                        // 魔法(wit)心靈(sou)科技(tec)
            "damage" : 500,
                "damage_type":  "劈傷",
        ]),
        ([      "action":               "$N雙掌忽然泛出綠光, 貼向$n的$l!",
                "attact_type":  "bar",
            "damage" : 500,
                "damage_type":  "內傷",
        ]),
        ([      "action":               "$N站定方位, "+HIR+"「"+NOR+"八卦星陣"+HIR+"」"+NOR+", 放出數道紫氣, 接連不斷的捲向$n的$l!",
                "attact_type":  "sou",
            "damage" : 500,
                "damage_type":  "瘀傷",
        ]),
    ([  "action":       "$N發瘋似的將一雙肉掌飛翻, $n難擋如此攻勢, 一時反應不過來!",
                "attact_type":  "bar",
            "damage" : 500,
                "damage_type":  "多處內傷",
        ]),
    ([  "action":       "$N大喝一聲, 一招"+MAG+"「"+NOR+"幻滅雙星"+MAG+"」"+NOR+"一掌迅捷無倫的朝$n的$l打去!",
                "attact_type":  "bar",
            "damage" : 500,
                "damage_type":  "多處內傷",
        ]),
    ([  "action":       "$N冷笑一聲, "+CYN+"「"+NOR+"單指取星"+CYN+"」"+NOR+"一指快速的點向$n的$l!",
                "attact_type":  "bar",
            "damage" : 500,
                "damage_type":  "多處內傷",
        ]),
    ([  "action":       "$N方位一轉, "+HIC+"「"+NOR+"斗轉星移"+HIC+"」"+NOR+"忽然一掌朝$n的後心打去!",
                "attact_type":  "bar",
            "damage" : 500,
                "damage_type":  "多處內傷",
        ]),
});

void do_clean();

void create()
{
        set_name(MAG"殞星老者"NOR,({"star old man", "old man","man" }) );
        set("long",@LONG
他是終生守護邪桫神廟的守廟人, 傳說它根本不是人, 
相傳從神廟出現開始他就出現了, 而神廟在文獻中已經有
一千二百年的歷史了....那....?!
LONG
);
        set("title",HIR"「守廟者」"NOR);
        set("age",1200+random(50));
        set("level",50);
        set("gender","男性");
 set("attitude", "peaceful");
        set("chat_chance", 13);
        set("chat_msg",({ 
        "殞星老者兩道銳利的目光掃向你....。\n",
        "殞星老者身上忽然發出一陣寒氣...。\n",
        }));
        set_skill("unarmed", 100);
      set("Merits/bar",7);
      set("Merits/sou",1);
      set("str",155);
    set("int",50);
          set("addition_armor",100);

    set("Merits/wit",3);
        set("addition_damage",50);
      set("no_busy",1);
        add("apply/hit",50);
        setup();
      carry_object(__DIR__"eq/star_necklace")->wear();
        set("actions", (: call_other, __FILE__, "query_action" :));
}
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
void die()
{
        object ob;
        
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
        message("world:world1:vision",

           HIW"\n【十萬大山】"+HIW"終生守廟的殞星老者竟然被"+ob->name(1)+"毀滅了..這意味著什麼...?\n\n"+NOR,users());
            ob->add("popularity",6); //聲望
        ::die();
        return;
}

void init()
{
       add_action("typetake","take");
}
     int typetake(string arg)
{
        object me;
        me=this_player();
        message_vision("殞星老者冷冷的瞪著$N\n",me);
        message_vision("殞星老者輕蔑的說:想動這個神廟?...哼 ...!\n",me);
        return 1;
}

