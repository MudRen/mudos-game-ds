#include <ansi.h>
inherit ROOM;
void create()
{
     set("short",HIC"悠閒聊天室"NOR);
     set("long",HIW"\n\t來到這裡，就是放鬆您的心情，拋開一切壓力！\n"
                   "\n\t好好的與好友聊上幾句∼^.^∼\n\n"NOR);
             set("exits", ([ /* sizeof() == 1 */
  "north" : "/u/j/jangshow/workroom",
]));
     setup();
}
