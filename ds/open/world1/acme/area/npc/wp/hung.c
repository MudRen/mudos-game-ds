#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIR "���мC" NOR, ({ "hung chan sword","sword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "��");
               set("limit_str",26);
               set("long", "�o��C�e������A���p�U�N�����P���A�o��C�W�Q�L��C\n");
               set("wield_msg", "$N�q�I��C�T����X�@�������$n�A���b�⤤��Z���C\n");
               set("unwield_msg", "$N�N�⤤��$n���J�I��C�T���C\n");
               set("value",4000);
set("volume",5);
               set("rigidity",375);     //�w��
        }
   init_sword(40);
setup();
}
