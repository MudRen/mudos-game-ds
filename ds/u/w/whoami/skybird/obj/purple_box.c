#include <ansi.h>
inherit ITEM;

void create()
{

        set_name(MAG"紫色"NOR"寶盒",({"purple box","box"}));
        set("long","一個紅色的盒子，裡面或許\裝著什麼值錢的東西也不一定•你可以打開(reopen)它•\n");
        set("unit", "個");
        set("value", 500);
        set("no_get",1);
        setup();

}

void init()
{
        add_action("do_open","reopen");
}


int do_open(string arg)
{
        object ob,me,env;
        me = this_player();
        env = environment(me);
        if (!arg || arg =="")
        return notify_fail("你要打開什麼？\n"); 
        if( me->is_busy() )
        return notify_fail("你還在忙！\n");
        if (arg != "box" && arg != "purple box") return 0;
        
        switch( random(100) ){
          case 0:
           ob = new("/open/world1/ksj/east_island/npc/eq/orochi-armor");
          break;
          case 1:
           ob = new("/open/world1/ksj/east_island/npc/eq/orochi-armor2");
          break;   
          case 2:
           ob = new("/open/world1/ksj/east_island/npc/eq/orochi-cloak");
          break;
          case 3:
           ob = new("/open/world1/ksj/east_island/npc/eq/orochi-waist");
          break;   
          case 4:
           ob = new("/open/world1/ksj/east_island/npc/eq/orochi-leggings");
          break;   
          case 5:
           ob = new("/open/world1/ksj/east_island/npc/eq/orochi-shield");
          break;   
          case 6:
           ob = new("/open/world1/ksj/east_island/npc/eq/orochi-gloves");
          break;   
          case 7:
           ob = new("/open/world1/ksj/east_island/npc/eq/orochi-mask");
          break;   
          case 8:
           ob = new("/open/world1/ksj/east_island/npc/eq/kilin-boots");
          break;   
          case 9:
           ob = new("/open/world1/moonhide/area/snake-surcoat");
          break;   
          case 10:
           ob = new("/open/world1/moonhide/area/leather");
          break;
          case 11:
           ob = new("/open/world1/ksj/lost_island/npc/eq/gold-boots");
          break;   
          case 12:
           ob = new("/open/world1/ksj/lost_island/npc/eq/gold-earring");
          break;   
          case 13:
           ob = new("/open/world1/ksj/lost_island/npc/eq/gold-leggings");
          break;   
          case 14:
           ob = new("/open/world1/ksj/lost_island/npc/eq/gold-necklace");
          break;   
          case 15:
           ob = new("/open/world1/ksj/lost_island/npc/eq/gold-waist");
          break;   
          case 16:
           ob = new("/open/world1/ksj/lost_island/npc/eq/gold-finger");
          break;   
          case 17:
           ob = new("/open/world1/ksj/lost_island/npc/eq/gold-coin");
          break;   
          case 18:
           ob = new("/open/world1/ksj/lost_island/npc/eq/gold-armor");
          break;   
          case 19:
           ob = new("/open/world1/ksj/lost_island/npc/eq/gold-mask");
          break;   
          case 20:
           ob = new("/open/world1/ksj/lost_island/npc/eq/gold-shield");
          break;   
          case 21:
           ob = new("/open/world1/ksj/lost_island/npc/eq/gold-waist");
          break;
          case 22:
           ob = new("/open/world1/ksj/lost_island/npc/eq/huge-tiger-cloth");
          break;    
          case 23:
           ob = new("/open/world1/ksj/lost_island/npc/eq/brambly-crown.c");
          break;
          case 24:
           ob = new("/open/world1/ksj/lost_island/npc/eq/inverse-horn-helmet.c");
          break;
          case 25:
           ob = new("/open/world1/wilfred/sand/npc/eq/eq24.c");    
          break;
          default:
           ob = new("/obj/money/coin");
           ob->set_amount(10000+random(50000));
          break; 
        }
         if ( !ob ) return 1;
         message_vision("\n$N迫不及待的將$n打開一看，結果裡面居然是一"+ob->query("unit")+ob->query("name")+"•\n",me,this_object());
         ob->move(env);  
         destruct(this_object());
   return 1;
}

