#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
set_name(HIY"�v�����L�M"NOR,({"left blade","blade"}));
        set_weight(7550);   
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
�o�O�v��������a�ڥN�N�۶Ǫ��_�M�A�W���g�u�v�������ӭ��v
���G�O�o��M�̦����D�H�A�O�I�i�G�M�y���H�Ϊ��M�C
LONG);
                set("unit", "��");
                set("material","blade");
        }
  
set("value",4500);
set("limit_str",15);
set("limit_dex",20);
set("armor_prop/dex",2);
set("armor_prop/int",1);
set("wield_msg","$N�q�y�Ǩ��t�ޥX���$n�A���b��W�C\n");
set("unwield_msg", "$N�N$n���J�M�T�����A�o�Pı�v�����L�M�����O�q�b���ʡC\n");
init_blade(60,TWO_HANDED);
setup();
}

