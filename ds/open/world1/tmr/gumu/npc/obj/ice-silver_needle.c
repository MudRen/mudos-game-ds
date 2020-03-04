#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void init()
{
        add_action("do_bawan", "play");
}

void create()
{
        set_name(HIC"�B�z�Ȱw"NOR, ({ "ice-silver needle", "needle" })); 
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�N�O�Z�L���H�D�����ܪ��B�z�Ȱw�A�w���\\��᯾�A���y�o���O��ӡA�O�H�Ԥ���Q�⪱(play)�@�f�C\n");
                set("value", 3500);
                set("base_unit", "��");
                set("base_weight", 30);
                set("base_value", 0);
                set("meterial", "iron");
                set("wield_msg", "$N�p���l�l�a���X�@�ڦB�z�Ȱw��Z���C\n");
                set("unwield_msg", "$N��Ȱw��^���n���C\n");
        }
        set_amount(1);
        init_throwing(25);
        setup();
}

int do_bawan()
{
        tell_object(this_player(), "�A�ݵۤ⤤���Ȱwı�o����A��w�����᯾�ӲӺN�F�@�M�C\n");
        message_vision(HIB "$N��Mı�o��x�³ª����Ǥ����F�K�A�r�M��ı�G�u�w�W���r�A�p���⪱�A�Z���M�I�H�v�A\n"
                "���i�}��x�ߤU�Ȱw�A�u�����x�ߤw�`�¦p���A���u�¤�P�����W�ɡA�ߤ��j�b�A�Ԥ���K�n���X�n�ӡC\n" NOR, this_player() );
        this_player()->apply_condition("poison", 20);
        this_object()->unequip(); 
        destruct(this_object());
        return 1;
}


