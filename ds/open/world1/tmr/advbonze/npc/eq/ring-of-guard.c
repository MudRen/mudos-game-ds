#include <armor.h>
#include <ansi.h> 
inherit FINGER;

void create()
{
        set_name(HIY"�u�@��"NOR"����"NOR,({"ring of guard","ring"}) );
        set("long","�o�ӫ����Q���m���I�л\\�ۡA�W����{�X�����⪺�ӱK�u���C�u\n"
                   "���s���ۡB�������|�A�p�P���C\n");
        set_weight(500);
        if ( clonep() )
        set_default_object(__FILE__);
else
{
                set("volume",3);
                set("unit","�u");
                set("value",4500);
}
               set("armor_prop/armor",4);
               set("armor_prop/bio",1);
               set("armor_prop/wit",-1);
               setup();
}

