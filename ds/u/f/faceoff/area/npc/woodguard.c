#include <ansi.h>
inherit NPC;
void create()
{
 set_name("天梟護木使",({"wood guard","guard"}));
 set("long","眼前這些高大挺拔的大個子是由天梟創教百選一的弟子
所任他們都是經過宣誓世世代代都堅守這棵神木, 並且不讓非天梟教
的外人靠近,但天梟的分裂使他們不再承認天梟,也養成了他們現在這
種見人就殺的習性....."
     );
 set("attitude","killer"); 
 set("age",42);
 set("gender","男性");
 set("level",15);
 set_skill("unarmed",60);
 set("chat_chance_combat",200);
                         (:command,"say 哼! 天梟豈是你好欺? ":),

 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}

