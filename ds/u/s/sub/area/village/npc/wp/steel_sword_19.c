#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("���C",({"steel sword","sword"}) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long",@LONG
�o�O�@��ѿ��s�������C�A�ݰ_�Ӱ{�{�o�G�A�����Q�������U�Q�C
LONG);
        }
        init_sword(19);
        setup();
        set("value",2400);
        set("volume", 6);
        set("limit_skill",30);
}

