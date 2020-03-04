#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"�m����n"HIB"�[�j���b"NOR, ({ "equip scroll" , "scroll"}) );
        set_weight(250);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",  
"�o���Ŧ⪺���b�W���g���F�K�K�³ª���r�A�o�Ǥ�r���G����\n"
"��o�ӪŶ��A�ݱo�A�O���Y�������A�ݨӥu�n�ݰݯ��F�E\n"+
HIC"(help scroll)\n"NOR);
                set("unit", "�i");
                set("value", 0);
        }
        setup();
}

void init()
{ 
        add_action("do_castwp", "castwp"); 
        add_action("do_casteq", "casteq"); 
}

int do_castwp(string arg)
{
        object me = this_player(), ob;
        int add  = 1+random(2); 
        if( !arg ) return notify_fail("castwp <���~id>\n");
        if( !objectp( ob = present( arg, me) ) ) 
                return notify_fail("�A���W�S�o�Ӫ��~�C\n");
        if( !ob->query("skill_type") )
                return notify_fail("�u��ϥΦb�Z���W���C\n");
        if( ob->query_temp("lv_up") )
                return notify_fail("�o�ӪZ���w�g����A�ɯŤF�C\n");
        if( ob->query("equipped") )
                return notify_fail("�Х��Ѱ��˳ơC\n"); 
         ob->set_temp("lv_up",1);
         ob->add("weapon_prop/bar", add); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�~��(BAR) "+add+" �I�F�E\n");
        destruct(this_object());
    return 1;
}
int do_casteq(string arg)
{
        object me = this_player(), ob;
        int add = 1+random(2); 
        if( !arg ) return notify_fail("casteq <���~id>\n");
        if( !objectp( ob = present( arg, me) ) ) 
                return notify_fail("�A���W�S�o�Ӫ��~�C\n");
        if( !ob->query("armor_type") )
                return notify_fail("�u��ϥΦb����W���C\n");
        if( ob->query_temp("lv_up") )
                return notify_fail("�o�Ө���w�g����A�ɯŤF�C\n");
        if( ob->query("equipped") )
                return notify_fail("�Х��Ѱ��˳ơC\n");
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/bar", add); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�~��(BAR) "+add+" �I�F�E\n");
    destruct(this_object());
        return 1;
}

