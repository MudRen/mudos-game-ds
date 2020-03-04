#include <ansi.h>
inherit ITEM;
        
void create()
{
        set_name("祭壇", ({"beg table","table"}) );
        set("long",@LONG
這桌祭壇看似已有很長的歷史，且也有很長的時間沒有使用，在祭壇
的後面還有一座廢棄的火爐，已沒有半點火光，但是祭壇上卻有乾掉
的血跡，是否要用到某種物品，才能解開火元素之謎 ? (screw xxx)

LONG
        );
        set_weight(1000);
        set_max_capacity(10);
        set_max_encumbrance(500000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("no_get",1);
        set("no_drop",1); 
        set("no_sac",1);      
        set("unit", "桌");
        set("volume",5000);
        set("value",123);
        }
        setup(); 
}

void init()
{
        add_action("kok_blood","kok");
        add_action("screw_fire_dragon_liver","screw");
}

int screw_fire_dragon_liver(string str)
{
        object me=this_player();
        object ob;

        if(str=="fire-dragon liver")
        {
        if(!ob=present("fire-dragon liver",me))
                {return notify_fail("你要擰什麼東西ㄚ ???\n");}

        if(this_object()->query_temp("fire-dragon liver")==1)
                {
                write("擰過了 .. .  .. .\n");
                return 1;
                }
                destruct(ob);
                message_vision(
                HIW"$N將火龍肝用力一擰，鮮紅色的火龍血，盡入眼簾，滴滴上祭壇。\n"NOR,me);
                set_temp("fire-dragon liver",1);
                return 1;
        }

}

int kok_blood(string str)
{
        if(this_object()->query_temp("opened") != 0) return 0;
        
        if(str=="blood" || str=="血")
        {
        object me,b;
        me=this_player();

        message_vision(
        HIR"\n$N用力的拍打滴在祭壇上的火龍肝血！\n"NOR,me);

         if(this_object()->query_temp("fire-dragon liver")==1)        
         {
          message_vision(
          HIB"忽然一陣"HIR"火 苗"HIB"從火爐中竄出，沉重的腳步聲慢伐而出 . . . . \n"NOR,me);

          b=new(__DIR__"fire.c" );
          b->move(environment(this_object()) );
          delete_temp("fire-dragon liver");
          //set_temp("opened",1);
          return 1;
          }
        else
          {
          message_vision(
          HIG"$N像一個呆子一樣...不知道在幹嘛。\n"NOR,me);
          }
        return 1;
        }
}

