#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name("�M���٦X��", ({ "body_pill"}));
        set("long",
        "�o�O�@���u���b�M���ľQ�~�R�o�쪺���A�����M��q���C\n"
        );
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
	        set("unit", "��");
	        set("eat_msg","$N�Y�U�@���M���٦X���C");
	        set("eff_msg",HIG "�A��ı�o���ѧN�y�b����¶�ण���A���W���ˤf���G�]����¡�X�F�C" NOR );
	}
        set("value", 150);
        set("cure",([ "body" : 10,]));
        setup();
}
