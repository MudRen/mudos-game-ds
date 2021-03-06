#include <ansi.h>
inherit NPC;
void create()
{
 set_name("天梟教眾",({"apprentice",}));
 set("long","你彎腰看了一看這個似乎只有十歲大的弟子，想來他一定\n"
            "是其他天梟弟子的家眷，不過家眷歸家眷，看他手中匕首\n"
            "揮來揮去倒也頗有章法，顯然並不好欺負.\n"
     );
 set("attitude","peaceful"); 
 set("age",12);
 set("gender","男性");
 set("level",15);
 set("max_hp",6000);
 set("str",40);
 set("Merits/bar",2);
 set("title", "天梟教第九代教眾");
 set_skill("unarmed",80);
 set_skill("dagger",40); 
 set_skill("dodge",40);
 set_skill("parry",40);
 set_skill("sky-dagger",40);
 set("chat_chance",5);
 set("chat_msg", ({"天梟弟子對著空中急刺三匕！\n",
                   "天梟弟子揮動匕首，口中念念有詞……\n"
 }));
setup(); 
carry_object(__DIR__"eq/owl_cloth")->wear();
carry_object(__DIR__"eq/owl_armor")->wear();
carry_object(__DIR__"eq/grass_boots")->wear();
carry_object(__DIR__"eq/dagger")->wield();
}

