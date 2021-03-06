#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "遺世島－"HIG"獸原"NOR);
  set("long", @LONG
這裡是一望無際的大草原，長滿及膝的青翠雜草，還有許多不知
名的花草植物，草原上飛舞著七彩蝴蝶和奇異的昆蟲，遠遠可以看到
珍禽異獸在草原中奔跑覓食，放眼望去渺無人煙，儼然是動物的世外
桃源。
LONG
);
  set("exits", ([ /* sizeof() == 4 */
      "east" : __DIR__"room27",
      "south" : __DIR__"room24",
      "north" : __DIR__"room30",
     ]));
  set("no_clean_up", 0);
  set("outdoors","land");
  set("no_auc", 1);
  set("treasure_room1",1);
  set("objects",([
       __DIR__"npc/mind-flayer":1,
     ]));
  setup();
}

void init()
{
  object me,z;
  me=this_player();

  if( objectp(z=present("_TREASURE_PAPER_1_",me) ) )
  add_action("do_dig","dig");
}

int do_dig()
{
  object me,ob;
  me=this_player();
 
  if( objectp(ob=present("_TREASURE_PAPER_1_",me) ) )
  {
    if( me->is_busy() )
      return notify_fail("你還在忙，沒時間進行挖掘。\n");
    message_vision(HIW"\n$N對照著圖上的位置，動手開始挖掘。\n"NOR,me);
    destruct(ob);
    me->start_busy(3);
    call_out("digging",3,1,me);
    if( !random(6) )
    {
      call_out("again",5,1,me);
      me->start_busy(7);
      call_out("digging",7,2,me);
      if( !random(6) )
      {
        call_out("again",9,2,me);
        me->start_busy(11);
        call_out("digging",11,3,me);
      }
    }
  return 1;
  }
}

void digging(int c,object me)
{
  switch(c)
  {
    case 1:
         message_vision(HIY"\n一陣辛苦挖掘後，$N挖出了一些財寶。\n"NOR,me);
                new(__DIR__"npc/eq/gold")->move(environment(me));
                if(random(3)==1)
                        new(__DIR__"npc/eq/gold")->move(environment(me));

         break;

    case 2:
         message_vision(HIY"\n$N挖到滿身汗水跟泥土，又挖到了一些寶物。\n"NOR,me);
         switch( random(4) )
         {
           case 0:
                new(__DIR__"npc/eq/gold")->move(environment(me));
                new(__DIR__"npc/eq/gold")->move(environment(me));
                break;
           case 1:
                new(__DIR__"npc/eq/gold-necklace")->move(environment(me));
                break;
           case 2:
                new(__DIR__"npc/eq/gold-earring")->move(environment(me));
                break;
           case 3:
                new(__DIR__"npc/eq/gold-finger")->move(environment(me));
                break;
         }
         break;

    case 3:
         message_vision(HIY"\n$N把周圍五尺挖成了個大洞，終於挖出了一個寶物。\n"NOR,me);
         switch( random(4) )
         {
           case 0:
                new(__DIR__"npc/eq/gold-boots")->move(environment(me));
                break;
           case 1:
                new(__DIR__"npc/eq/gold-mask")->move(environment(me));
                break;
           case 2:
                new(__DIR__"npc/eq/gold-wrists")->move(environment(me));
                break;
           case 3:
                new(__DIR__"npc/eq/intellect-staff")->move(environment(me));
                break;
         }
         break;
  }
}

void again(int c,object me)
{
  switch(c)
  {
    case 1:
         message_vision(HIW"\n$N覺得還有寶物，於是繼續挖掘下去。\n"NOR,me);
         break;

    case 2:
         message_vision(HIW"\n$N看到四周的土色有異，於是繼續挖掘下去。\n"NOR,me);
         break;
  }
}
