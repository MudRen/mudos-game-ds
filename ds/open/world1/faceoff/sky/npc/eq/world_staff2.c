#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
        set_name( "�إ@��" ,({"whisk-world staff","staff"}));
        set_weight( 6000 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
�o�O�����t�D�ҨϥΪ��t�M�A�Ψӱ����H�@�����Ѩ��U�c�C
�����t�D�b���Q�������~�o�D�A�ӳХX�u�E���ѩG�v, �q���԰�
���A�ϥΦ��M�A�ӱN�������ػP�L�H�C
LONG
                                );
                set("volume",2);
                set("unit", "��");
                set("value",7000);
                set("material","steel");
                set("limit_lv", 25);
        }
        init_staff(71);
        set("weapon_prop/str",1);
        set("weapon_prop/dex",1);
        setup();
}

