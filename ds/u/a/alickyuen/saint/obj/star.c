
#include <armor.h> 
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIY"�P�Φ���"NOR, ({ "star-shaped earring","earring" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@��P�P�Ϊ��������A\n"
                           "�A�i�H�յ۰t�a�ݬݡC\n");
                set("unit", "��");
  set_temp("has_light",1);  
                set("material", "jade");
set("value",1000);
		set("wear_msg",HIY"$N���W�F�o������A ��Mı�o�@�������C"NOR);
        }
        setup();
}
