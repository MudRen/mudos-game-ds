#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIY"�ӫa�M�h���C"+NOR ,({ "crown knight sword","sword" }) );
        set("long","�@����������M�h�ҥΪ�����C�A�W����"HIC"�ӫa"NOR"��L�C\n");
        set_weight(9000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material","steel");
        }
        set("unit", "��" );
        set("limit_str",12);
        set("value",1500);
        set("volume",2);
        init_sword(35); //sword �����O
        set("wield_msg","�u��v���@�n�A$N���t�L�񪺩�X�⤤$n�A�C�b�p�P�@�l�����{�{�ۥ��~�C\n"NOR);
        set("unwield_msg","�u���v�@�n�T�A$N�N�⤤��$n���^�C�T�C\n"NOR);

        setup();
}

