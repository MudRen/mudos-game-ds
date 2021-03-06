#include <ansi.h>
#include <path.h>
inherit ROOM;

void create()
{
        set("short", "遺世島－"HIC"海角天涯"NOR);
        set("long", @LONG
這裡是一斷崖，距離海面約有百尺高，崖下是澎湃翻騰的海浪及
巨大尖銳的礁石，強勁的海風讓你搖搖晃晃難以站穩，一波波海浪撞
擊崖壁形成沖天的浪花，可謂天然奇景，如果在這邊吹號角的話，說
不定可以傳到大陸。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"room44",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("no_auc", 1);
        setup();
}

void init()
{
        add_action("do_bugle","bugle");
}

int do_bugle(string str)
{
        object me,z,ob;
        me=this_player();

        if(!objectp(z=present("horn bugle",me) ) )
        return notify_fail("你要吹什麼？ \n");

        // 1/13 新增 by ksj
        ob=find_living("_NPC_LEVIATHAN_");
        if( objectp(ob) )
        {
          if(!environment(ob) )
          {
            destruct(ob);
          }
          else
          {
            message_vision("$N舉起號角用力的吹響，嗚∼嗚∼的聲響直達天際。\n",me);
            return 1;
          }
        }
 
        destruct(z);
        message_vision(
        HIW"\n$N舉起號角用力的吹響，嗚∼嗚∼的聲響直達天際，哇，連號角都吹裂了。\n"NOR
        HIC"\n突然海中一道巨大的黑影迅速接近，一條巨大的身影從海中浮現！\n\n"NOR,me);
        message("world:world1:vision",
        HIR"\n\t"HIG" 遺世島 "HIR"的方向傳來響亮的號角聲，隨後一道巨浪襲向"HIC"海角天涯"HIR"！！\n\n"NOR
        ,users());
        me->add_busy(1);
        new(__DIR__"npc/leviathan")->move(environment(me));
        return 1;
}
