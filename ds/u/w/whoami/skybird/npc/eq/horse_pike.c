#include <weapon.h>
#include <ansi.h>
inherit PIKE;

void create()
{
        set_name(HIW"麟馬槍"NOR, ({ "unicorn-horse pike", "pike" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 16000);
               
                set("long", 
"據說 , 這把槍是而匹馬打造的 , 但是這匹馬的智商卻超乎常人所能想像的高\n牠把自己的麟角折了下來 , 用嘴把角跟用花鋼石焊接在一起 , 而這匹馬就是古代傳說的 麒麟。"
                );
                set("wield_msg",HIG "$N拿起手中的$n , 頓時灰沙飛起 , 萬馬奔騰。\n"NOR); 
                set("unwield_msg",HIG "$N放下手中的$n , 黃沙也漸漸的散落一地。\n"NOR_;                
        }
     init_pike(68);
        setup();
}