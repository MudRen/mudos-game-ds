#include <armor.h>
#include <ansi.h>
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIY"上等金蟬衣"NOR ,({ "cicada cloth","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
 set("long",@LONG
此件寶衣是皇帝的珍藏寶衣，特別賜給有功的人，他的防禦力，
我想不用說了，一定是一級棒的。既然是金蟬衣，當然少不了鑲在上
面一隻一隻的金蟬了，雖然是死掉多時，不過他身上的殼卻還是逐年
的增厚，的確是件寶衣，不過皇帝為何不要，那就沒人知了。
LONG
     );
        set("unit", "件");
        set("value",10000);
        set("material", "steel");
        set("armor_prop/shield",2);
        set("armor_prop/con",2);
        set("armor_prop/armor", 25);
        set("wear_msg",HIY"$N穿上了上等金蟬衣後，似乎聽到了蟬叫。"NOR);

        }
        setup();
}

