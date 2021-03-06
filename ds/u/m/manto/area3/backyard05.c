#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "花園");
        set("long", @LONG
這是個不大的花園，中間一堆假山，一條小溪。旁邊種滿了各類花草，
芳香宜人。北面有一道鎖著的鐵門(door)，可以通往另一個院子。
LONG);
        set("exits", ([
              "south" : __DIR__"backyard04",
        ]));

        set("item_desc", ([                    
                "door": "\n這道鐵門極其沉重，看來沒有幾百斤臂力推它不動。真是奇怪為
何會有如此鐵門在此，就連一般人都可以翻越(climb)旁邊的矮牆。\n",
        ]));
        setup(); 
}

void init()
{

        add_action("do_climb", "climb");
        add_action("do_push", "push");
        add_action("do_smell", "smell");                  
}

int do_climb(string arg)
{
        int dex, i = 0;
        object me = this_player();    
            
        dex = me->query_dex();     
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("你正忙著呢。\n");
        	
       	if (dex < 18 )
       	
        	return notify_fail("這矮牆雖矮，你卻怎麼也翻不過去。\n");
       	
       	if (dex > 17 && dex < 25){  
           	message_vision("$N雙手在矮牆上一按，一翻身便縱了過去。\n", me);
           	i = 1;
        	}
        
       	if (dex > 24 && dex < 36){  
           	message_vision("$N運功\提氣輕輕一縱，便躍了過去。\n", me);
           	i = 2;
        	}
        
       	if (dex > 35){  
           	message_vision("$N腳尖輕輕一點，高高躍起，飄了進去。\n", me);
           	i = 3;
        }    
        me->set_temp("backyard_climb", i);
        me->move(__DIR__"backyard06");
        me->start_busy(2);
        return 1;   	    
}

int do_push(string arg)
{
        int str;
        object me = this_player();
        
        str = me->query_str();

        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("你正忙著呢。\n");
        	
        if( !arg || arg=="" ) return 0;
        
       	if (arg == "door" ){
       		if (str < 10 )
               		return notify_fail("你使出了吃奶的力氣，可就是推不動這鐵門。\n");
               		
       		if(str < 20)
           			message_vision("$N使出全身力氣推向鐵門，可鐵門只輕輕動了一下。\n", me);

       		if(str > 19) 
           		message_vision("$N內勁運轉，雙掌平伸推向鐵門。\n", me);
           		message_vision("鐵門突然打開，$N一沒留神滾了進去。鐵門卻又合上了。\n", me);
           		me->receive_damage("hp", 200);
           		me->receive_damage("ap", 100);
           		me->move(__DIR__"backyard06");
           		message("vision", "只聽啪的一聲，一個人影從鐵門出滾了過來！\n",environment(me), ({me}));
           		return 1;
           		
       		}
       	else return 0;        
}

int do_smell(string arg)
{
        int con = this_player()->query("con");

      	if ( con > 29 && con < 37)
         	write("你輕輕吸了吸氣，突然感覺到花香中隱隱帶有股腥味。但聞不出是從哪兒來的。\n");      
      	if ( con > 36 )
         	write("你輕輕吸了吸氣，突然感覺到花香中隱隱帶有股腥味。好像是從鐵門那邊的院子飄來的。\n");       
      	if ( con < 30 )
         	write("你輕輕吸了吸氣，全是芬芳的花香，你都快醉了。\n");                     
       	return 1;        
}

int valid_leave(object me)
{        
       me->delete_temp("backyard_climb");
       return ::valid_leave(me);
}