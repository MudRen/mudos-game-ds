#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
        set_name(CYN"�M�ɤ��N"NOR,({"jade bracelet","bracelet"}) );
        set("long",@LONG
�o�O�@�ӬݨӫD�`��몺���N�A���b�⤤��Ĳ�P�o�a���I�x�N�C
LONG
);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",20);
                set("unit", "��");
                set("light",1);
                  set("value", 6000);
                set("volume", 4);
                set("material", "silk");
        }
        set("limit_con", 30);
        set("armor_prop/armor",5);  
        set("armor_prop/con", 2);
          set("armor_prop/dex", 1);
        setup();
}

