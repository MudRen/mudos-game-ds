#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIM "殭屍" NOR ,({ "zombie" }) );
         set("level",20);
        set("age", 200);
        set("long", "這是一具已死去二百多年的死屍，但並未腐爛，模樣令人作噁。\n"
);
      set("con",15);
         set("exp",1000);
       set_skill("dodge",50);
        set_skill("unarmed",50);
        set_skill("parry",50);
        set("unit","隻");
      set("race","人類");
             set("attitude","killer");

        set("chat_chance", 5);
         set("chat_msg",({
          "殭屍從口中發出：「荷∼∼荷∼∼」的聲音。\n"
     }));
        set("chat_msg_combat", ({
                "殭屍的臉上開始痙攣﹐一陣抽搐﹐發狂似地大叫。\n",
                "殭屍五指箕張﹐咬牙切齒﹐露出猙獰的笑容。\n",
        }) );

        setup();
}
