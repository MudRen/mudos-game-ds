#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name( "教徒", ({ "giautoo"}));
        set("long", "他是一位在這裡鍛鍊技能的靈幻教教徒。\n");
           set("level",3);
        set("title","靈幻教");
        set("gender", "男性");
        set("race", "人類");
        set("age", 42);
 set("evil",-20);                //邪惡度 20 (正的表邪惡, 負表善良)
        set_skill("blade",40);          // 技能(自定)
        set_skill("parry",20);          //
        set_skill("dodge",30);          //
        set("attitude", "peaceful");   //溫和的 NPC。
        set("chat_chance",20);
        set("chat_msg",({
                  "教徒努力的練習著，不時還發出喘氣聲。\n" ,
                  (:command("addoil"):),
         }) );
        setup();
          add_money("coin", 200);           //帶的錢
}


