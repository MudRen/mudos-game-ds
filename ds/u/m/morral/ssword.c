#include <weapon.h>
#include <ansi.h>

inherit SWORD;
void create()
{
set_name(HIG"�믫�C"NOR,({"spirit sword","sword","spirit"}) );
set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
set("long",HIG"�o�O�@�ⷥ�����M���C�A�����O�C�٤��p�����O�@��
��q�C�����o�O�@�⨾�ä��C�A���O�A�i�H�Pı�o���٦����K���æb�̭��C\n"NOR);
set("value",1);
init_sword(15);
                set("material", "energy");
set("wield_msg","$N�˳ƤW$n�A���M���O�q�q$N����W���o�X�ӡC\n");
set("unwield_msg", "$N�N��W��$n���_�C\n");
}
setup();
}
int query_autoload() { return 1; }
  
