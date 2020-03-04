#include <ansi.h>
inherit NPC;

void create()
{
        set_name("活體四十級八極門", ({"genius"}) );
        set("long", "你可以打他看看....還蠻耐打的\n");
        set("title",HIY"【"NOR"見習"HIY"天使】"NOR);
        set("nickname",HIC"哈"HIG"哈"HIR"哈"HIY"哈"HIC"哈"HIG"哈"HIR"哈"HIY"哈"NOR);
        set("race", "人類");
        set("age", 16);
        set("level", 100);

        set("combat_exp",100000);
        set("chat_chance",20);
        set("chat_msg",({
         (:command("smark"):),
         (:command("spare"):),
         (:command("zap fire"):),
         (:command("exert bagi_fist"):),
         (:command("exert bagi_fist"):),
        }) );

      set_skill("unarmed",100);
      set_skill("combat",100);
      set_skill("bagi_fist",100);
      set_skill("horse-steps",100);
      set_skill("bagi_force",100);
      set_skill("force",100);
      set_skill("dodge",70);
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                (:command("exert bagi_fist"):),
                (:command("exert bagi_force power_up"):),
         }) );

      setup();

      carry_object("/open/always/moon_mark")->wear();
      carry_object("/u/g/genius/eq/flame_coat")->wear();
      carry_object("/u/g/genius/eq/helmet")->wear();
      carry_object("/open/world1/eq/viper_cloth")->wear();
      carry_object("/u/g/genius/wp/wizburnhands")->wield();


}

