// 新增int setting() 及 int do_look() 以識別馬主身分
// alickyuen@ds 2003.1.12.
#include <ansi.h>
#include <login.h>
inherit F_HORSE; // use inheritance by tmr 2006/12/08

void flee();

/*string *horse = ({
        HIY+" 赤兔馬"+NOR,
        HIR+" 汗血寶馬"+NOR,
        HIG+" 千里馬"+NOR,
        HIW+" 四不像"+NOR,
        HIC+" 閃龍飛電"+NOR,
        CYN+" 霹靂"+NOR,
        BLU+" 黑神駿"+NOR,
        WHT+" 踏雪烏騅"+NOR,
        HIW+" 墨玉蹄兔"+NOR,
        MAG+" 騮鷾追雪"+NOR,
        HIM+" 騮鬖燎羽"+NOR,
        RED+" 赤燄追日"+NOR,
});
*/

void create()
{
        set_name(HIR"壯碩大馬"NOR,({"the best horse","horse"}));
        set("long","這是由中國各地所搜集而來的名馬，你如果要改他的名字請用(name)。\n");
        set("race","野獸");
        set_weight(30000);

        set("limbs", ({ "頭部","身體","前腳","後腳","頭部" }));
        set("verbs", ({ "bite","claw","crash" }));

        set("level", 5);
        set("age",10);

        set_temp("apply/damage",10);

        set("no_get",1);
        set("no_drop",1);
        set("amount",1);
        set("ridable",1);

        set("chat_chance",1);
        set("chat_msg",({
          (: command("dog") :),
          (: command("cat") :),
          this_object()->name()+"在路上跑了跑。\n",
          (: command("pure") :),
          (: command("jump") :),
          (: command(":D") :),
          (: command(":)") :),
          (: command(":P") :),
        }));
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({ (: flee :) }));
        set("unit","匹");
          set("value", 8000);
        set("member0","none");
        set("member1","none");
        set("member2","none");
        set("max_remember", 3); // 最多記三個
        setup();
        if( this_object()->query("buyer_id") ) 
        {
                set_living_name("com_horse/"+this_object()->query("buyer_id"));
                set("long", this_object()->query("long") + "你看到這匹馬的馬身上刻了 "+this_object()->query("buyer_id")+" 這幾隻大字。\n");
        }
}

