#include <ansi.h>
inherit NPC;
void create()
{
 set_name("天梟弟子",({"apprentice",}));
 set("long","                 你彎腰看了一看這個似乎只有十歲大的弟子, 想來他一定
                 是其他天梟弟子的家眷, 不過家眷歸家眷, 看他手中匕首揮來揮去
                 倒也頗有章法, 顯然並不好欺負."
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
 set("chat_chance_combat",200);
                         (:command,"say好啊! 來過兩招":),
 setup(); carry_object(__DIR__"eq/cloth")->wear();
carry_object(__DIR__"eq/dagger")->wield();}
