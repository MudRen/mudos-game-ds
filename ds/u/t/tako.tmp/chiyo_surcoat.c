#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(MAG"�����@��" HIG"��"NOR ,({ "killgod-wind surcoat","surcoat" }) );
        set("long",
"�E�׷�ɭ�٬Ӯ�,�]�H�ۤv�Ѧa���L,�������n�q�L�T��, \n""�����N���L��F�@��ܭ�,�R�W�� �����@�� ���C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(850);
        set("material", "silk");
        set("unit", "��" );
        set("value",400);
set("volume",3);
        }
          set("armor_prop/armor", 5);
          set("armor_prop/int", 1);
          set("armor_prop/sword", -20);
          set("armor_prop/dex", 1); 
          set("armor_prop/str", -1);         setup();
}


