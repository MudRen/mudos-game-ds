#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", HIW"幽靈地帶"NOR"入口"NOR);
  set ("long", "
    在古老的傳說中，位於在紫陽山的一處，有著讓人膽顫心驚的地方，就
是這─「幽靈地帶」，在這有著紫陽四老都怕的白鬼四幽，此幽靈有著四種
不同特質的神力，令人聽聞就不經的留下冷汗。\n 
");
  set("exits", ([
  "enter" : __DIR__"f1",
  "down" : "/open/world1/cominging/purple_sun/4f4",
  ]));
  set("no_clean_up", 0);
  set("outdoors","land");
  setup();
 }
 int valid_leave(object me, string dir)
{

        string gender;
        gender=me->query("gender");
        if ( gender=="男性" ) gender="少俠";
        if ( gender=="女性" ) gender="俠女";
        if ( me->query("age") > 50 ) gender="老前輩";
        
        if( dir=="enter" )
        {
 message("world:world1:vision",
HIW"\n\t"+me->query("name")+HIR"闖入了幽靈地帶，"HIG"白鬼四幽"HIR"怒道：\n
"HIY"\t\t這位"HIW+gender+HIY"真是膽大，闖入我們的禁地！！\n
"HIG"\t一聲令下，所有兵衛拾了兵器，準備應戰！！\n\n"NOR,users());
                                            
     }
        return ::valid_leave(me, dir);
}



