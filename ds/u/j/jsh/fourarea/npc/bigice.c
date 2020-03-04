#include <ansi.h>
inherit ITEM;
        
void create()
{
        set_name("千年魄冰", ({"thousand ice","ice"}) );
        set("long",@LONG
這是一塊很大塊的冰，有極高的歷史，中間還有一個類似鑰匙洞
的孔 (put xxx)，這塊冰塊的溫度似乎很低，不知道有什麼東西 
可以把這塊冰給融化，解開冰元素之謎底。(kok xxx)
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
        set("unit", "塊");
        set("volume",5000);
        set("value",123);
        }
        setup(); 
}

void init()
{
        add_action("kok_ice","kok");
        add_action("put_key_of_fire","put");
}

int put_key_of_fire(string str)
{
        object me=this_player();
        object ob;

        if(str=="key of fire")
        {
        if(!ob=present("key of fire",me))
                {return notify_fail("你要放什麼東西ㄚ ???\n");}

        if(this_object()->query_temp("key of fire")==1)
                {
                write("你已經開過了 \n");
                return 1;
                }
                destruct(ob);
                message_vision(
                HIR"$N將火燄之鑰放進千年魄冰的匙孔裡，只見火燄之鑰瞬間爆燒，千年魄冰似乎裂了開來。\n"NOR,me);
                set_temp("key of fire",1);
                return 1;
        }

}

int kok_ice(string str)
{
        if(this_object()->query_temp("opened") != 0) return 0;
        
        if(str=="ice")
        {
        object me,b;
        me=this_player();

        message_vision(
        HIW"\n$N往千年魄冰的中心點敲了敲 . . . 千年魄冰整個碎開！\n"NOR,me);

         if(this_object()->query_temp("key of fire")==1)        
         {
          message_vision(
          HIW"天空降下了片片的"HIC"雪花 \n"NOR,me);

          b=new(__DIR__"ice.c" );
          b->move(environment(this_object()) );
          delete_temp("key of fire");
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

