#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name(HIR"�s"HIY"��"NOR,({ "dragon staff" , "staff" }));
        set_weight(2100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "��");
               set("long", HIW"�ѥj�ͪ�"HIM"���s�I�G"HIW"�����ҥ��y�X�Ӫ�����Q��\n"NOR);

               set("value",9000);
               set("limit_str",22);
               set("limit_con",22);
                set("volume",4);
               set("material", "gold");
        }
init_staff(60);
   setup();
}
