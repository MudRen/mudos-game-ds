#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("水手服",({"waterman cloth","cloth"}) );

        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
         set("long","這是水手們常穿的一種衣服，堅韌的布料上留下了\n"
                    "點點鹽漬，在容易磨損的地方也加了補丁。\n"
          );
         set("material", "cloth");
         set("unit", "件");
         set("value",150);

         set("armor_prop/armor", 3);

        }
        setup();
}

