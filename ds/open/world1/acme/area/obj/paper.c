#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("紙", ({ "paper" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
           set("long",
               "這紙已泛黃，已相當破爛，勉強可見上頭幾行血字：\n\n"
               HIR"…………今…本將神殺…典……藏於此……，………\n"
               "幽冥…佬…尾隨…，當要……時…遭幽冥………偷…\n"
               "暗算……\n\n"NOR
               "當你看到這裡時，下半面的紙卻遭註蟲蝕去，無從得知。\n",
           );
           set("unit","張");
        }
     setup();
}
