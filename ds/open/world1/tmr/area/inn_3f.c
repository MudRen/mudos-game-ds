#include <command.h>
#include <path.h>
inherit ROOM;
void create()
{
        set("short", "三樓");
        set("long", @LONG
在三樓的樓梯口擺著一張牌子，寫道：「整修中，暫停開放」，看來
此層還在整修中，右面牆壁上破了一個大洞，地板滿是坑坑洞洞，憑「朝
天樓」的財務，怎會任其如此?
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
"down" : __DIR__"inn_2f",
//"up" : "/u/a/alickyuen/open/christmas/chris1",
        ]));
        set("item_desc",([      
        "大洞" : "一個開在牆壁上的大洞，可看到街上不時過往的人群。\n跳下去(jump into hole)可能會受重傷喔!\n",
        "hole" : "一個開在牆壁上的大洞，可看到街上不時過往的人群。\n跳下去(jump into hole)可能會受重傷喔!\n",
        ])      );
        set("light",1);
        set("no_clean_up", 0);
         set("objects", ([ /* sizeof() == 1 */
                "/open/lottery/erika" : 1,
//                    "/open/world1/tmr/game/2008_ghost/board" : 1,
          ]));

        setup();
} 
/*
void init()
{
 add_action("do_jump","jump");
}

int do_jump(string arg)
{
 object me,*inv;
 int i;
 string buffer1,file;
 me=this_player();
 if(!arg) return 0;
 if(me->is_busy()) return notify_fail("你上一個動作還沒完成。\n");
 if(sscanf(arg, "into %s", arg)==1)
 {
  if(arg=="hole" || arg=="大洞")
  {
   if(me->query_temp("ride"))
   {
        write("雖然你願意跳, 可是你的座騎卻不願意..\n");
        return 1;
   }
   if(me->query_temp("killer"))
  {
    write("你殺了人暫時不可以跨越時空!\n");
    return 1;
  }
   if(me->query_temp("invader"))
  {
    write("你攻擊了玩家暫時不可以跨越時空!\n");
    return 1;
  }
   inv = all_inventory(me);
   for(i=0; i<sizeof(inv); i++)
   {
    if(inv[i]->query("secured")) inv[i]->delete("secured");
    if(!inv[i]->query("base_value"))
    {
     file=base_name(inv[i]);
     if((sscanf(file,"/open/world2/%s",buffer1)!=1 && sscanf(file,"/open/always/%s",buffer1)!=1 )
     || inv[i]->query_max_encumbrance() > 0)
     {
      if(inv[i]->query("equipped")) inv[i]->unequip();
      DROP_CMD->do_drop(me, inv[i]);
     }
    }
   }
   tell_room(environment(me),me->name()+"深吸了一口氣, 奮力的朝牆壁的大洞跳了出去。\n",({ me }));
   message("system", "$N丟下一些多餘的物品, 深吸了一口氣, 奮力的朝牆壁的大洞跳了出去。\n\n",me);

 me->move(NOW"anfernee/start/pastroom");
 me->set("startroom",NOW"anfernee/start/pastroom");
 me->save();
 message("system", "突然一陣空間的扭曲.. 你又回到了熟悉的地方。\n\n",me);
 tell_room(environment(me),me->name()+"突然從屋頂上的破洞跌了下來。\n",({ me }));
 me->start_busy(1);
   return 1;
  } 
 }
 else return 0;
}
*/

