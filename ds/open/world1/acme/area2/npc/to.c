#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "勾魂使", ({ "to bewitch man","man", "__GUARD__" }) );
        set("level",40);
        set("combat_exp",4000);
        set("evil",80);
set("exp",3000);
        set("long","他是幽冥地窖中和攝魄使合稱『幽冥二燈』的幽冥地窖左右\n"
                   "護法，但不倖於三十年前的天城戰役中，被流影打敗，但流\n"
                   "影宅心仁厚，不將其處死，只挑斷他的腳筋，任其生死。幸\n"
                   "被天殘邪佬所醫救，但從此武功\大退，得意絕技也從此使不\n"
                   "出來。\n"
            );
        set("age",100);
        set("attitude","killer");
        set("gender","男性");
        set("title",HIR"群魔亂舞"NOR);
        set_skill("unarmed",70);
        set_skill("dodge",70);
        set_skill("parry",70);
        set("chat_chance_combat",30);
        set("chat_msg_combat", ({
"勾魂使喝道：哼！哼！要不是三十年前的一次天城戰役中，被流影\n挑斷腳筋，要不然就讓你嚐嚐「千里追魂」的厲害。\n\n",
                       }) );
       setup();
       carry_object(__DIR__"obj/lamp.c");
}
