#include <ansi.h>
inherit NPC;
void create()
{
 set_name("天梟十八代弟子",({"apprentice",}));
 set("long","你彎腰看了一看這個似乎只有十歲大的弟子, 想來他一定\n"
            "是其他天梟弟子的家眷, 不過家眷歸家眷, 看他手中匕首\n"
            "揮來揮去倒也頗有章法, 顯然並不好欺負.\n"
     );
 set("attitude","peaceful"); 
 set("age",12);
 set("gender","男性");
 set("level",10);
 set_skill("unarmed",20);
 set_skill("dagger",20);
 set_skill("sky-dagger",10);
 set("chat_chance",5);
 set("chat_msg", ({"天梟弟子對著空中急刺三匕! \n",
                    "天梟弟子揮動匕首, 口中念念有詞...\n"
}));
setup(); 
carry_object(__DIR__"eq/owl_cloth")->wear();
carry_object(__DIR__"eq/owl_armor")->wear();
carry_object(__DIR__"eq/grass_boots")->wear();
carry_object(__DIR__"eq/dagger")->wield();}

