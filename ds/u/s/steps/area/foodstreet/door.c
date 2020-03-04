#include <ansi.h>
inherit ROOM;
void create()
{
          set("short",HIG"ST．Door＠FoodStreet"NOR);
          set("long",
          "【世界食品街】，你在這裡看到這個電子告示板，就知道這裡就是你\n"
          "想要去的地方了，這裡正在大肆宣傳，你心想進去這條食品街，看看有什\n"
          "麼特別的好吃的美食來填滿你空空的肚子。\n"
);
          set("exits", ([ /* sizeof() == 4 */
          "north":"/u/s/steps/area/street1.c",
          "southup":"/u/a/alickyuen/area/dst15.c",
          ]));
          set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/woman" : 1,
]));
          set("chat_chance", 4);
          set("chat_msg", ({
                HIY"”大家好，世界食品街新開幕，多謝大家支持”\n"NOR,
                HIY"”多種世界美食都在食品街內，大家快試試吧”\n"NOR,
        }));
setup();
}
