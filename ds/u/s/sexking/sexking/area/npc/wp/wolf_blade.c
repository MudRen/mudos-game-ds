#include <weapon.h>
inherit BLADE;

void create()
{
set_name("�ѯT���b",({"wolf tooth blade","blade"}));
        set_weight(8850);   
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
�۶Ƿ�~�ѻ��G�T�Y�h�i���ѯT�s�A�N�ѯT�����A�ް_�e���������y
�F�@��M�A���N�O�u�ѯT���b�v�C
LONG);
                set("unit", "��");
                set("material","blade");
        }
init_blade(55,TWO_HANDED);
set("value",5500);
set("limit_str",20);
set("limit_con",20);
set("armor_prop/str",2);
set("armor_prop/con",1);
set("wield_msg","$N�q�I�ᨳ�t�ޥX�@��Ѥ��T�b�A�u���Ѥ��T�b�_�X�H�H���ť��C\n");
set("unwield_msg", "$N�N�ѯT���b���^�I��M�T�����A�Pı�I�ᦳ�ѦB�B�D�D���H��C\n");
setup();
}
