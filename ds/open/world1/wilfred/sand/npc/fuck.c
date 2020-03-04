#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", HIW"幽"HIC""BLK"靈"HIW"地"HIC""BLK"帶"NOR"入口"NOR);
  set ("long", @LONG
在古老的傳說中，位於在紫陽山的一處，有著讓人膽顫心驚的地
方，就是這─「幽靈地帶」，在這有著紫陽四老都怕的白鬼四幽，此幽
靈有著四種不同特質的神力，令人聽聞就不經的留下冷汗。
LONG
);
  set("exits", ([
  "enter" : __DIR__"enter",
  "down" : "/open/world1/cominging/purple_sun/4f4",
  ]));
  set("no_clean_up", 0);
  set("outdoors","land");
  setup();
 }
 
int valid_leave(string dir)
{
object ob, me;
        if(dir=="enter")
                 message("world:world1:vision",
HIW"\n\t\t"+ob->name(1)+""HIR"闖入了幽靈地帶∼∼"NOR,users());

        return ::valid_leave(me,dir);
}
