#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
        set_name(HIM"���~�P"HIC"�@��"NOR ,({ "six-star leggings","leggings" }) );
      set("long", @LONG
�b�C�i���ɭԡA´�k�b�@�������C���A�ݨ�@��ѱC�C�����b�a�W�n��
�ܵh�W���ˤl�A´�k�N����ԥL�F�@��A�K�e�o�^��F�o����B�A��M
���ѱC�C�����j�ܦ������Q�Q�A�M��ݨ�´�k���u�ۤߡA�K�e������A
������§�C

LONG
);
           set_weight(800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "��" );
                set("value",1);
                set("valme",1);
               set("no_sac",1);
                              
                set("no_auc",1); 
                set("no_sell",1);                
                set("armor_prop/armor", 14);
                set("armor_prop/dex",1);
                set("armor_prop/str",1);    
    }

        setup();
}

int query_autoload() { return 1; }

