#include <ansi.h>
inherit NPC;
void create() {
   set_name(HIW+"魔。神"+NOR, ({"devil_god","god"}});
   set("long",@Long
你只不過是望他一眼，然而你整個人卻如同落入永無止盡的黑暗深淵
，站在你眼前的，依然是之前那位少年，但此時他身上所散發出來的
氣勢，卻遠遠臨駕於天地萬物之上，就在此時，他轉頭望向你，在他
的眼中透露出：「高傲、輕視、憐憫、嘲弄」等多種神情，此時你開
始有點後悔，早知道他真的的是五千年前，以一己之力將天、魔兩界
殺的體無完膚，並同時擁有天神和惡魔兩種極端力量的魔。神的話，
就不應該來與他為敵的。
Long
     );
   set("level",10);
   set_living_name("devilgod");
   set("combat_exp", 10000000);
   set("give_exp", 100000000);
   set("chat_chance",10);
   set("chat_msg",({
       "魔。神以冷冽的目光瞪了你一眼。\n",
       "魔。神面無表情的望著你。\n",
            }));
}

void die()
{
        object ob;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);

        if( !ob ) return;

        message("system",
                HIR "\n\n你聽到一聲帶著憤恨、驚恐、與野獸般的咆哮聲響徹整個天空。\n\n"
                HIW "侮天鬼王" HIR "嘶啞地吼著﹕可惡的" + ob->name(1) + "﹐我一定會報仇的∼∼∼\n\n"
                        "然後一道黑色火焰呼嘯著衝上雲端﹐大地又恢復了寧靜。\n\n" NOR,
                users() );
        destruct(this_object());
}
