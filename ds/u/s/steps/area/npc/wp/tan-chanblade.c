#include <weapon.h>
#include <ansi.h>
inherit SSERVER;
inherit BLADE;
void create()
{
        set_name(WHT "�Ѩ��M" NOR,({"tan-chan blade","tan-chan","blade"}) );
        set("long",
        "�o�O�@�`���p�ȡA�Q�p�b�A��d�K�p�d���]�M�C�o\n"
        "�o�`�M�ǻ��O�a���Ѩе��Ѵݨ��Х����g�c����A\n"
        "�a���ѨбN�g�c�����S���q�۽m�s�Ӧ����C�ǻ���\n"
        "�a���ѨХΤF�ʦ~��ű�y���M�A�Q���١��ѤU�Ĥ@\n"
        "�M�C���٨S���H�M�o���M�U���A��Q�Z�L�H�h�y��\n"
        "�����M�̦������ǻD�C\n"
);
        set_weight(20000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","�`");
          set("value",100000);
                set("limit_str",45);
                set("limit_con",40);
                set("limit_int",30);
                set("limit_dex",30);
                set("limit_skill",80);
                set("wield_msg","$N�ˤW$n,$N�P�즳�@�Ѩ���B��$N������I");
                set("unwield_msg","$N��U�F$n,$N��������^�M���C");
        }
        set("weapon_prop/hit", 30);
        set("weapon_prop/dodge",-2);
        set("weapon_prop/bar",5);
        set("weapon_prop/bio",5);
        set("weapon_prop/tec",-4);
        init_blade(60);
        setup();
}
