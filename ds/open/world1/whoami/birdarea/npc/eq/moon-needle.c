#include <weapon.h>
#include <ansi.h>
inherit NEEDLE;

void create()
{
        set_name( "��w" ,({"moon needle","needle"}) );
        set("long","�@����Ŧ⪺�Ȱw�A�D�`���y�U�C\n");
          set_weight(1200);
          if (clonep() )
          set_default_object(__FILE__);
          else {
                set("unit","��");
                set("value",1000);
                set("material", "silver");
               }
          init_needle(14);
          setup();        
}

