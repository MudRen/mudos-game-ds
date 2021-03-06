#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "縫隙");
        set("long", @LONG
這裡是石塊與石塊之間的夾縫，光線昏暗。你明顯感覺到四周的沙沙
聲是各種毒蟲爬行的聲音，一股股腥味中也夾雜著一些刺鼻的氣息。你發
現前面有一石塊(stone) 隱隱發出淡淡的光芒。
LONG);
        set("objects", ([
                    __DIR__"npc/boa" : 1,
        ]));
        set("exits", ([
              "east" : __DIR__"chink02",
              "out" : __DIR__"backyard09",
        ]));
         set("item_desc", ([                    
                "stone": HIW"\n這塊石頭呈乳白色，散發著陣陣暖氣，石面有一道五彩色的細線，
石塊上凹陷進去的是個左右兩個手掌的手掌形。\n"NOR,
        ]));
        setup(); 
}

void init()
{
        add_action("do_push", "push");      
}

int do_push(string arg)
{
        object me = this_player();
        if( !arg || arg=="" ) return 0;
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("你正忙著呢。\n");
        	
        if( !me->query_temp("move_stone") ) return 0;
        if( (int)me->query_temp("move_stone") > 2) 
                return notify_fail("你已經推動過了石塊。\n");
        if (arg == "stone" ){   
           	message_vision("$N深深吸了口氣，伸出雙手按住石塊上的手印，緩緩向下推去。\n", me);           
           	me->add_temp("move_stone", 1);
           	message_vision("$N將石塊按下寸許\，隱隱約約聽到地下傳來一陣轟隆聲。\n", me);            
        	me->start_busy(5);      
        	call_out("poisoned", 5, me);
        	return 1;
        }     
        return 0;
}


int poisoned(object me)
{
	if (!me) return 0;
        if ((int)me->query_skill("anti_poison", 1) < 70 ){
               tell_object(me, MAG "你感到手心一涼，那道五彩細線已經附在你的手心上。\n" NOR );
               message_vision("$N突然身子一顫，好像是中了毒！\n", me);
               me->apply_condition("super_poison", me->query_condition("super_poison")+random(20)+10);
               return 1;
               }   
        else {
               tell_object(me, MAG "忽然你的手心一涼，那道五彩細線已經附在你的手上。\n" NOR );
               tell_object(me, HIW "你連忙運功\調氣，將手心的五彩細線逼出了大半。\n" NOR );
               me->apply_condition("poison", me->query_condition("poison")+30);
               return 1;
               }
                
}
