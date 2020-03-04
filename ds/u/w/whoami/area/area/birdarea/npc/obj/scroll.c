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
        int add  = 1+random(2); 
        int add1 = 1+random(30);
        int add2 = 1+random(10);
        int add3 = 1+random(5); 
        if( !arg ) return notify_fail("castwp <���~id>\n");
        if( !objectp( ob = present( arg, me) ) ) 
                return notify_fail("�A���W�S�o�Ӫ��~�C\n");
        if( !ob->query("skill_type") )
                return notify_fail("�u��ϥΦb�Z���W���C\n");
        if( ob->query_temp("lv_up") )
                return notify_fail("�o�ӪZ���w�g����A�ɯŤF�C\n");
        if( ob->query("equipped") )
                return notify_fail("�Х��Ѱ��˳ơC\n"); 
   switch( random(100) ) {
   case 0..1:
       switch(random(100)){
        case 1..10:
         ob->set_temp("lv_up",1);
         ob->add("weapon_prop/bar", add); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�~��(BAR) "+add+" �I�F�E\n");
         break;
        case 11..20: 
         ob->set("lv_up",1);
         ob->add("weapon_prop/wit", add); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�]�k(WIT) "+add+" �I�F�E\n");
         break;
        case 21..30: 
         ob->set_temp("lv_up",1);
         ob->add("weapon_prop/bio", add); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�ͪ�(BIO) "+add+" �I�F�E\n");
         break;
        case 31..40:
         ob->set_temp("lv_up",1);
         ob->add("weapon_prop/tec", add); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���(TEC) "+add+" �I�F�E\n");
         break;
        case 41..50:
         ob->set_temp("lv_up",1);
         ob->add("weapon_prop/sou", add); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���F(SOU) "+add+" �I�F�E\n");
         break; 
        case 51..70:
         ob->set_temp("lv_up",1);
         ob->add("weapon_prop/damage", add1); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���z�����O "+add1+" �I�F�E\n");
         break; 
        case 71..75: 
         ob->set_temp("lv_up",1);
         ob->add("weapon_prop/con", add3); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���(CON) "+add3+" �I�F�E\n");
         break;
        case 76..80:
         ob->set_temp("lv_up",1);
         ob->add("weapon_prop/str", add3); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�O�q(STR) "+add3+" �I�F�E\n");
         break; 
        case 81..85:
         ob->set_temp("lv_up",1);
         ob->add("weapon_prop/int", add3); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���z(INT) "+add3+" �I�F�E\n");
         break;
        case 86..90:
         ob->set_temp("lv_up",1);
         ob->add("weapon_prop/dex", add3); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�ӱ�(DEX) "+add3+" �I�F�E\n");
         break;
        default: 
         ob->set_temp("lv_up",1);
         ob->add("weapon_prop/hit", add3); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�����R���v "+add3+"% �F�E\n");
         break;
        }

        message_vision("$N���W��"+ob->query("name")+"�{�X"HIY"�����⪺���~"NOR"�A�b���~�h�h��A"+ob->query("name")+"���G�ܪ���j�F�C\n", me);
        destruct(this_object());
     break;
    default:
message_vision(
"$N���W��"+ob->query("name")+"�o�X�@�n���T�A��ӬO�I�G���~��"
+ob->query("name")+"���d�a�F�A$N�]�����F�o�Ӽo���E\n",me);
    destruct(ob);
    break;
    }return 1;
}

int do_casteq(string arg)
{
        object me = this_player(), ob;
        int add = 1+random(2); 
        int add1 = 1+random(30);
        int add2 = 1+random(10);
        int add3 = 1+random(5);
        if( !arg ) return notify_fail("casteq <���~id>\n");
        if( !objectp( ob = present( arg, me) ) ) 
                return notify_fail("�A���W�S�o�Ӫ��~�C\n");
        if( !ob->query("armor_type") )
                return notify_fail("�u��ϥΦb����W���C\n");
        if( ob->query_temp("lv_up") )
                return notify_fail("�o�Ө���w�g����A�ɯŤF�C\n");
        if( ob->query("equipped") )
                return notify_fail("�Х��Ѱ��˳ơC\n");
     switch( random(100) ) {
      case 0..1:
        switch(random(100)){
        case 1..5:
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/bar", add); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�~��(BAR) "+add+" �I�F�E\n");
         break;
        case 6..10: 
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/wit", add); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�]�k(WIT) "+add+" �I�F�E\n");
         break;
        case 11..15:    
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/bio", add); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�ͪ�(BIO) "+add+" �I�F�E\n");
         break;
        case 16..20: 
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/tec", add); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���(TEC) "+add+" �I�F�E\n");
         break;
        case 21..25: 
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/sou", add); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���F(SOU) "+add+" �I�F�E\n");
         break;
        case 26..35:  
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/armor", add1); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���z���m�O "+add1+" �I�F�E\n");
         break;
        case 36..45: 
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/shield", add1); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���F��ܤO "+add1+" �I�F�E\n");
         break;
        case 46..55: 
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/damage", add2); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���z�����O "+add2+" �I�F�E\n");
         break;
        case 56..65: 
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/con", add3); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���(CON) "+add3+" �I�F�E\n");
         break;
        case 66..75:
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/str", add3); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�O�q(STR) "+add3+" �I�F�E\n");
         break; 
        case 76..85:
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/int", add3); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F���z(INT) "+add3+" �I�F�E\n");
         break;
        case 86..95:
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/dex", add3); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�ӱ�(DEX) "+add3+" �I�F�E\n");
         break;
        default:
         ob->set_temp("lv_up",1);
         ob->add("armor_prop/dodge", add2); 
ob->add("long","�o"+ob->query("unit")+ob->query("name")+"�w�g�W�[�F�{���j�ײv "+add2+"% �F�E\n");
         break;
        }        message_vision("$N���W��"+ob->query("name")+"�{�X"HIY"�����⪺���~"NOR"�A�b���~�h�h��A"+ob->query("name")+"���G�ܪ���j�F�C\n", me);
        destruct(this_object());
     break;
    default:
message_vision(
"$N���W��"+ob->query("name")+"�o�X�@�n���T�A��ӬO�I�G���~��"
+ob->query("name")+"���d�a�F�A$N�]�����F�o�Ӽo���E\n",me);
    destruct(ob);
    break;
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


