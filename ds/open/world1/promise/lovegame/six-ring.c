#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
        set_name(HIM"���~�P"HIG"����"NOR ,({ "six-star ring","ring" }) );
      set("long", @LONG
�b�C�i���ɭԡA´�k�b�@�������C���A�ݨ�@��ѱC�C�����b�a�W�n��
�ܵh�W���ˤl�A´�k�N����ԥL�F�@��A�K�e�o�^��F�o����B�A��M
���ѱC�C�����j�ܦ������Q�Q�A�M��ݨ�´�k���u�ۤߡA�K�e������A
������§�C
LONG
);
           set_weight(400);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "�u" );
                set("value",10);
                set("armor_prop/armor", 1);

    }

        setup();
}

int query_autoload() { return 1; }


