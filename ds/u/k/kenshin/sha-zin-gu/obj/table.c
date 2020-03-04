#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
        set_name("封魔台", ({"fon-mo table"}) );
        set("long",@LONG
此神台是封印住千年巨獸─千年守鶴所製的，聽說此封魔台是幾位
法力高深莫測的聖僧耗近數十年的修為完成的至高封魔台，但是聽
說只要找到一樣能蓋過聖澤天霖聖氣的物品，便能讓大惡不赦的千
古巨獸解放，但是至今所有的武林同道人士就算知道解放千古巨獸
之物品，也不敢恭維。此外這封魔台中央有一凹巢似乎能把一粒小
石子放入(putting xxxx)LONG
        );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("no_get",1);
        set("no_drop",1);
        set("unit", "個");
        set("volume",10000);
        set("value",0);
        }
        setup(); 
}

void init()
{
        add_action("do_putting","putting");
}

int do_putting(string str)
{
        object me,b,z,ob;
        me=this_player();
 
        if(!str || str!="stone") return 0;
        if(!objectp(z=present("evil stone",me) ) )
        return notify_fail("你並沒有招喚千古巨獸之物!! \n");
        ob=find("__DIR__"npc/aeonian-beast.c");
         if( objectp(ob) )
        {
          if(!environment(ob) )
          {
            destruct(ob);
          }
          else
          {
            message_vision("$N把象徵邪惡的代表之物給放下凹槽裡，但是一點動靜也沒有!?\n",me);
            destruct(z);
            return 1;
          }
        }
  
        destruct(z);
        message_vision(
        HIR"\n$N將邪惡代表物「犬惡石」給放進凹槽！！。\n"NOR
        HIG"\n頃刻間，數道金光迎面而出！！\n"NOR 
        HIW"\n大地突然風雲變色！！\n"NOR,me); 
        message("world:world1:vision",
        HIR"\n\t千古巨獸 千"NOR"年守"HIM"鶴"HIW"經過了千年的沉睡，再度降臨於中原！！\n\n"NOR
        ,users());
        b=new(__DIR__"npc/aeonian-beast.c" );
        b->move(environment(this_object()));
        destruct(this_object());
        return 1;
}

