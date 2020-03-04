#include <ansi.h>
inherit ITEM;

void create()
{
        switch(random(16)){
        case 0..14:
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
   if ( query_temp("wp_scroll")){
        add_action("do_castwp", "castwp"); 
   } else {
        add_action("do_casteq", "casteq"); 
          } 
   add_action("do_help","help");
}

int do_castwp(string arg)
{
        object me = this_player(), ob;
        string name;
        int add  = 1+random(2),add1 = 1+random(5),add2 = 1+random(5),add3 = 1+random(2),x,y; 
        if( !arg ) return notify_fail("castwp <���~id>\n");
        if( !objectp( ob = present( arg, me) ) ) return notify_fail("�A���W�S�o�Ӫ��~�C\n");
        if( !ob->query("skill_type") ) return notify_fail("�u��ϥΦb�Z���W���C\n");
        if( ob->query_temp("lv_up") > 4 ) return notify_fail("�o�ӪZ���w�g����A�ɯŤF�C\n");
        if( ob->query("equipped") ) return notify_fail("�Х��Ѱ��˳ơC\n"); 
        name = ob->query("name");
        if( ob->query_temp("lv_up") == 1) name = replace_string( name, "��", HIC"��"NOR );
        else if( ob->query_temp("lv_up") == 2) name = replace_string( name, "��", HIY"��"NOR );
        else if( ob->query_temp("lv_up") == 3) name = replace_string( name, "��", HIG"��"NOR );
        else if( ob->query_temp("lv_up") == 4) name = replace_string( name, "��", HIR"��"NOR );
        
        if( ob->query_temp("lv_up") < 2)  x = 0;
        if( ob->query_temp("lv_up") == 2) x = 2;
        if( ob->query_temp("lv_up") == 3) x = 4;        
        if( ob->query_temp("lv_up") == 4) x = 8;
        if( x > 2) y = 106;
        else y = 100;
        
   if( random(x) < 1 ) {
        switch(random(y)){
        case 0..19:    ob->add("weapon_prop/damage", add1); 
                       ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���z�����O "+add1+" �I�F�E\n");break; 
        case 20..29:   ob->add("weapon_prop/con", add3); 
                       ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���(CON) "+add3+" �I�F�E\n"); break;
        case 30..39:   ob->add("weapon_prop/str", add3); 
                       ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�O�q(STR) "+add3+" �I�F�E\n"); break; 
        case 40..49:   ob->add("weapon_prop/int", add3); 
                       ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���z(INT) "+add3+" �I�F�E\n"); break;
        case 50..59:   ob->add("weapon_prop/dex", add3); 
                       ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�ӱ�(DEX) "+add3+" �I�F�E\n"); break;
        default:       ob->add("weapon_prop/hit", add3); 
                       ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�����R���v "+add3+"% �F�E\n"); break;
        case 101:      ob->add("weapon_prop/bar", 1); 
                       ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�~��(BAR) 1 �I�F�E\n");        break;
        case 102:      ob->add("weapon_prop/wit", 1); 
                       ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�]�k(WIT) 1 �I�F�E\n");        break;
        case 103:      ob->add("weapon_prop/tec", 1); 
                       ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���(TEC) 1 �I�F�E\n");        break;
        case 104:      ob->add("weapon_prop/sou", 1); 
                       ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���F(SOU) 1 �I�F�E\n");        break;
        case 105:      ob->add("weapon_prop/bio", 1); 
                       ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�ͪ�(BIO) 1 �I�F�E\n");        break;
        }
     message_vision("$N���W��"+ob->query("name")+"�{�X"HIY"�����⪺���~"NOR"�A�b���~�h�h��A"+ob->query("name")+"���G�ܪ���j�F�C\n", me);
     ob->add_temp("lv_up",1);
     if( ob->query_temp("lv_up") == 1 ) ob->set("name",HIC"��"NOR+name);
     else ob->set("name", name);
     destruct(this_object());
   } else {
     message_vision("$N���W��"+ob->query("name")+"�o�X�@�n���T�A��ӬO�I�G���~��"+ob->query("name")+"���d�a�F�A$N�]�����F�o�Ӽo���E\n",me);
     destruct(ob); destruct(this_object());
   }
   return 1;
}

int do_casteq(string arg)
{
        object me = this_player(), ob;
        string name;
        int add = 1+random(2), add1 = 1+random(5), add2 = 1+random(5), add3 = 1+random(2),x,y;
        if( !arg ) return notify_fail("casteq <���~id>\n");
        if( !objectp( ob = present( arg, me) ) ) return notify_fail("�A���W�S�o�Ӫ��~�C\n");
        if( !ob->query("armor_type") ) return notify_fail("�u��ϥΦb����W���C\n");
        if( ob->query_temp("lv_up") > 4 ) return notify_fail("�o�Ө���w�g����A�ɯŤF�C\n");
        if( ob->query("equipped") ) return notify_fail("�Х��Ѱ��˳ơC\n");
        name = ob->query("name");
        if( ob->query_temp("lv_up") == 1) name = replace_string( name, "��", HIW"��"NOR );
        else if( ob->query_temp("lv_up") == 2) name = replace_string( name, "��", HIC"��"NOR );
        else if( ob->query_temp("lv_up") == 3) name = replace_string( name, "��", HIY"��"NOR );
        else if( ob->query_temp("lv_up") == 4) name = replace_string( name, "��", HIB"��"NOR );
        
        if( ob->query_temp("lv_up") < 2)  x = 0;
        if( ob->query_temp("lv_up") == 2) x = 2;
        if( ob->query_temp("lv_up") == 3) x = 4;        
        if( ob->query_temp("lv_up") == 4) x = 8;
        if( x > 2 ) y = 106;
        else y = 100;
        
    if( random(x) < 1 ){            
        switch(random(y)){
        case 0..14: ob->add("armor_prop/armor", add1); 
                     ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���z���m�O "+add1+" �I�F�E\n");break;
        case 15..29: ob->add("armor_prop/shield", add1); 
                     ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���F��ܤO "+add1+" �I�F�E\n");break;
        case 30..44: ob->add("armor_prop/damage", add1); 
                     ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���z�����O "+add1+" �I�F�E\n");break;
        case 45..54: ob->add("armor_prop/con", add3); 
                     ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���(CON) "+add3+" �I�F�E\n"); break;
        case 55..64: ob->add("armor_prop/str", add3); 
                     ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�O�q(STR) "+add3+" �I�F�E\n"); break; 
        case 65..74: ob->add("armor_prop/int", add3); 
                     ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���z(INT) "+add3+" �I�F�E\n"); break;
        case 75..84: ob->add("armor_prop/dex", add3); 
                     ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�ӱ�(DEX) "+add3+" �I�F�E\n"); break;
        default:     ob->add("armor_prop/dodge", add2); 
                     ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�{���j�ײv "+add2+"% �F�E\n"); break;
        case 101:      ob->add("weapon_prop/bar", 1); 
                       ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�~��(BAR) 1 �I�F�E\n");        break;
        case 102:      ob->add("weapon_prop/wit", 1); 
                       ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�]�k(WIT) 1 �I�F�E\n");        break;
        case 103:      ob->add("weapon_prop/tec", 1); 
                       ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���(TEC) 1 �I�F�E\n");        break;
        case 104:      ob->add("weapon_prop/sou", 1); 
                       ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���F(SOU) 1 �I�F�E\n");        break;
        case 105:      ob->add("weapon_prop/bio", 1); 
                       ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�ͪ�(BIO) 1 �I�F�E\n");        break;
        }
        message_vision("$N���W��"+ob->query("name")+"�{�X"HIY"�����⪺���~"NOR"�A�b���~�h�h��A"+ob->query("name")+"���G�ܪ���j�F�C\n", me);
        ob->add_temp("lv_up",1);
        if( ob->query_temp("lv_up") == 1 ) ob->set("name",HIW"��"NOR+name);
        else ob->set("name", name);
        destruct(this_object());
    } else {
    message_vision("$N���W��"+ob->query("name")+"�o�X�@�n���T�A��ӬO�I�G���~��"+ob->query("name")+"���d�a�F�A$N�]�����F�o�Ӽo���E\n",me);
    destruct(ob); destruct(this_object()); 
    }
        return 1;
}

int do_help(string str)
{
  if(!str || str != "scroll") return 0; 
  if ( query_temp("wp_scroll")){
  write(HIG"\n\t���Ϊk: castwp <id>\n"NOR);
  } else {
  write(HIG"\n\t���Ϊk: casteq <id>\n"NOR);
  }
  return 1;
}
