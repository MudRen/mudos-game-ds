#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("�]�C���@" , ({ "mist tough whip","whip" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long",@long
�o�O�@���ʾ]�p�W�~�����S�s���@�A���@�����Q�ƤV�A�ʭY���ҡA����
�O�٬O��H�A���O�n���R�o������@�l�A�ˤ]���O�e�����ơC
long
);
                set("material", "silver");
                set("value",4000);
        }
        set("weapon_prop/dex",2);
        set("limit_dex",20);
        init_whip(40);
        setup();
}


