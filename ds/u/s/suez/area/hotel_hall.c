#include <ansi.h>
inherit ROOM;
void create()
{
       set("short",HIY"月嵐客棧大廳"NOR);
       set("long",@LONG
這裡是月嵐客棧的大廳，全部木製的家具被擦的乾乾淨淨，泛出柔和
的光澤。清涼的風在樑間吹送著，外面植物的枝葉也沙沙作響。這裡雖然
不明亮，但是山中的氣息卻讓你覺得心中一片平靜。如果說這裡有任何讓
你不自在的，那就只有窗口邊那位美艷的老闆娘了。
LONG
        );

         set("exits", ([
         "out": __DIR__"hotel_f",
       "east":__DIR__"hotel_path",
         ]));

        set("objects",([

              __DIR__"npc/yen-lu-yu" : 1,
              __DIR__"npc/waiter" : 1,
          ]) );
       
        set("light",1);
        set("valid_startroom", 1);
        set("map","hotel");
        setup();
        replace_program(ROOM);
 }
