#include <ansi.h>
inherit NPC;
void create()
{
 set_name("上官鶴",({"killer",}));
 set("long","             你看了一看眼前的老人,實在無法想像他有什麼作為 , 這個老人雖
             然目前以經七十七歲了, 不過他的眼中反而射出一股令人害怕的精
             光, 原來他就是三十年前名震江湖的有名殺手--箏劍雙絕 上官鶴! 
             只是隨著歲月流失, 他的兇狠與日俱減, 圍剿絕命雙煞得行動完後
             , 他就正式宣告退隱, 並且改其稱號為箏不離手, 這次受邀於尉遲
             妄, 來到英雄樓效力.\n"
    );
 set("attitude","peaceful"); 
 set("age",67);
 set("gender","男性");
 set("level",30);
 set("title",HIY"箏不離手"NOR);
 set_skill("unarmed",55);
 set_skill("sword",80);
 set_skill("force",60);
 set_skill("parry",70);
 setup();
 carry_object(__DIR__"eq/longsword")->wield();
 carry_object(__DIR__"eq/cloth")->wear();
}
