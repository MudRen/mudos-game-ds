#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name("�ѯT�ԳT" ,({ "wolf surcoat","surcoat" }) );
        set("long","�۶Ƿ�~�ѻ��G�T�Y�h�i���ѯT�s�A�N�ѯT�����A�å��e����
                 ��U�����F�o��ԳT�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_con",25);
        set("limit_int",10);
        set_weight(9020);
        set("unit", "��" );
       set("value",4500);
        set("armor_prop/armor", 12);
        set("volume",7);
    set("armor_prop/con",1);
        }
        setup();
}

