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
                    __DIR__"npc/cobra" : 2,
                    __DIR__"npc/boa" : 1,
        ]));
        set("exits", ([
              "north" : __DIR__"chink02",
              "out" : __DIR__"backyard07",
        ]));
         set("item_desc", ([                    
                "stone": HIB"\n這塊石頭呈藍靛色，散發著陣陣寒氣，石塊上凹陷進去的是個右手手掌形。\n"NOR,
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
        	
        if( (int)me->query_temp("move_stone") ) 
                return notify_fail("你已經推動過了石塊。\n");
                
        if (arg == "stone" ){   
           	message_vision("$N深深吸了口氣，伸出右手按住石塊上的手印，緩緩向下推去。\n", me); 
           	me->set_temp("move_stone", 1);
           	message_vision("$N將石塊按下寸許\，隱隱約約聽到地下傳來一陣轟隆聲。\n", me); 
           	me->start_busy(5);      
           	call_out("poisoned", 5, me);
        }     
        return 1;
}

int poisoned(object me)
{
        if(!me) return 0;
        
        if ((int)me->query_skill("anti_poison", 1) < 50 ){
               tell_object(me, HIB "你感到石塊上的陰氣順著手臂慢慢傳了上來。\n\n" NOR );
               message_vision("$N突然身子一顫，好像是中了寒毒！\n", me);
               me->apply_condition("cold_poison", me->query_condition("cold_poison")+random(30));
               return 1;
               }   
        else {
               tell_object(me, HIB "忽然一股陰氣順著手臂從石塊上慢慢傳了上來。\n\n" NOR );
               tell_object(me, HIW "你連忙運功\調氣，將侵入手臂的寒氣盡數逼了出去。\n" NOR );
                me->apply_condition("poison", me->query_condition("poison")+random(20));
               return 1;
               }           
}
