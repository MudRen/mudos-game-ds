#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"廣場"NOR);
 set("long",@LONG 
眼前這口數十年的大井是這些村民生活的最主要水供給來源
，再幾十年前就被這裡當地的居民挖掘出來，看著裡面清澈乾淨
又溫暖的泉水，你不禁想喝一口！
LONG
    );

       set("exits",([
       "north":__DIR__"town8",
       "south":__DIR__"town6",
       "west":__DIR__"town14",
       "east":__DIR__"town15",
           ]));

        set("objects", ([
           ]));
        set("item_desc",([

                  "古井" : GRN"一口擁有數十年歷史的古井，可供人飲用(drink water from well)。\n"

                ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();

}        
void init()
{
          add_action("do_drink","drink");
}

void gone(object me)
{
        if( !me ) return ; 
        me->set_temp("str_drinked", 0);
        me->add_temp("apply/str", -5);
        me->set("hp", me->query("hp")/2);
        tell_object(me, "你開始覺得疲倦了。\n");
}

void again()
{
        set("drinked", 0);
}

int do_drink(string str)
{

        object me;
        me = this_player();
        if(str!="water from well") return notify_fail("你想喝什麼？！\n");
        if(me->is_fighting()) return notify_fail (HIC"戰鬥中不能喝。\n"NOR);
        if( query("drinked") )
                return notify_fail("井裡的水似乎不太夠了。\n");
        me->add("hp", 50); 
        me->add("mp", 50);
        me->add("ap", 50); 
        if( me->query_temp("str_drinked") || me->query("level") > 4 )
                return notify_fail("你覺得井裡的水十分清涼。\n");
        tell_object( me, "你喝了井裡的水之後，覺得全身的力量都湧出來了。\n");
        me->add_temp("apply/str", 5);
        me->set_temp("str_drinked", 1);
        set("drinked", 1);
        return 1;
}



