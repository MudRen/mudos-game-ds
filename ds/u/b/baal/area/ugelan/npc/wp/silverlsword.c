#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("�Ȼs���C", ({ "silver long sword", "sword" , "long" }) );
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@��Ȼs�����C�A�H�S��ޥ�ű���A�b�P�����t�ͪ��԰���
�঳�S���ĥΡA���~�A�ܦn��...\n");
                set("volume",3);
                set("value", 1400);
        set("material","silver");
                set("sword",41);
        }
        set("wield_msg", "$N�u�|�v�a�@�n��X�@��$n���b�⤤�C\n");
        set("unwield_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");
        init_sword(15);
        setup();
}

