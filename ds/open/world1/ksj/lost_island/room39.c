#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "遺世島－"CYN"黑沼地"NOR);
        set("long", @LONG
這裡是一片空壙深黑的沼地，地面上寸草不生，只有一個地洞，
走在地面上感覺軟軟浮浮的，很是奇特，地面好像不時的在起伏，也
許只是錯覺。
LONG
        );
        set("exits", ([ 
            "southeast" : __DIR__"room36",
            "northeast" : __DIR__"room40",
            "west" : __DIR__"room41",
            "southwest" : __DIR__"room38",
            "northwest" : __DIR__"room42",
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("no_auc", 1);
        set("objects",([
           __DIR__"hole":1,
           ]) );
        setup();
}

int room_effect(object me)
{
          switch(random(10))
        {
         case 0:
         case 1:
         case 2:

                message_vision("你的雙腳正慢慢陷入泥沼中．．．。\n",me);
                if(me->query_skill("dodge")< 35 && random(10)<3 )
                {
                        tell_object(me,YEL"等你發現時，已深陷於泥沼，一時動彈不得！！\n" NOR ); 
                        me->add_busy(5);
                }

                else if(me->query_skill("dodge")< 70 && random(10)<3 )
                {
                        tell_object(me,YEL"等你發現時，已深陷於泥沼，一時動彈不得！！\n" NOR ); 
                        me->add_busy(3);
                }

                else if(me->query_skill("dodge")>69 && random(10)<3 )
                {
                        tell_object(me,YEL"等你發現時，已深陷於泥沼，一時動彈不得！！\n" NOR ); 
                        me->add_busy(1);
                }
                return 1;
        

         default:       return 1;
        }
}

