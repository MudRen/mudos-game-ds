#include <ansi.h>
inherit ITEM;

void create()
{
        switch(random(2)){
        case 0:
        set_name(HIW"�m����n"HIB"�[�j���b"NOR, ({ "equip scroll" , "scroll"}) );
        set_temp("eq_scroll",1);
        break;
        default:        
        set_temp("wp_scroll",1);
        set_name(HIW"�m�Z���n"HIB"�[�j���b"NOR, ({ "weapon scroll", "scroll" }) );
        break;
        }
        set_weight(250);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "���۲��W�O�q�����b�C\n");
                set("unit", "�i");
                set("value", 0);
        }
        setup();
}

void init()
{ 
   if ( query_temp("wp_scroll")){
        add_action("do_castwp", "castwp"); 
   } else {
        add_action("do_casteq", "casteq"); 
      }
}

int do_castwp(string arg)
{
        object me = this_player(), ob;
        int bar,addbar = 1+random(2);
        if( !arg ) return notify_fail("castwp <���~id>\n");
        if( !objectp( ob = present( arg, me) ) ) 
                return notify_fail("�A���W�S�o�Ӫ��~�C\n");
        if( !ob->query("skill_type") )
                return notify_fail("�u��ϥΦb�Z���W���C\n");
        if( ob->query_temp("weapon_prop/bar"))
                return notify_fail("�o�ӪZ���w�g����A�ɯŤF�C\n");
        if( ob->query("equipped") )
                return notify_fail("�Х��Ѱ��˳ơC\n");
        ob->add_temp("weapon_prop/bar", addbar); 
        ob->init_weapon();
        ob->add("long","�o�ӪZ���w�g�W�[�FBAR"+addbar+"�I�F");
        message_vision("$N���W��"+ob->query("name")+"�{�X�����⪺���~�A�b���~�h�h��A"+ob->query("name")+"���G�ܪ���j�F�C\n", me);
        destruct(this_object());
        return 1;
} 
 
int do_casteq(string arg)
{
        object me = this_player(), ob;
        int bar,addbar = 1+random(2);
        if( !arg ) return notify_fail("casteq <���~id>\n");
        if( !objectp( ob = present( arg, me) ) ) 
                return notify_fail("�A���W�S�o�Ӫ��~�C\n");
        if( !ob->query("skill_type") )
                return notify_fail("�u��ϥΦb����W���C\n");
        if( ob->query_temp("armor_prop/bar"))
                return notify_fail("�o�Ө���w�g����A�ɯŤF�C\n");
        if( ob->query("equipped") )
                return notify_fail("�Х��Ѱ��˳ơC\n");
        ob->add_temp("armor_prop/bar", addbar); 
//      ob->init_weapon();
        ob->add("long","�o�Ө���w�g�W�[�FBAR"+addbar+"�I�F");
        message_vision("$N���W��"+ob->query("name")+"�{�X�����⪺���~�A�b���~�h�h��A"+ob->query("name")+"���G�ܪ���j�F�C\n", me);
        destruct(this_object());
        return 1;
}

