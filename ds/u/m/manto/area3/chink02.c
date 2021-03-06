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
                    __DIR__"npc/cobra" : 4,
        ]));
        set("exits", ([
              "south" : __DIR__"chink01",
              "west" : __DIR__"chink03",
              "out" : __DIR__"backyard08",
        ]));
         set("item_desc", ([                    
                "stone": HIR"\n這塊石頭呈紅汞色，散發著陣陣熱氣，石塊上凹陷進去的部分是個左手手掌形。\n"NOR,
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
        if( (int)me->query_temp("move_stone") > 1) 
                return notify_fail("你已經推動過了石塊。\n");
                
        if (arg == "stone" ){   
           	message_vision("$N深深吸了口氣，伸出左手按住石塊上的手印，緩緩向下推去。\n", me);            
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
        if(!me) return 0;
        
        if ((int)me->query_skill("anti_poison", 1) < 60 ){
               tell_object(me, HIR "你感到石塊上的炎熱之氣順著手臂慢慢傳了上來。\n\n" NOR );
               message_vision("$N突然身子一顫，好像是中了熱毒！\n", me);
               me->apply_condition("hot_poison", me->query_condition("hot_poison")+random(50));
               return 1;
               }   
        else {
               tell_object(me, HIR "忽然一股炎熱之氣順著手臂從石塊上慢慢傳了上來。\n\n" NOR );
               tell_object(me, HIW "你連忙運功\調氣，將侵入手臂的炎熱之氣盡數逼了出去。\n" NOR );
                me->apply_condition("poison", me->query_condition("poison")+random(20));
               return 1;
               }               
}
