
inherit ROOM;

void create()
{
 set("short","山中小徑");
        set("long",@LONG
細細的山溝在小徑旁緩緩流動著，遠方的山壁有一條白練懸垂著，那
是一個小瀑布，山泉由瀑布源頭流到這裡，在這裡聚集成一小水窪，隨即
就流入地下。水窪邊的柳樹形狀奇特，附近地形也平坦多了，不少人在此
駐足，一享山林之美。
LONG
        );

         set("exits", ([
         "southdown": __DIR__"path_2",
//         "northup": __DIR__"path_t",
         "west": __DIR__"path_lake",
         ]));

         set("hide_exits", ([
         "east": __DIR__"grass",
         ]));

        set("objects",([
              __DIR__"npc/traveler" : 1,
               __DIR__"npc/obj/three-gentlemen_t" : 1,
              ]) );
        
        set("outdoors","land");
        
        setup();
        replace_program(ROOM);

 }