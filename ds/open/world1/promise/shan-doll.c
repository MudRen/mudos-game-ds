#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("����s"HIC"����"NOR, ({ "shan doll","doll",}) );
        set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","
�P���Z�ж}�s���v���ˤl�p�P�A�Q���i�R������
\n"NOR);
                set("unit", "��");
                set("material", "gold");
                set("no_sell",1);
               set("no_drop",1);
               set("no_auc",1);
               set("no_get",1);
              set("no_give",1);   
                set("value",4800);
        }
              setup();

}
int query_autoload() { return 1; }

