#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name("�ڤ��ĤY", ({ "fantasy pill","fantasy","pill"}));
        set("long",@LONG
�o�O�@���٨S�W�����T�ġA�����˪̪��ˤf���t�_��C
LONG);
        set_weight(2);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("eat_msg","$N�]�U�@���ڤ��ĤY�C");
                set("eff_msg","�A�P��������ˤf���t���_��F�C"  );
        }
        set("value",2000);
        set("cure",([
         "head" : 10,
         "body" : 10,
         "right_arm" : 10,
         "left_arm" : 10,
         "right_leg" : 10,
         "left_leg" : 10,
                ]));
        setup();
}
