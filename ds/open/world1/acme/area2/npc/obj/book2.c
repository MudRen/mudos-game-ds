#include <ansi.h>
inherit ITEM;
void create()
{
       set_name(HIR"《幽冥神殺寶典》"NOR,({"you ming book","book"}));
       if( clonep() )
         set_default_object(__FILE__);
       else {
          set("unit", "本");
          set("long",
              "這是一本花費了天殘邪佬十年的光陰才撰寫而\n"
              "成的書，傳說中能夠一口氣爆發人體極限本能\n"
              "但是裡頭一頁也不剩，只剩下殘破的書皮。\n");
            }
        set("value", 0);
        set_weight(250);
        setup();
}
